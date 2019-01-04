# include <iostream>
# include <tpl_graph.H>
# include <generate_graph.H>

using namespace std;

using Node = Graph_Node<char>;
using Arc  = Graph_Arc<Empty_Class>;
using GT   = List_Graph<Node, Arc>;

struct Wnode
{
  string operator () (GT::Node * p)
  {
    stringstream s;
    s << p->get_info();
    return s.str();
  }
};

struct Warc
{
  string operator () (GT::Arc *)
  {
    return "";
  }
};

int main()
{
  GT g;

  auto s = g.insert_node('s');
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

  ofstream output("graph-ex2.dot");

  if (not output)
    {
      cout << "Error creating graph-ex2.dot\n";
      return 1;
    }
  
  Generate_Graphviz<GT, Wnode, Warc>()(g, output, "LR");

  output.close();
  
  return 0;
}
