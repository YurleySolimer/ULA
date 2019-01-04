#ifndef TESTBENCH_H
#define TESTBENCH_H
#include<systemc.h>


class TestBench:public sc_module{
	
	public:
	sc_in_clk clk;


	//direcciones
	sc_out<sc_uint<5> > dirdata_out;

	sc_out<sc_uint<5> > dira_out;

	sc_out<sc_uint<5> > dirb_out;

	//  dato a escribir
	sc_out<sc_uint<32> > data_out;

	//registro a
	sc_in<sc_uint<32> > ra_in;

	//registro b
	sc_in<sc_uint<32> > rb_in;


	SC_CTOR(TestBench){
		SC_THREAD(test);
		sensitive<<clk.pos();


	}

	private:

	void test();


};  


#endif
