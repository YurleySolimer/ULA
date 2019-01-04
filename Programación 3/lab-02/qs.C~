
# include <gsl/gsl_rng.h>
# include <now.h>
# include <tuple>
# include <fstream>
# include <iostream>
# include <tclap/CmdLine.h>
# include <tpl_dynArray.H>

# include <ahSort.H>

# include <common.H>

using namespace std;
using namespace TCLAP;

/* Lo siguientes valores son variables globales que NO NECESITAS MODIFICAR.

   Random_Threshold: a partir de que tamaño de partición se comienza a
                     seleccionar la mediana entre una cantidad de
                     muestras aleatorias.
   Num_Samples: cantidad de muestras aleatorias cuando se seleccione el
                pivote entre la mediana de Num_Samples elementos

   Max_Num_Samples: longitud del arreglo interno para ordenar la muestras.
 */
size_t Random_Threshold = 5;
size_t Num_Samples = 3;
const size_t Max_Num_Samples = 50;

gsl_rng * g = NULL; // generador de números aleatorios


# include <q.H>


// Retorna true si a está ordenado
bool sorted(const DynArray<long> & a) noexcept
{
  if (a.is_empty())
    return true;

  long val = numeric_limits<long>::min();
  return a.all([&val] (long item)
	       {
		 if (item < val)
		   return false;
		 val = item;
		 return true;
	       });
}

// Esta rutina lee num_lines números del archivo abierto in
DynArray<long> read_stream(istream & in, const size_t num_items) 
{
  DynArray<long> ret_val;
  for (auto item_num = 0; item_num < num_items; ++item_num)
    {
      long value;
      if (in >> value)
	ret_val.append(value);
      else
	{
	  stringstream s;
	  s << "Input has " << item_num << " items, but " << num_items 
	    << " were specified";
	  throw std::overflow_error(s.str());
	}
    }

  return ret_val; 
}

// Retorna true si a está particionado según el pivote en pivot_idx
bool partition_ok(const DynArray<long> & a, size_t pivot_idx) noexcept
{
  auto pivot = a(pivot_idx);
  for (auto i = 0; i < a.size(); ++i)
    if (i < pivot_idx)
      if (a(i) <= pivot)
	continue;
      else
	return false;
    else if (i > pivot_idx)
      if (a(i) >= pivot)
	continue;
      else 
	return false;
  
  return true;
}


ostream & operator << (ostream & s, const tuple<size_t, size_t> & t)
{
  return s << "(" << get<0>(t) << "," << get<1>(t) << ")" << endl;
}


ostream & operator << (ostream & s, const DynArray<long> & a)
{
  a.for_each([&s] (long i) { s << i << " "; });
  return s;
}


bool test(const DynArray<long> & array, Sel_Pivot sel_pivot, 
	  const string & msg, bool verbose) 
{
  bool part_ok;
  {
    auto a = array;
    auto p = qs_partition(a, 0, a.size() - 1, sel_pivot);
    part_ok = partition_ok(a, get<0>(p));

    cout << "Testing partition " << msg << endl;
    if (verbose)
      cout << a << endl;
    cout << "    Pivot is " << a(get<0>(p)) << " at pos " << get<0>(p) << endl
	 << "    Num of comps = " << get<1>(p) << endl
	 << "    Num of swaps = " << get<2>(p) << endl
	 << "    Partition is " << (part_ok ? "VALID" : "INVALID") << endl;  
  }

  auto a = array;
  auto t = now(); 
  auto sort_res = qs(a, 0, a.size() - 1, sel_pivot);
  t = now_delta(&t);
  
  bool sort_ok = sorted(a);
  
  cout << "Testing sort" << endl;
  if (verbose)
    cout << a << endl;
  cout << "    Num of comps = " << get<0>(sort_res) << endl
       << "    Num of swaps = " << get<1>(sort_res) << endl
       << "    Result is " << (sort_ok ? "" : "not") << " sorted" << endl
       << "    Time = " << t << endl
       << endl;

  return part_ok and sort_ok;
}


void process_command_line(int argc, char *argv[])
{
  ValueArg<unsigned long> seed("S", "seed", "seed", false, 11, 
			       "seed for random number generator");
  ValueArg<size_t> num_items("n", "num-items", "number of item", false, 10,
			     "number of items to be read from stream");
  ValueArg<size_t> num_samples("s", "num-samples", "Number of samples", false,
			       3, 
			       "Number of samples for selecting random median");
  ValueArg<size_t> threshold("t", "threshold", "threshold for insertion sort", 
			     false, 40, 
			     "partition size threshold for insertion sort");
  SwitchArg verbose("v", "verbose", "verbose array", false);
  CmdLine cmd("qs", ' ', "0.0");
  cmd.add(seed);
  cmd.add(num_items);
  cmd.add(num_samples);
  cmd.add(threshold);
  cmd.add(verbose);
 
  cmd.parse(argc, argv);

  Num_Samples = num_samples.getValue();
  Random_Threshold = threshold.getValue();

  g = gsl_rng_alloc (gsl_rng_mt19937);
  gsl_rng_set(g, seed.getValue() % gsl_rng_max(g));

  DynArray<long> unsorted = read_stream(cin, num_items.getValue());
  if (verbose.getValue())
    cout << unsorted << endl
	 << endl;

  test(unsorted, select_left, "left side", verbose.getValue());
  test(unsorted, select_right, "right side", verbose.getValue());
  test(unsorted, select_random, "random", verbose.getValue());
  test(unsorted, select_median, "median", verbose.getValue());
  test(unsorted, select_random_median, "random median", verbose.getValue());

  gsl_rng_free(g);
}

int main(int argc, char *argv[])
{
  process_command_line(argc, argv);
}
