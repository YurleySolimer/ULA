# include <iostream>

# include <tpl_graph.H>
# include <generate_graph.H>

using namespace std;

using Node = Graph_Node<char>;
using Arc  = Graph_Arc<Empty_Class>;
using GT   = List_Graph<Node, Arc>;

void print_graph(GT & g, const string & name)
{
  cout << "Graph " << name << endl
       << g.get_num_nodes() << " nodes\n";

  for (GT::Node_Iterator it(g); it.has_curr(); it.next())
    cout << it.get_curr()->get_info() << endl;

  cout << g.get_num_arcs() << " arcs\n";
    
  for (GT::Arc_Iterator it(g); it.has_curr(); it.next())
    {
      auto a = it.get_curr();
      auto s = g.get_src_node(a);
      auto t = g.get_tgt_node(a);
      cout << s->get_info() << " -- " << t->get_info() << endl;
    }

  cout << endl;
}

# define PRINT(g) print_graph(g, #g)

GT build_component(GT::Node * s)
{
  assert(not IS_NODE_VISITED(s, Breadth_First));

  GT ret;

  auto ret_s = mapped_node<GT>(s);

  if (ret_s == nullptr)
    {
      ret_s = ret.insert_node(s->get_info());
      GT::map_nodes(s, ret_s);
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

	  auto ret_u = mapped_node<GT>(u);
	  assert(ret_u != nullptr);
	  
	  auto ret_v = mapped_node<GT>(v);

	  if (ret_v == nullptr)
	    {
	      ret_v = ret.insert_node(v->get_info());
	      GT::map_nodes(v, ret_v);
	    }

	  auto ret_a = mapped_arc<GT>(a);

	  if (ret_a == nullptr)
	    {
	      ret_a = ret.insert_arc(ret_u, ret_v, a->get_info());
	      GT::map_arcs(a, ret_a);
	    }

	  if (IS_NODE_VISITED(v, Breadth_First))
	    continue;
	  
	  NODE_BITS(v).set_bit(Breadth_First, true);

	  queue.put(v);
	}
    }

  return ret;
}

DynList<GT> connected_components(GT & g)
{
  g.reset_nodes();
  g.reset_arcs();
  
  DynList<GT> ret;

  for (GT::Node_Iterator it(g); it.has_curr(); it.next())
    {
      auto v = it.get_curr();

      if (IS_NODE_VISITED(v, Breadth_First))
	continue;

      ret.append(build_component(v));
    }

  return ret;
}

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

  auto ga = g.insert_node('a');
  auto gb = g.insert_node('b');
  auto ge = g.insert_node('e');
  auto gd = g.insert_node('d');
  
  g.insert_arc(ga, gb);
  g.insert_arc(gd, gb);
  g.insert_arc(ga, ge);
  g.insert_arc(ga, gd);
  g.insert_arc(ge, gd);
  
  auto gc = g.insert_node('c');
  auto gf = g.insert_node('f');
  auto gh = g.insert_node('h');

  g.insert_arc(gc, gh);
  g.insert_arc(gc, gf);
  g.insert_arc(gh, gf);
  
  auto gg = g.insert_node('g');
  auto gi = g.insert_node('i');

  g.insert_arc(gg, gi);
  g.insert_arc(gi,ga);

  PRINT(g);

  cout << "Computing connected components of g...\n";
  DynList<GT> cc = connected_components(g);
  cout << "Done!\n";

  size_t counter = 0;
  
  cc.mutable_for_each([&counter](GT & c) {
      stringstream s;
      s << "Component " << ++counter;
      print_graph(c, s.str());
      cout << endl;
    });


  ofstream output("graph-ex4.dot");
  
  if (not output)
    {
      cout << "Error creating graph-ex4.dot\n";
      return 1;
    }

  Generate_Graphviz<GT, Wnode, Warc>()(g, output, "LR");
  
  return 0;
}
