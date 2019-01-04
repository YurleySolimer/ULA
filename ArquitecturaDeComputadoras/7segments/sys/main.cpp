#include "module.h"
#include "TestBench.h"
#include <systemc.h>
int sc_main(int argc, char * argv[]){

	sc_time PERIOD(10,SC_NS);
	sc_time DELAY(10,SC_NS);

	sc_clock clock("clock",PERIOD,0.5,DELAY,true);

	SevenSegments ss("SevenSegments");
	TestBench tb("tb");

	sc_signal<sc_uint<4> > x;
	sc_signal<bool> z[7];



	ss.x_in(x);
	for(int i=0; i< 7;i++){
		ss.z_out[i](z[i]);
		tb.z_in[i](z[i]);
	}



	tb.clk_in(clock);
	tb.x_out(x);
	sc_start();
	return 0;
}
