#include <iostream>
#include <fstream>
#include <tpl_dynBinHeap.H>
#include <tpl_binHeap.H>
#include <map>

using namespace std;

class Operation
{
  char operation;
  int a;
  int b;
  float result;

  unsigned int priority;

  public:

    Operation() {}

    Operation(char operation, int a, int b, unsigned int priority) 
    {
      this->operation = operation;
      this->a = a;
      this->b = b;
      this->priority = priority;

      switch (operation)
      {
        case '+':
          result = a + b;
          break;

        case '-':
          result = a - b;
          break;

        case '*':
          result = a * b;
          break;

        case '/':
          if (b == 0)
            throw domain_error("Division entre 0!");

          result = a / (float)b;
          break;

        case '%':
          if (b == 0)
            throw domain_error("Division entre 0!");

          result = a % b;
          break;
      }
    }

    char getOperation() const
    {
      return operation;
    }

    int getA() const
    {
      return a;
    }

    int getB() const
    {
      return b;
    }

    float getResult() const
    {
      return result;
    }

    unsigned int getPriority() const
    {
      return priority;
    }

};

struct OpCmp
{
  map<char, int> opPriorities;

  OpCmp()
  {
    opPriorities['+'] = 5;
    opPriorities['-'] = 4;
    opPriorities['*'] = 3;
    opPriorities['/'] = 2;
    opPriorities['%'] = 1;
  }

  bool operator () (const Operation & op1, const Operation & op2)
  {
    if (op1.getPriority() > op2.getPriority())
    {
      return true;
    }
    else if (op1.getPriority() < op2.getPriority())
    {
      return false;
    }
    else if (opPriorities[op1.getOperation()] > opPriorities[op2.getOperation()])
    {
      return true;
    }

    return false;
  }
};

int main()
{
  ifstream in("./operaciones.txt");

  if (in.fail())
  {
    cerr << "Error al abrir archivo\n";
    return 1;
  }

  char op;
  int a, b;
  unsigned int priority;
  DynBinHeap<Operation, OpCmp> operations;

  while (not in.eof())
  {
    in >> op;

    if (not in.good())
      break;

    in >> a;
    in >> b;
    in >> priority;

    Operation operation(op, a, b, priority);

    operations.insert(operation);
  }

  while (not operations.is_empty())
  {
    Operation operation = operations.get();
    cout << operation.getA() << " "
         << operation.getOperation() << " "
         << operation.getB() << " = "
         << operation.getResult()
         << "\t(Priority: " << operation.getPriority() << ")\n";
  }

  return 0;
}
