#include<Complementador.h>
#include<testbench.h>
int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal<sc_uint<8> > a,s;
	sc_signal<bool> ctrl;
	Complementador comp("adder");
	testbech test("test");

	comp.a_in(a);
	comp.s_out(s);
	comp.ctrl_in(ctrl);
	
	
	test.a_out(a);
	test.s_in(s);	
	test.ctrl_out(ctrl);
	test.clk(clk);
	sc_start();
	
return 0;
}
