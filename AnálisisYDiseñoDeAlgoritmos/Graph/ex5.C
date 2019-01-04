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
    s << p->get_info() << " / " << NODE_COUNTER(p);
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

void bfs(GT & g, GT::Node * s)
{
  g.reset_nodes();
  g.reset_arcs();
  
  for (GT::Node_Iterator it(g); it.has_curr(); it.next())
    {
      auto v = it.get_curr();
      NODE_COUNTER(v) = (v == s ? 0 : std::numeric_limits<long>::max());
    }
  
  NODE_BITS(s).set_bit(Breadth_First, true);
  DynListQueue<GT::Node *> queue;
  queue.put(s);
  
  while (not queue.is_empty())
    {
      auto u = queue.get();

      for (GT::Node_Arc_Iterator it(u); it.has_curr(); it.next())
	{
	  auto a = it.get_curr();

	  if (IS_ARC_VISITED(a, Breadth_First))
	    continue;

	  ARC_BITS(a).set_bit(Breadth_First, true);

	  auto v = it.get_tgt_node();

	  if (IS_NODE_VISITED(v, Breadth_First))
	    continue;

	  NODE_COUNTER(v) = NODE_COUNTER(u) + 1;
	  NODE_BITS(v).set_bit(Breadth_First, true);
	  queue.put(v);
	}
    }
}


int main()
{
  GT g;
  
  auto gs = g.insert_node('s');
  auto ga = g.insert_node('a');
  auto gb = g.insert_node('b');
  auto gc = g.insert_node('c');
  auto gd = g.insert_node('d');
  auto ge = g.insert_node('e');

  g.insert_arc(gs, ga);
  g.insert_arc(gs, gb);
  g.insert_arc(ga, gc);
  g.insert_arc(ga, gb);
  g.insert_arc(gc, ge);
  g.insert_arc(gc, gd);
  g.insert_arc(gb, gd);
  g.insert_arc(gd, ge);

  bfs(g, gs);

  ofstream output("graph-ex5.dot");
  
  if (not output)
    {
      cout << "Error creating graph-ex5.dot\n";
      return 1;
    }

  Generate_Graphviz<GT, Wnode, Warc>()(g, output, "LR");

  output.close();
  
  return 0;
}
