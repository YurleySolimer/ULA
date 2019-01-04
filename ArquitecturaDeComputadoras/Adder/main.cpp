#include "and_gate.h"
#include "testbench.h"
#include "fulladder.h"

int sc_main(int argv, char* argc[]){
	sc_time PERIOD(10,SC_NS);//SC_PS SC_SEC . . .	
	sc_time DELAY(10,SC_NS);	
	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	Full_Adder ag1("ag1");
	TestBench tb("tb");

	sc_signal<bool>  s1_sg, s2_sg, s2_sg;

	ag1.a_in(a_sg);
	ag1.b_in(b_sg);
	ag1.c_in(c_sg);
	ag1.s_out(s1_sg);
	ag1.c_out(s2_sg);

	tb.clk_in(clock);
	tb.a_out(a_sg);
	tb.b_out(b_sg);
	tb.c_out(c_sg);
	tb.s_in(s1_sg);
	tb.c_in(s2_sg);


	sc_start();

	return 0;
}
