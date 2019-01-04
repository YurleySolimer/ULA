#include<registerfile.h>
#include<TestBench.h>
int sc_main(int argc,char *argv[]){
	sc_time DELAY(10,SC_NS);
	sc_time PERIOD(10,SC_NS);
	
	sc_clock clk("clock",PERIOD,0.5,DELAY,true);
	sc_signal<sc_uint<5> > dira,dirb,dirdata;
	
	sc_signal<sc_uint<32> > data,ra,rb;
	Registerfile Reg("Reg");
	TestBench test("test");

	Reg.dira_in(dira);
	Reg.dirb_in(dirb);
	Reg.dirdata_in(dirdata);
	Reg.data_in(data);
	Reg.ra_out(ra);
	Reg.rb_out(rb);
	Reg.clk(clk);
		
	
	test.dira_out(dira);
	test.dirb_out(dirb);
	test.dirdata_out(dirdata);
	test.data_out(data);
	test.ra_in(ra);
	test.rb_in(rb);
	test.clk(clk);
	sc_start();
	
return 0;
}
