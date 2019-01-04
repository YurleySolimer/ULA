/*
  Aca estan los metodos que no se terminaron en clase.
  Si los ven bien, terminan siendo muy sencillos y no es necesario el split.
  Si quieren practicar mas la recursividad, pueden hacer una funcion que diga si dos ABB son identicos
  Otra cosa que pueden hacer es resolver estos mismos problemas, pero en forma iterativa, dentro de lo que se pueda  
*/

#include <iostream>
#include <tpl_binTree.H>

using namespace std;
using namespace Aleph;

typedef BinTree<int>::Node ABB;


//Al usar tanto minimo como maximo, se debe garantizar que el nodo raiz no sea nulo (que el arbol no este vacio)
//Esto para ahorrarnos la validacion !node que solo es necesaria en la primera pasada, pero que al ser recursivo
//se hace en todas las llamadas, lo cual es contraproducente
ABB* minimo(ABB * node)
{
  if(!LLINK(node))
    return node;

  return minimo(LLINK(node));
}


ABB* maximo(ABB * node)
{
  if(!RLINK(node))
    return node;

  return maximo(RLINK(node));
}


//Calcula la suma de todos los elementos de un ABB
int tree_addition(ABB * node)
{
  if(!node)
    return 0;

  //Sumo la clave actual, mas la suma de toda la rama izquierda y toda la rama derecha. 
  return KEY(node) + tree_addition(LLINK(node)) + tree_addition(RLINK(node));
}


//Calcula la suma de los elementos del arbol que son > key
int sum_greater(ABB * node, int key)
{
  if(!node)
    return 0;

  if(key < KEY(node)) //La clave esta en la rama izquierda
                      //entonces tanto el nodo actual como la rama derecha, tienen elementos > key
                      //Por eso sumo la clave del nodo actual, mas la suma de todo el arbol que inicia en RLINK(node) (rama derecha)
                      //Y sigo sumando los > key que esten en la rama izquierda
    return KEY(node) + tree_addition(RLINK(node)) + sum_greater(LLINK(node), key);
  else if(key > KEY(node))  //La clave esta en la rama derecha
                            //Entonces los elementos de la rama izq y el del nodo actual son < key
                            //Asi que me olvido de ellos y sumo los > key que esten en la rama derecha
    return sum_greater(RLINK(node), key);

  //La clave del nodo actual es igual a key
  //Las claves de la rama izq son < key, asi que me olvido de ellos, y sumo todos los del arbol que inicia en RLINK(node) (rama derecha)
  //pues todos esos son > key
  return tree_addition(RLINK(node));
}


//Calcula la suma de todos los elementos del arbol < key.
//La explicacion es analoga a la de sum_greater
int sum_lesser(ABB * node, int key)
{
  if(!node)
    return 0;

  if(key < KEY(node))
    return sum_lesser(LLINK(node), key);
  else if(key > KEY(node))
    return KEY(node) + tree_addition(LLINK(node)) + sum_lesser(RLINK(node), key);
    

  return tree_addition(LLINK(node));
}

int main()
{
  BinTree<int> btree;

  int key;
  while(cin >> key)
    btree.insert(new ABB(key));

  cout << "Minimo: " << KEY(minimo(btree.getRoot())) << endl;
  cout << "Maximo: " << KEY(maximo(btree.getRoot())) << endl;
  cout << "Suma de todos los elementos: " << tree_addition(btree.getRoot()) << endl;
  cout << "Suma de menores que 25: " << sum_lesser(btree.getRoot(), 25) << endl;
  cout << "Suma de mayores que 25: " << sum_greater(btree.getRoot(), 25) << endl;
  cout << "Suma de menores que 2: " << sum_lesser(btree.getRoot(), 2) << endl;
  cout << "Suma de mayores que 2: " << sum_greater(btree.getRoot(), 2) << endl;

	return 0;
}
