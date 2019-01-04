/**@file testbench.h
*@brief modulo para probar el FullAdder
*@author Ronald Sulbarán
*@mail ronalanto03@hotmail.com
@date 17/5/2011
*/


#ifndef TESTBECH_H
#define TESTBECH_H
#include<systemc.h>
class testbech:public sc_module{
	public:
		sc_out<bool> x_out,y_out;
		sc_in<bool> z_in,c_in;
		sc_out<bool> c_out;
		sc_in_clk clk;
		SC_CTOR(testbech){
		SC_THREAD(test);
		sensitive<<clk.pos();
		dont_initialize();
}	
	private:
		void print_result();
		void test();


};
#endif
