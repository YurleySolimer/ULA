/**@file sc_main.cpp
*@brief aqui se conectan el el FullAdder con el testbech 
*@author Ronald Sulbarán
*@mail ronalanto03@hotmail.com
@date 17/5/2011
*/

#include<FullAdder.h>
#include<testbech.h>
int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal<bool> x,y,z;
	sc_signal<bool> c_i,c_o,ovf;
	FullAdder adder("adder");
	testbech test("test");

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
