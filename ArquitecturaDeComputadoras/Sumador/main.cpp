#include "and_gate.h"
#include "Or_gate.h"
#include "Xor_gate.h"
#include "Full_Adder.h"
#include "testbench.h"

int sc_main(int argv, char* argc[]){
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);
	sc_signal<bool> a;
	sc_signal<bool> b;
	sc_signal<bool> s;
	sc_signal<bool> c_i;
	sc_signal<bool> c_o;

	Full_Adder fa1("fa1");
	Testbench tb("tb");

	fa1.a_in(a);
	fa1.b_in(b);
	fa1.s_out(s);
	fa1.c_in(c_i);
	fa1.c_out(c_o);
	

	tb.clk_in(clock);
	tb.a_out(a);
	tb.b_out(b);
	tb.s_in(s);
	tb.c_in(c_o);
	tb.c_out(c_i);
	
	
	

	sc_start();
return 0;

}
