/**@file sc_main.cpp
*@brief aqui se conectan el el FullAdder con el testbech 
*@author Ronald Sulbarán
@date 12/6/2011
*/

#include<Compl.h>
#include<testbech.h>
int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal<sc_uint<2> > y,z;
	sc_signal<bool> ctrl;
	Compl com("adder");
	testbech test("test");

	com.y_in(y);
	com.z_out(z);
	com.ctrl_in(ctrl);
	
	
	test.y_out(y);
	test.z_in(z);	
	test.ctrl_out(ctrl);
	test.clk(clk);
	sc_start();
	
return 0;
}
