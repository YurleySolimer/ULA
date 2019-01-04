/**@file sc_main.cpp
*@brief aqui se conectan el Adder2Bits con el testbench 
*@author Ronald Sulbarán
*@mail ronalanto03@hotmail.com
@date 11/6/2011
*/

#include<Adder2Bits.h>
#include<testbench.h>
int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal<sc_uint<2> > x,y,z;
	sc_signal<bool> c_i,c_o,ovf;
	Adder2Bits adder("adder");
	testbench test("test");

	adder.x_in(x);
	adder.y_in(y);
	adder.z_out(z);
	adder.c_in(c_i);
	adder.c_out(c_o);
	
	
	test.x_out(x);
	test.y_out(y);
	test.z_in(z);	
	test.c_in(c_o);
	test.c_out(c_i);
	test.clk(clk);
	sc_start();
	
return 0;
}
