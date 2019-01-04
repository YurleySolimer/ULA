#include <iostream>
#include <tpl_tree_node.H>    //aca se encuentra definida la clase TreeNode
#include <string>
#include <ctype.h>
# include <ahSort.H>
# include <htlist.H>

using namespace std;
using namespace Aleph;




//  Esta funcion recibe una referencia hacia un puntero a un nodo (root), 
// la palabra (str)que se esta agregando y la posicion actual de una de 
// las letras de str, la cual se esta agregando
void insert(Tree_Node<char> *& root, string & str, int pos);

//  Esta funcion se le aplicara a cada nodo del arbol para mostrarlo por pantalla
void func(Tree_Node<char> * root, int, int)
{
  cout << root->get_key() << ' ';
}

//  NOTA: Recuerda que al probar este programa todas las palabras que insertes deben
// comenzar por la misma letra, para que tenga sentido
int main()
{


  Tree_Node<char> * tree = NULL;
  
  string str;

  while(cin >> str) //permitimos que la persona ingrese palabras, hasta que presione Ctrl+D
  {
		insert(tree, str, 0);   //y luego insertamos esa palabra en el arbol cuya raiz es tree 
  }

  tree_preorder_traversal(tree, func);

}


void insert(Tree_Node<char> *& root, string & str, int pos)
{
  if(!root)   //root es NULL, entonces apenas estamos insertando la primera palabra
  {           // y pos == 0, es decir que estamos comenzando a trabajar en dicha palabra
    root = new Tree_Node<char>(str[pos]);
    auto p = root;
    for(int i = pos + 1; i < str.size(); i++) //  y de una vez agregar todas las letras restantes al arbol ya que es la primera palabra
    {
      p->insert_rightmost_child(new Tree_Node<char>(str[i])); // para eso, se creo un puntero auxiliar p que apuntara a un nodo
      p = p->get_right_child();                               // al cual se le inserta como hijo un nuevo nodo una de las letras de str
    }   //  OJO: nota que i nos ayudara a iterar sobre las letras de la palabra, comenzando desde la segunda 
        // ya que la primera se inserto en la raiz anteriormente
    return;
  }
  
  if(str[pos] != root->get_key()) //  Si la letra sobre la cual estamos trabajando no coincide con la letra del nodo root
    return;                       // retornar..
  
  bool inserted = false;    //ahora verificaremos si existe un hijo del nodo root que ya tenga la letra str[pos]
  root->for_each_child([&pos, &str, &inserted] (Tree_Node<char>* c)   //  Sea c un hijo de root
      {
        if(str[pos+1] == c->get_key())  //Si es asi, entonces no necesitamos crear una nueva rama (o hijo)
        {
          insert(c, str, pos+1);  //  y lo que haremos es llamar recursivamente a insert pero con la letra siguiente y root = c
          inserted = true;  //ahora que sabemos que ya la letra actual existia como hija de root, marcamos inserted
        }
      });

  if(inserted)  //  Si ya la letra str[pos] habia sido insertada, retornamos
    return;
  // pero si no..
  auto p = root;  //insertamos todas las letras restantes en una nueva rama (como cuando se agrega la primera palabra al arbol)
  for(int i = pos + 1; i < str.size(); i++)
  {
    p->insert_rightmost_child(new Tree_Node<char>(str[i]));
    p = p->get_right_child();
  }

}
