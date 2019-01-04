#include <iostream>
#include <tpl_tree_node.H>
#include <tpl_binNodeUtils.H>

using namespace std;
using namespace Aleph;

void show_bin_node(BinNode<char> * node, int, int)
{
  cout << KEY(node) << ' ';
}

void show_tree_node(Tree_Node<char> * node, int, int)
{
  cout << node->get_key() << ' ';
}

int main()
{
  Tree_Node<char> * a1 = new Tree_Node<char>('A');
  a1->insert_rightmost_child(new Tree_Node<char>('B'));
  a1->insert_rightmost_child(new Tree_Node<char>('C'));
  auto aux = a1->get_right_child();
  aux->insert_rightmost_child(new Tree_Node<char>('D'));
  aux->insert_rightmost_child(new Tree_Node<char>('E'));
  aux->insert_rightmost_child(new Tree_Node<char>('F'));

  Tree_Node<char> * a2 = new Tree_Node<char>('G');
  a2->insert_rightmost_child(new Tree_Node<char>('H'));
  a2->insert_rightmost_child(new Tree_Node<char>('I'));
  a2->get_right_child()->insert_rightmost_child(new Tree_Node<char>('J'));

  Tree_Node<char> * a3 = new Tree_Node<char>('K');
  a3->insert_rightmost_child(new Tree_Node<char>('L'));
  aux = a3->get_right_child();
  aux->insert_rightmost_child(new Tree_Node<char>('M'));
  aux->insert_rightmost_child(new Tree_Node<char>('N'));

  a1->insert_tree_to_right(a2);
  a1->insert_tree_to_right(a3);

  BinNode<char> * bin_tree = forest_to_bin<Tree_Node<char>, BinNode<char> >(a1);

  preOrderRec(bin_tree, show_bin_node);
  cout << endl;
  forest_preorder_traversal(a1, show_tree_node);
  cout << endl;


	return 0;
}
