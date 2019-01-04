
# include <cassert>
# include <iostream>
# include <tuple>
# include <common.H>

# include <stats.H>


void test()
{
  Sampler s = range<long>(0, 100000);	
//Sampler s = Sampler({0,0,0,3,4,5,5,6,8,9});
  s.add_sample(10);

  //assert(s == Sampler({0,1,2,3,4,5,6,7,8,9,10}));
	s.mean();
	s.var();
	s.size();
	s.stats();
	//s.get_sample(2); //con 2 debe dar 3 
	s.list();
	
	//s.get_by_position(2,6);
	//s.sample_by_position(3, 6);
 assert(eq(s.get_by_position(2, 6), {2,3,4,5}));
	assert(eq(Sampler(s.get_by_position(2, 6)).list(), {2,3,4,5}));
	
	// s.get_by_key(s.list());

//DynList<long>l={1,2,3,4,22};
	//s.get_by_key(l);

	assert(eq(s.get_by_key(3, 6), {4,5,6}));

	//s.sample_by_position(2, 6);
 	assert(s.sample_by_position(2, 6) == Sampler({2,3,4,5}));
assert(s.sample_by_key(3,6) == Sampler({3,4,5,6}));

//s.cut_key(2,6);
  
	Sampler copy = s;

//s.cut_position(2,6);
 assert(eq(s.cut_position(2,6).list(), {2,3,4,5}));
   assert(s == copy.sample_by_position(2,6));
  assert(s == copy.cut_position(2,6));

}

void test_key()
{

}


int main()
{
int i=0;
/*while(i<=10)
{
 test();
	i++; }*/ test();

 //test_key(n);

  cout << "every thing ok?" << endl;
}
