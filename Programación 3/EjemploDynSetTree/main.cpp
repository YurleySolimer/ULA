#include <iostream>
#include <tpl_dynSetTree.H>

using namespace std;

//Calcula la media de los elementos del arbol tree
float getMedia(const DynSetTree<int,Rand_Tree> &tree);

//Calcula la varianza de los elementos del arbol tree
float getVari(const DynSetTree<int,Rand_Tree> &tree);

//Estructura con operador () sobrecargado
//El operador () debe ser sobrecargado con la operacion que se quiere aplicar sobre cada clave
//del arbol en un for_each
struct ver_clave
{
  //Se sobrecarga el oeprador para que imprima la clave
  void operator () (const int & key)
  {
  	cout << key << " ";
  }
}Ver;


int main()
{
  //Instanciamos un arbol de enteros, de tipo aletorio. Es un arbol con rangos
  DynSetTree<int,Rand_Tree> tree;

  int x;
  //leemos algunos valores y los insertamos al arbol, hasta encontrar -1
  cin>>x;
  while(x!=-1)
  {
    tree.insert(x);
    cin>>x;
  }

  tree.for_each_inorder(Ver);
  cout<<endl;
  
  //Vamos a calcular la media y la varianza de los elementos del arbol tree
  //que esten entre dos claves dadas por el usuario
  int k1, k2;
  cout << "Ingrese las dos claves: ";
  cin >> k1 >> k2;
  cout<<endl;

  DynSetTree<int,Rand_Tree> TL, TR;
  //Con un split_key_dup con la clave k1 obtengo en TR los elementos mayores o iguales a k1
  tree.split_key_dup(k1, TL, TR); //tree queda vacio
  tree.swap(TR); //ahora en tree tengo los elementos que me interesan, TR queda vacio
  TL.empty(); //No me importan los elementos menores que k1 y necesito a TL vacio para usar de nuevo el split
  //Observo como esta el arbol hasta ahora
  tree.for_each_inorder(Ver);
  cout<<endl;

  //Con un split sobre el elemento que se encuentre despues de k2 tengo en TL los elementos que esten entre k1 y k2.
  //No hago el split sobre k2 porque estaria eliminando a k2
  int pos = tree.position(k2);
  //Primero, si la posicion es la ultima en el arbol, entonces tree ya esta listo para buscar media y varianza
  if(pos + 1 != tree.size())
  {
    int k2 = tree.select(pos + 1);
    tree.split_key_dup(k2, TL, TR);
    tree.swap(TL);
  }

  tree.for_each_inorder(Ver);
  cout<<endl;
  cout<<"Media: "<<getMedia(tree)<<endl;
  cout<<"Varianza: "<<getVari(tree)<<endl;


	return 0;
}


float getMedia(const DynSetTree<int,Rand_Tree> &tree)
{
  float x=0;
  for(DynSetTree<int, Rand_Tree>::Iterator it(tree); it.has_curr();it.next())
    x+= it.get_curr();
  
  x/= tree.size();
  return x;
}

float getVari(const DynSetTree<int,Rand_Tree> &tree)
{
  float media= getMedia(tree);
  float var=0;
  for(DynSetTree<int, Rand_Tree>::Iterator it(tree); it.has_curr();it.next())
    var += (it.get_curr() - media) * (it.get_curr() - media);

  return var/tree.size();


}












