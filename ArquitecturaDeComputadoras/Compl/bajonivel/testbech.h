/**@file testbench.h
*@brief modulo para probar el Complementador
*@author Ronald Sulbarán
@date 12/6/2011
*/


#ifndef TESTBECH_H
#define TESTBECH_H
#include<systemc.h>
class testbech:public sc_module{
	public:
		public:
		sc_out<sc_uint<2> > y_out;
		sc_out<bool> ctrl_out;
		sc_in<sc_uint<2> > z_in;
		sc_in_clk clk;

		SC_CTOR(testbech){
		SC_THREAD(test);
		sensitive<<clk.pos();
		dont_initialize();
		}	
	private:
		void print_values();
		void test();


};
#endif
