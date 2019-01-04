# ifndef TESTBENCH_H
# define TESTBENCH_H

# include <systemc.h>

class TestBench: public sc_module{
	public:
		
		sc_in_clk clk_in;
		sc_out<bool> a_out;
		sc_out<bool> b_out;
		sc_out<bool> c_out;
		sc_in<bool> c_in;
		sc_in<bool> s_in;
		


		SC_CTOR(TestBench);
		~TestBench(){};
		


	private:
		void test();
	


};

#endif
