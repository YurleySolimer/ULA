
# include <string>
# include <tpl_agraph.H>

using namespace std;
using namespace Aleph;

typedef unsigned long long U64;

typedef unsigned char NetColor;

string bits_str(NetColor color)
{
  return reverse(range(1, 8).map<int>([&color] (int)
    {
      int bit = (color & 1);
      color >>= 1;
      return bit;
    })).foldl<string>("", [] (auto str, auto i)
		      {
			return str + to_str(i);
		      });
}

struct Friend
{
  unsigned long id = 0;
  NetColor color   = 0;

  Friend(unsigned long __id = 0) : id(__id) { /* empty */ }

  std::string to_str() const
  {
    return Aleph::to_str(id) + " " + Aleph::to_str((int)color);
  }

  friend istream & operator >> (istream & s, Friend & f)
  {
    int color;
    s >> f.id >> color;
    f.color = color;
    return s;
  }

  friend ostream & operator << (ostream & s, const Friend & f)
  {
    return s << f.to_str();
  }

  // functor que define cómo se comparan dos amigos. Útil para buscar
  // secuencialmente nodos en la red
  struct Equals
  {
    bool operator () (const Friend & f1, const Friend & f2) const
    {
      return f1.id == f2.id;
    }
  };

  bool operator == (const Friend & r) const
  {
    return id == r.id;
  }
};

struct FriendShip
{
  NetColor color;
  int cost;

  string to_str() const
  {
    return Aleph::to_str((int)color) + " " + Aleph::to_str(cost);
  }

  friend ostream & operator << (ostream & s, const FriendShip & f)
  {
    return s << f.to_str();
  }

  friend istream & operator >> (istream & s, FriendShip & f)
  {
    int color;
    s >> color >> f.cost;
    f.color = color;
    return s;
  }

  bool operator == (const FriendShip & r) const
  {
    return color == r.color and cost == r.cost;
  }
};

const NetColor Red    =   1;
const NetColor Blue   =   2;
const NetColor Yellow =   4;
const NetColor Orange =   8;
const NetColor Green  =  16;
const NetColor Cyan   =  32;
const NetColor Brown  =  64;
const NetColor Pink   = 128;


typedef Array_Graph<Graph_Anode<Friend>, Graph_Aarc<FriendShip>> SocialNet;

    // Búsqueda lineal de nodo con id
inline SocialNet::Node * search_node(SocialNet & net, unsigned int id)
{
  if (id >= net.vsize())
    throw std::out_of_range("id is greater than |V|");

  return net.search_node([id] (auto p) { return p->get_info().id == id; });
}

    // Búsqueda lineal de nodo con id
inline SocialNet::Node * search_node(const SocialNet & net, unsigned int id)
{
  if (id >= net.vsize())
    throw std::out_of_range("id is greater than |V|");

  return net.search_node([id] (auto p) { return p->get_info().id == id; });
}

inline void out_path(const Path<SocialNet> & path, ostream & out = cout)
{
  if (path.size() == 0)
    {
      out << "Empty path";
      return;
    }

  for (Path<SocialNet>::Iterator it(path); it.has_current_arc(); it.next())
    {
      const auto p = it.get_current_node();
      const auto & f = p->get_info();
      const auto & fs = it.get_current_arc()->get_info();
      out << "(" << f.id << "," << bits_str(f.color) << "," << p->num_arcs 
	  << ")-[" << bits_str(fs.color) << "," << fs.cost << "]-";
    }
  const auto & f = path.get_last_node()->get_info();
  out << "(" << f.id << "," << bits_str(f.color) << ") (length = " 
      << path.size() << ")";
}

inline tuple<DynList<Friend>, DynList<FriendShip>>
path_to_list(const Path<SocialNet> & path)
{
  auto nodes = path.nodes().map<Friend>([] (auto p) { return p->get_info(); });
  auto arcs = path.arcs().map<FriendShip>([](auto a) { return a->get_info(); });
  return make_tuple(nodes, arcs);
}

inline string path_to_str(const Path<SocialNet> & path)
{
  if (path.is_empty())
    return string("Path is empty");

  string ret;
  for (Path<SocialNet>::Iterator it(path); it.has_current_arc(); it.next())
    {
      const auto p = it.get_current_node();
      const auto & f = p->get_info();
      const auto & fs = it.get_current_arc()->get_info();
      ret += "(" + to_str(f.id) + "," + bits_str(f.color) + "," +
	to_string(p->num_arcs) + ")-[" + bits_str(fs.color) + "," + 
	to_str(fs.cost) + "]-";
    }
  const auto & f = path.get_last_node()->get_info();
  ret += "(" + to_str(f.id) + "," + bits_str(f.color) + "," +
    to_string(path.get_last_node()->num_arcs) + ")" "(length = " +
    to_str(path.size()) + ")";

  return ret;
}

inline void out_node_list(const DynList<SocialNet::Node*> & l, 
			  ostream & out = cout)
{
  l.for_each([&out] (auto p)
	     {
	       const auto & f = p->get_info();
	       out << "(" << f.id << "," << bits_str(f.color) << ")";
	     });
}

inline void out_arc_list(const DynList<SocialNet::Arc*> & l, 
			 ostream & out = cout)
{
  l.for_each([&out] (auto a)
	     {
	       const auto & f = a->get_info();
	       out << "[" << bits_str(f.color) << "," << f.cost << "]";
	     });
}

inline void out_pairs(const DynList<std::pair<NetColor, size_t>> & l,
		      ostream & out = cout)
{
  l.for_each([&out] (auto p)
	     {
	       out << "(" << bits_str(p.first) << "," << p.second << ")";
	     });
}
