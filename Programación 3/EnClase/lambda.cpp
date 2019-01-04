#include <iostream>
#include <htlist.H>
#include <tuple>


using namespace std;
using namespace Aleph;


int main()
{
  int n;
  cin >> n;
  
	DynList<int> lista;
 
  int i = 1;
  while(i != 0)
  {
    cin >> i;
    lista.append(i); 
  }

  lista.for_each([&n] (int a)
                 {
                    if(a > n)
                      cout << a << " es mayor que " << n << endl;
                    else if(a < n)
                      cout << a << " es menor que " << n << endl;
                  });

  

	return 0;
}
