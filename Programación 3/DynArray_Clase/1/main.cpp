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

  //¿Cual es la dimension actual del arreglo? (Para mostrar que el append agrega al FINAL del arreglo, y actualiza la dimension del arreglo en 1)
  cout << "Dimension: " << arreglo.size() << endl;  //la dimension debe ser 20

  //Observo todo el arreglo
  //Las 10 primeras entradas deben tener un valor predeterminado (0) porque no se ha escrito sobre ellas
  arreglo.for_each([](int x)
    {
      static int i = 0;
      cout << "arreglo(" << i << ") = " << x << endl;
      i++;
    });


  //Observo que aunque la dimension es 20, hay mas elementos que ya tienen memoria apartada, hasta cierto punto.
  //(para mostrar el funcionamiento de exist())
  for(int i = 0; arreglo.exist(i); i++)
    cout << "Indice " << i << " : " << arreglo(i) << endl;



  //trato de acceder a un elemento que no tiene memoria reservada. Es lo mismo que usar el operador ()
  //cout << arreglo.access(i) << endl; 
  //SE OBTIENE UN ASSERT (Aborta el programa). Descomentar para probar

  //Resumo el uso de exist() y () con test()
  int * e, i = 0;
  do
  {
    e = arreglo.test(i);
    if(e != NULL and *e != 0 )
      cout << "Indice " << i << " : " << *e << endl;
    else if(e == NULL)
      cout << "Indice " << i << " : NO TIENE MEMORIA APARTADA" << endl;

    i++;
  } while(e != NULL);

  //Cual es la dimension ahora? (Para mostrar que si se usa access o () en un indice mayor que la dimension, pero que tiene memoria apartada, la dimension se actualiza a ese indice)
  cout << "Dimension: " << arreglo.size() << endl;

  //Vacio el arreglo
  arreglo.empty();
  cout << "Dimension: " << arreglo.size() << endl;

  //touch en cualquier indice
  arreglo.touch(10000);
  //Prueba de que no solo se aparta memoria para un elemento, sino para todos los elementos aledaños (bloque)
  //Hasta que indice hay memoria?
  do
  {
    e = arreglo.test(i);
    if(e != NULL and *e != 0 )
      cout << "Indice " << i << " : " << *e << endl;
    else if(e == NULL)
      cout << "Indice " << i << " : NO TIENE MEMORIA APARTADA" << endl;

    i++;
  } while(e != NULL);

  //Aunque en el while anterior se nota que no hay memoria apartada en un indice mucho menor a 10000, en el indice 10000 y sus alrededores si hay memoria apartada
  e = arreglo.test(10000);
  if(e != NULL)
    cout << "En la posicion 10000 hay memoria apartada\n";

  //La dimension del arreglo ahora es 101 porque se toco el inidice 100, que es mayor a la dimension de ese momento (0)
  cout << "Dimension: " << arreglo.size() << endl;

  //Disminuir la dimension del arreglo
  arreglo.cut(10);
  //nueva dim
  cout << "Dimension: " << arreglo.size() << endl;
  //Hasta que indice hay memoria?
  do
  {
    e = arreglo.test(i);
    if(e != NULL and *e != 0 )
      cout << "Indice " << i << " : " << *e << endl;
    else if(e == NULL)
      cout << "Indice " << i << " : NO TIENE MEMORIA APARTADA" << endl;

    i++;
  } while(e != NULL);

  //Sigue habiendo memoria hasta un indice grande, pero en el 10000, por ejemplo, ya no hay
  //Todo esto y lo anterior para mostrar que la memoria apartada es proporcional a la escritura en el arreglo, y no directamente a su dimension.
  e = arreglo.test(10000);
  if(e != NULL)
    cout << "En la posicion 10000 hay memoria apartada\n";



	return 0;
}
