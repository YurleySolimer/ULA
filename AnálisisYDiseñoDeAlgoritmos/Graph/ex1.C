# include <iostream>

# include <tpl_graph.H>

using namespace std;

using Node = Graph_Node<char>;
using Arc  = Graph_Arc<Empty_Class>;
using GT   = List_Graph<Node, Arc>;

void print_graph(GT & g)
{
  cout << g.get_num_nodes() << " nodes\n";
  
  for (GT::Node_Iterator it(g); it.has_curr(); it.next())
    {
      auto p = it.get_curr();
      
      cout <<
	"Node " << p->get_info() << ", "
	   << g.get_num_arcs(p) << " adjacent arcs: ";
      
      for (GT::Node_Arc_Iterator ait(p); ait.has_curr(); ait.next())
	{
	  auto q = ait.get_tgt_node();
	  cout << q->get_info() << ' ';
	}

      cout << endl;
    }

  cout << endl << endl;
  cout << g.get_num_arcs() << " arcs\n";

  for (GT::Arc_Iterator it(g); it.has_curr(); it.next())
    {
      auto a = it.get_curr();

      auto p = g.get_src_node(a);
      auto q = g.get_tgt_node(a);

      cout << p->get_info() << " -- " << q->get_info() << endl;
    }
}

int main()
{
  GT g;

  GT::Node * s = g.insert_node('s');
  auto a = g.insert_node('a');
  auto b = g.insert_node('b');
  auto c = g.insert_node('c');
  auto d = g.insert_node('d');
  auto e = g.insert_node('e');

  g.insert_arc(s, a);
  g.insert_arc(s, b);
  g.insert_arc(a, c);
  g.insert_arc(a, b);
  g.insert_arc(c, e);
  g.insert_arc(c, d);
  g.insert_arc(b, d);
  g.insert_arc(d, e);

  print_graph(g);
  
  return 0;
}
