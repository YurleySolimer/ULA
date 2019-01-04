#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <systemc.h>
#include <iostream>
#include "Full_Adder.h"
#include "Sumador.h"

using namespace std;
class Testbench : public sc_module{

	public:	
		sc_in<bool> clk_in;		
		sc_in<bool> c_in;
		sc_out<bool> c_out;
		sc_in<sc_uint<8> > s_in;
		sc_out<sc_uint<8> > a_out, b_out;

		SC_CTOR(Testbench);
		~Testbench();
	private:
		void test();
	
		
};

#endif
