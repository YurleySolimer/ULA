
# include <gsl/gsl_rng.h>
# include <tclap/CmdLine.h>
# include <iostream>

using namespace std;
using namespace TCLAP;

int main(int argc, char *argv[])
{
  ValueArg<unsigned long> n("n", "num-samples", "Number of samples", false, 100,
			    "Number of samples to be generated");
  ValueArg<long> i("i", "min", "minimum value", false, 0,
		   "Minimum value that may be generated");
  ValueArg<long> mx("x", "max", "maximum value", false, 1000,
		    "Maximum value that may be generated");
  ValueArg<unsigned long> seed("s", "seed", "seed for random", false, 0,
			       "seed value for random number generator");
  CmdLine cmd("random number generator", ' ', "0.0");
  cmd.add(n);
  cmd.add(i);
  cmd.add(mx);
  cmd.add(seed);
  cmd.parse(argc, argv);

  const auto N = n.getValue();
  if (N == 0)
    {
      cout << "Number of samples is zero" << endl;
      exit(0);
    }

  const auto init = i.getValue();
  const auto m = mx.getValue() + 1;
  if (init > m - 1)
    {
      cout << "Minimum value " << init
	   << " is greater than maximum value " << m - 1 << endl;
      exit(0);
    }

  gsl_rng * r = gsl_rng_alloc(gsl_rng_mt19937);
  gsl_rng_set(r, seed.getValue() % gsl_rng_max(r));
  const unsigned long range = m - init;

  for (long i = 0; i < N; ++i)
    cout << (long) (init + gsl_rng_uniform_int(r, range)) << " ";
  cout << endl;

  gsl_rng_free(r);
}
