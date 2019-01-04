
using Point = tuple<double,double>; // x, y

using City = tuple<Point, unsigned long>; // 2do campo es el id único

using Gmap = Array_Graph<Graph_Anode<City>, Graph_Aarc<double>>;

const double Epsilon = 1e-6;

inline string to_str(const Path<Gmap> & path)
{
  if (path.is_empty())
    return string("Path is empty");

  string ret;
  double sum = 0.0;
  for (Path<Gmap>::Iterator it(path); it.has_current_arc(); it.next())
    {      
      Gmap::Arc * a = it.get_current_arc();
      Gmap::Node * p = it.get_current_node();
      const double & d = a->get_info();
      sum += d;
      ret.append(to_str(get<1>(p->get_info())));
      ret.push_back('(');
      ret.append(to_str(d));
      ret.push_back(')');
    }
  ret.append(to_str(get<1>(path.get_last_node()->get_info())));
  ret.push_back('\n');
  ret.append(to_str(sum));

  return ret;
}

inline ostream & operator << (ostream & s, const Path<Gmap> & path)
{
  return s << to_str(path);
}

inline DynList<City> cities(const size_t num_points, 
          const double xsize,
          const double ysize,
          unsigned long seed)
{
  gsl_rng * r = gsl_rng_alloc(gsl_rng_mt19937);
  gsl_rng_set(r, seed % gsl_rng_max(r));

  DynList<City> ret;

  City c;
  Point & p = get<0>(c);

  DynSetTree<unsigned long, Avl_Tree> ids;

  for (int i = 0; i < num_points; ++i)
    {
      get<0>(p) = xsize * gsl_rng_uniform(r);
      get<1>(p) = ysize * gsl_rng_uniform(r);

      unsigned long id = 0;

      while (true)
  {
    id = gsl_rng_get(r);

    if (ids.insert(id) != nullptr)
      break;
  }

     
      get<1>(c) = id;

      ret.append(c);
    }

  gsl_rng_free(r);

  return ret;
}
