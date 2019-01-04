#include "and_gate.h"
#include "Or_gate.h"
#include "Xor_gate.h"
#include "Full_Adder.h"
#include "testbench.h"
#include "Sumador.h"

int sc_main(int argv, char* argc[]){
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);
	sc_signal<bool> c_i,c_o,ovf;
	sc_signal<sc_uint<8> > a, b, s;

	Sumador Su("su1");
	Testbench tb("tb");

	Su.a_in(a);
	Su.b_in(b);
	Su.c_in(c_i);
	Su.c_out(c_o);
	Su.s_out(s);

	tb.clk_in(clock);
	tb.a_out(a);
	tb.b_out(b);
	tb.c_out(c_i);
	tb.c_in(c_o);
	tb.s_in(s);
	

	sc_start();
return 0;

}
