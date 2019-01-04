/**@file testbench.h
*@brief modulo para probar el Adder2Bits
*@author Ronald Sulbarán
*@mail ronalanto03@hotmail.com
@date 17/5/2011
*/


#ifndef TESTBECH_H
#define TESTBECH_H
#include<systemc.h>
class testbench:public sc_module{
	public:
		sc_out<sc_uint<2> > x_out,y_out;
		sc_in<sc_uint<2> > z_in;
		sc_in<bool> c_in;
		sc_out<bool> c_out;
		sc_in_clk clk;
		SC_CTOR(testbench){
		SC_THREAD(test);
		sensitive<<clk.pos();
		dont_initialize();
}	
	private:
		void print_result();
		void test();


};
#endif
