
# include <ahSort.H>
# include <htlist.H>

using namespace std;
using namespace Aleph;

typedef DynList<DynList<int>> Sudoku;

// Una celda del sudoku se define por una tupla row,col
typedef tuple<int, int> Cell;

typedef DynList<Cell> Cells;

inline void print_sudoko(const Sudoku & sudoku)
{
  cout << "-------------------------" << endl;
  int i = 0;
  sudoku.for_each([&i] (const DynList<int> & line)
		  {
		    int j = 0;
		    cout << "| ";
		    line.for_each([&j] (int val)
				  {
				    cout << val << " ";
				    if (++j % 3 == 0)
				      cout << "| ";
				  });
		    cout << endl;
		    if (++i % 3 == 0)
		      cout << "-------------------------" << endl;
		  }); 
}

inline string sudoku_array(const Sudoku & sudoku)
{
  int i = 0;
  string ret("{");
  sudoku.for_each([&i,&ret] (const DynList<int> & line)
		  {
		    int j = 0;
		    ret += "{";
		    line.for_each([&j,&ret] (int val)
				  {
				    ret += to_str(val);
				    if (++j < 9)
				      ret += ",";
				  });
		    ret += "}";
		    if (++i < 9)
		      ret += ",";
		    else
		      ret += "}";
		    ret += "\n";
		  }); 
  return ret + "\n";
}

inline void print(const DynList<int> & l)
{
  l.for_each([] (int i) { cout << i << " "; });
  cout << endl;
}

