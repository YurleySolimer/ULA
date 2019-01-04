
# include <gsl/gsl_rng.h>
# include <cassert>
# include <fstream>
# include <iostream>
# include <ahFunctional.H>
# include <io_graph.H>
# include <tpl_dynSetTree.H>
# include <tpl_dynSetHash.H>
# include <tpl_graph_indexes.H>
# include <ahSort.H>
# include <tpl_dynListStack.H>
# include <tpl_dynListQueue.H>

# include "net.H"

using namespace std;

bool verbose = false;

gsl_rng * r = NULL;

# include "find.H"

void usage()
{
  cout << "usage " << endl
       << "    rand-paths num-test [seed] < graph" << endl
       << "        num-test: number of random tests" << endl
       << endl
       << "I perform num-tests tests of each function" << endl;
  exit(0);
}

NetColor gen_random_color()
{
  NetColor color = gsl_rng_uniform_int(r, 255) + 1;
  assert(color > 0 and color <= 255);
  return color;
}

using FP = Path<SocialNet> (*)(const SocialNet &, 
			       const unsigned long,
			       const unsigned long,
			       const NetColor,
			       const NetColor);

void test_find_path(const SocialNet & net, const int n, FP find_path,
		    const string & name)
{
  cout << endl
       << "Generating " << n << name << " first searches" << endl;
  for (auto i = 0; i < n; ++i)
    {
      const auto & V = net.vsize();
      auto src_id = gsl_rng_uniform_int(r, V);
      auto tgt_id = gsl_rng_uniform_int(r, V);
      const NetColor node_color = gen_random_color();
      const NetColor arc_color = gen_random_color();

      cout << src_id << ":" << tgt_id << " " << bits_str(node_color) 
	   << " " << bits_str(arc_color) << ": ";
      if (src_id == tgt_id)
	cout << "LOOP";
      else
	out_path(find_path(net, src_id, tgt_id, node_color, arc_color));
      cout << endl
	   << endl;
    }
}

void test(const SocialNet & net, const int num_tests)
{
  cout << "List of node colors:" << endl;
  sort(count_node_color(net)).
    for_each([] (auto p)
    {
      cout << "    Color " << bits_str(p.first) << " = " << p.second << endl
	   << endl;
    });
  cout << endl
       << "List of arc colors:" << endl;
  sort(count_arc_color(net)).for_each([] (auto p)
    {
      cout << "    Color " << bits_str(p.first) << " = " << p.second << endl
	   << endl;
    });
  cout << endl
       << "Testing count_node_color" << endl;
  count_node_color(net).for_each([] (auto p)
    {
      cout << "Node color = " << bits_str(p.first) << ": " << p.second << endl
	   << endl;
    });
  
  cout << endl
       << "Testing count_arc_color" << endl;
  count_arc_color(net).for_each([] (auto p)
    {
      cout << "Arc color = " << bits_str(p.first) << ": " << p.second << endl
	   << endl;
    });
  
  cout << "Tests for arbitrary color node masks" << endl;
  range(1, num_tests).for_each([&net] (int)
    {
      NetColor color = gen_random_color();
      cout << "Nodes of color " << bits_str(color) << ": ";
      nodes(net, color).for_each([] (SocialNet::Node * p)
       {
	 const Friend & f = p->get_info();
	 cout << "(" << f.id << "," << bits_str(f.color) << ")";
       });
      cout << endl
	   << endl;
    });

  cout << endl
       << "Test for specific node colors" << endl;
  range<size_t>(1, 8*sizeof(NetColor)).for_each([&net] (auto i)
    {
      int color = 1 << (i - 1);
      cout << "Nodes with color " << bits_str(color) << ": ";
      nodes(net, color).for_each([] (SocialNet::Node * p)
        {
	  const Friend & f = p->get_info();
	  cout << "(" << f.id << "," << bits_str(f.color) << ")";
       });
      cout << endl
	   << endl;
    });

  cout << endl
       << "Tests for arbitrary color arc masks" << endl;
  range(1, num_tests).for_each([&net] (int)
    {
      NetColor color = gen_random_color();
      cout << "Arc of color " << bits_str(color) << ": ";
      arcs(net, color).for_each([] (SocialNet::Arc * p)
       {
	 const FriendShip & f = p->get_info();
	 cout << "(" << bits_str(f.color) << "," << f.cost << ")";
       });
      cout << endl
	   << endl;
    });

  cout << endl
       << "Test for specific arc colors" << endl;
  range<size_t>(1, 8*sizeof(NetColor)).for_each([&net] (auto i)
    {
      int color = 1 << (i - 1);
      cout << "Arcs with color " << bits_str(color) << ": ";
      arcs(net, color).for_each([] (SocialNet::Arc * a)
        {
	  const FriendShip & f = a->get_info();
	  cout << "(" << bits_str(f.color) << "," << f.cost << ")";
       });
      cout << endl
	   << endl;
    });

  test_find_path(net, num_tests, find_path_breadth_first, "Breadth");

  test_find_path(net, num_tests, find_path_depth_first, "Depth");
  
  cout << endl;
}

int main(int argc, char *argv[])
{
  if (argc < 2)
    usage();

  SocialNet net;
  IO_Graph<SocialNet>(net).load_in_text_mode(cin);

  r = gsl_rng_alloc(gsl_rng_mt19937);
  unsigned long seed = argc == 3 ? atol(argv[2]) : 0; 
  gsl_rng_set(r, seed % gsl_rng_max(r));

  const size_t num_tests = atol(argv[1]);

  test(net, num_tests);

  gsl_rng_free(r);

  return 0;
}

