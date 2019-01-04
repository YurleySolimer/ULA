
# include <cassert>
# include <random_graph.H>
# include <io_graph.H>
# include <net.H>
# include <gen-net.H>

void usage()
{
  cout << "gen-net num-nodes prob min-w max-w [seed]" << endl
       << "    num-nodes: number of nodes" << endl
       << "    [prob]: (0.15) probability of conection between two nodes" << endl
       << endl
       << "    min-w: (1) mininum weigth of arc" << endl
       << "    max-w: (1) maximum weigth of arc" << endl
       << "    seed: random seed" << endl
       << endl
       << "Weights are generated according to a uniform distribution" << endl
       << endl;
  exit(0);
} 

bool verbose = false;

int main(int argc, char *argv[])
{
  if (argc < 2)
    usage();

  const unsigned int num_nodes = atoi(argv[1]);
  const double prob = argc > 2 ? atof(argv[2]) : 0.15;
  const long min_w = argc > 3 ? atol(argv[3]) : 1;
  const long max_w = argc > 4 ? atol(argv[4]) : 1;
  const unsigned long seed = argc > 5 ? atoi(argv[5]) : 0;

  if (min_w > max_w)
    {
      cout << min_w << " must be greater than " << max_w << endl;
      exit(0);
    }

  SocialNet net = create_random_net(num_nodes, prob, min_w, max_w, seed);
  IO_Graph<SocialNet>(net).save_in_text_mode(cout);
}
