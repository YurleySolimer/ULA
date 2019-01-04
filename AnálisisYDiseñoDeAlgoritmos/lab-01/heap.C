
# include <cassert>
# include <fstream>
# include <iostream>

# include <ahSort.H>
# include <htlist.H>

typedef unsigned long Ulong; 
typedef unsigned long long U64;

struct SumExtremes
{
  DynList<Ulong> extremes;
  long long sum;

  SumExtremes() {}

  SumExtremes(DynList<Ulong> && items, const long long __sum)
    : extremes(std::move(items)), sum(__sum)
  {
    // empty
  }
};


# include <read-sum.C>

void usage(char * name)
{
  cout << name << " file-name num-lines n"  << endl;
  exit(0);
}

int main(int argc, char *argv[])
{
  if (argc != 4)
    usage(argv[0]);

  ifstream in(argv[1]);

  if (not in)
    {
      cout << "Problem opening " << argv[1] << endl;
      exit(0);
    }

  const size_t num_lines = atoi(argv[2]);
  const size_t n = atoi(argv[3]);

  std::pair<SumExtremes, SumExtremes> p = compute_extremes(in, num_lines, n);

  cout << "Smallers            = ";
  sort(p.first.extremes).for_each([] (Ulong i)
				  {
				    cout << i << " ";
				  });
  cout << endl
       << "sum                 = " 
       << p.first.extremes.foldl<U64>(0, [] (U64 acc, U64 i)
				      {
					return acc + i;
				      }) << endl
       << "online smallers sum = " << p.first.sum << endl
       << "Biggers             = ";
  sort(p.second.extremes).for_each([] (Ulong i)
				   {
				     cout << i << " ";
				   });
  cout << endl
       << "sum                 = " 
       <<  p.second.extremes.foldl<U64>(0, [] (U64 acc, U64 i)
					{
					  return acc + i;
					}) << endl
       << "online biggers sum  = " << p.second.sum << endl;

  return 0;
}

