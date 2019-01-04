
# include <gsl/gsl_rng.h>
# include <fstream>
# include <iostream>
# include <io_graph.H>
# include <generate_graph.H>
# include <net.H>

using namespace std;

bool verbose = false;

struct WFriend
{
  void operator () (const SocialNet &, SocialNet::Node * p, 
		    std::ostream & output) const
  {
    const Friend & f = p->get_info();
    output << "label = \"" << f.id << " " << bits_str(f.color) << "\"";
  }
};

struct WFriendShip
{
  void operator () (const SocialNet & net, SocialNet::Arc * a, 
		    std::ostream & output) const
  {
    const FriendShip & f = a->get_info();
    output << "label = \"" << bits_str(f.color) << " " << f.cost << "\"";
  }
};

int main()
{
  SocialNet net;
  IO_Graph<SocialNet>(net).load_in_text_mode(cin);
  To_Graphviz<SocialNet, WFriend, WFriendShip> () (net, (ofstream&) cout);
}

