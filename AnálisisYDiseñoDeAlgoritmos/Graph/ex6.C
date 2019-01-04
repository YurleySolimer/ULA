# include <iostream>

# include <tpl_dynArray.H>
# include <tpl_graph.H>
# include <tpl_cut_nodes.H>
# include <generate_graph.H>

using namespace std;

using Node = Graph_Node<char>;
using Arc  = Graph_Arc<Empty_Class>;
using GT   = List_Graph<Node, Arc>;

string colors[] = { "red", "blue", "green", "purple",
		    "cyan", "darkgreen", "gray" };

struct NodeAttr
{
  void operator () (const GT &, GT::Node * p, ostream & output)
  {
    const string & color = IS_NODE_VISITED(p, Cut) ?
      colors[0] : colors[NODE_COUNTER(p)];
    output << "label = \"" << p->get_info() << "\" color = " << color;
  }
};

struct ArcAttr
{
  void operator () (const GT &, GT::Arc *, ostream &) { /* empty */ }
};

GT read_graph()
{
  GT ret;
  char cs, ct;

  DynArray<GT::Node *> nodes;
  nodes.set_default_initial_value(nullptr);

  while (cin >> cs >> ct)
    {
      GT::Node * s = nodes.touch(cs - 'A');

      if (s == nullptr)
	{
	  s = ret.insert_node(cs);
	  nodes(cs - 'A') = s;
	}

      GT::Node * t = nodes.touch(ct - 'A');

      if (t == nullptr)
	{
	  t = ret.insert_node(ct);
	  nodes(ct - 'A') = t;
	}

      ret.insert_arc(s, t);
    }

  return ret;
}

int main()
{
  GT g = read_graph();

  Compute_Cut_Nodes<GT> ccn(g);

  DynDlist<GT::Node *> l;

  ccn.cut_nodes(g.get_first_node(), l);
  ccn.paint_subgraphs();

  ofstream output("graph-ex6.dot");

  if (not output)
    {
      cout << "Error creating graph-ex6.dot\n";
      return 1;
    }

  To_Graphviz<GT, NodeAttr, ArcAttr>()(g, output);

  output.close();
  
  return 0;
}
