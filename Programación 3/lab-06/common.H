# include <math.h>

# include <string>

using namespace std;

# include <ahSort.H>
# include <tpl_dynSetTree.H>

struct BasicStats
{
  long min;
  long max;
  double median;
  double mean;
  double var;
  size_t len;
  long q1, q3;

  bool operator == (const BasicStats & s) const
  {
    double epsilon = 0.000001;
    return fabs(mean - s.mean) <= epsilon and fabs(var - s.var) < epsilon and
      this->min == s.min and this->max == s.max and median == s.median and 
      len == s.len and q1 == s.q1 and q3 == s.q3;
  }

  BasicStats(long __min, long __max, double __median, double __mean, 
	     long double __var, size_t __len, long __q1, long __q3)
    : min(__min), max(__max), median(__median), mean(__mean),
      var(__var), len(__len), q1(__q1), q3(__q3)
  {
    // empty
  }

  friend string to_str(const BasicStats & st)
  {
    DynList<string> vals = 
      { to_str(st.min), to_str(st.q1), to_str(st.median), to_str(st.mean),
	to_str(sqrt(st.var)), to_str(st.q3), to_str(st.max), to_str(st.len) };

    DynList<string> head = 
      {"Min.", "1st Qu.", "Median", "Mean", "Sigma", "3er Qu.", "Max.", "size"};

    using Pair = pair<const string &, const string &>;
    DynList<size_t> lens = zip(head, vals).map<size_t>([] (const Pair & p)
      {
	return std::max(p.first.size(), p.second.size());
      });

    string ret; 
    ret.reserve(2*lens.foldl<size_t>(0, [] (size_t acc, size_t len)
				     {
				       return acc + len + 1;
				     }));
    
    using Pairh = pair<const string&, size_t>;
    ret = zip(head, lens).foldl<string>("", [] (const string & acc, Pairh p)
      {
	return acc + string(p.second - p.first.size() + 1, ' ') + p.first;
      });
    
    ret.push_back('\n');
    ret += zip(vals, lens).foldl<string>("", [] (const string & acc, Pairh p)
      {
	return acc + string(p.second - p.first.size() + 1, ' ') + p.first;
      });

    return ret;
  }

  friend ostream & operator << (ostream & s, const BasicStats & st)
  {
    return s << to_str(st);
  }
};

using Spair = tuple<long, long>;

inline ostream & operator << (ostream & s, const DynList<long> & l)
{
  l.for_each([&s] (long i) { s << i << " "; });
  return s;
}

inline string to_str(const DynList<long> & l)
{
  string ret;
  l.for_each([&ret] (long i) { ret.append(to_str(i)); ret.push_back(' '); });
  return ret;
}

inline string to_str(const DynList<Spair> & l)
{
  string ret;
  l.for_each([&ret] (const Spair & p) 
  { 
    ret.push_back('(');
    ret.append(to_str(get<0>(p)));
    ret.push_back(','); 
    ret.append(to_str(get<1>(p)));
    ret.push_back(')'); 
  });
  return ret;
}
