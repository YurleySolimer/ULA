#include <iostream>
#include <tpl_dynArray.H>

using namespace std;
using namespace Aleph;

int main()
{
	int aux;
	DynArray<int> arreglo(10); //OJO, dimension inicial 10

	cout<<"Comienze a ingresar los valores del arreglo.."<<endl;

					         //se leen y agregan enteros al arreglo 	
	while(cin>>aux)	//hasta que el usuario presione Ctrl + D (o se termine el archivo)				
		arreglo.append(aux);

  //¿Cual es la dimension actual del arreglo? (Para mostrar que el append no agrega en la primera posicion, sino que actualiza la dimension del arreglo en 1)
  cout << "Dimension: " << arreglo.size() << endl;  //la dimension debe ser 20

  //Observo todo el arreglo
  //Las 10 primeras entradas deben tener un valor predeterminado (0) porque no se ha escrito sobre ellas
  arreglo.for_each([](int x)
    {
      static int i = 0;
      cout << "arreglo(" << i << ") = " << x << endl;
      i++;
    });


  //Lectura fuera de la dimension pero sobre un bloque sin memoria apartada
  int i;
  //busco una entrada invalida del arreglo
  for(i = 0; arreglo.exist(i); i++)
  {}

  try
  {
    arreglo[i] + 1;
  }
  catch(std::invalid_argument & e)
  {
    cerr << e.what() << endl;
  }

  //Lectura fuera de la dimension pero con memoria asignada memoria apartada
  //NO genera excepcion
  try
  {
    arreglo[i - 1] + 1;
  }
  catch(std::exception & e)
  {
    cerr << e.what() << endl;
  }

  //Escritura sobre una posicion sin memoria apartada
  //Aparta la memoria como lo haria touch
  try
  {
    arreglo[i] = 123;
  }
  catch(std::exception & e)
  {
    cerr << e.what() << endl;
  }
  //Si hago lectura sobre la pos i, ya no tendremos excepcion
  try
  {
    cout << "Arreglo[" << i << "] = " << arreglo[i] << endl;
  }
  catch(std::invalid_argument & e)
  {
    cerr << e.what() << endl;
  }


  //trato de asignar a una entrada valida del arreglo, el valor de una entrada invalida del arreglo
  int pos_valida = i;
  //primero busco alguna entrada invalida del arreglo
  for(i = 0; arreglo.exist(i); i++)
  {}

  try
  {
    arreglo[pos_valida] = arreglo[i];
  }
  catch(std::exception & e)
  {
    cerr << e.what() << endl;
  }

  //Escribo sobre una entrada invalida, una entrada valida del arreglo
  try
  {
    arreglo[i] = arreglo[pos_valida];
  }
  catch(std::exception & e)
  {
    cerr << e.what() << endl;
  }


  cout << "MAX_DIM: " << arreglo.max_size() << endl;



	return 0;
}