#include <iostream>
#include <htlist.H>
#include <tuple>


using namespace std;
using namespace Aleph;


int main()
{
	cout<<"Hola!"<<endl;
	DynList<tuple<int, char> > lista;

	int aux = 1;
	char c;

	while(aux >= 1)
	{
		cin >> aux;
		if(aux >= 1)
		{			
			cin >> c;
			lista.append(make_tuple(aux, c));
		}		
	}

  cout<<"---------------------While------------------------------"<<endl;
  DynList<tuple<int, char> >::Iterator it(lista);
  while(it.has_curr())
  {
    auto t = it.get_curr();
    for(int i = 0; i < get<0>(t); i++)
      cout << get<1>(t);

    cout << '\n';
    it.next();
  }
  cout<<"----------------------For-----------------------------"<<endl;

  for(DynList<tuple<int, char> >::Iterator it(lista); it.has_curr(); it.next())
  {
    auto t = it.get_curr();
    for(int i = 0; i < get<0>(t); i++)
      cout << get<1>(t);

    cout << '\n';
  }
  cout<<"---------------------------------------------------"<<endl;
	
  //Ejemplo
  /*
  cout << " Range Based for" <<endl;
  for (auto & i : lista)
  {
     cout << get<1>(i) << endl;

  } 
  */ 






	return 0;
}
