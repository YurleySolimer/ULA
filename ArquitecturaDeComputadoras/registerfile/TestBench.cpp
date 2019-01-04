#include"TestBench.h"
void TestBench::test(){
	cout<<"dira\tdirb\tdirdata\tdata\tra\trb"<<endl;
	dira_out.write(2);
	dirb_out.write(5);
	data_out.write(4);
	dirdata_out.write(2);
	wait();


	cout<<dira_out.read()<<"\t"<<dirb_out.read()<<"\t"<<dirdata_out.read()<<"\t"<<data_out.read()<<"\t"<<ra_in.read()<<"\t"<<rb_in.read()<<endl;




	dira_out.write(2);
	dirb_out.write(5);
	data_out.write(677);
	dirdata_out.write(2);
	wait();


	cout<<dira_out.read()<<"\t"<<dirb_out.read()<<"\t"<<dirdata_out.read()<<"\t"<<data_out.read()<<"\t"<<ra_in.read()<<"\t"<<rb_in.read()<<endl;


	sc_stop();
}
