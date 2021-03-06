#include "and_gate.h"
#include "Or_gate.h"
#include "Xor_gate.h"
#include "Full_Adder.h"
#include "testbench.h"
#include "Complementador.h"
#include "Sumador.h"
#include "Restador.h"


int sc_main(int argv, char* argc[]){
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);
	sc_signal<bool> c_i,c_o,ovf;
	sc_signal<sc_uint<8> > a, b, s;

	Testbench tb("tb");
	Restador Re("re1");
	//Complementador Co("co");
	
	Re.a_in(a);
	Re.b_in(b);
	Re.c_in(c_i);
	Re.c_out(c_o);
	Re.s_out(s);

	/*Co.b_in(b);
	Co.s_out(s);
	Co.ctrl_in(c_i);*/

	tb.clk_in(clock);
	tb.a_out(a);
	tb.b_out(b);
	tb.c_out(c_i);
	tb.c_in(c_o);
	tb.s_in(s);
	

	sc_start();
return 0;

}
