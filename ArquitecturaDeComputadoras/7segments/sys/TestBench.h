#ifndef TESTBENCH_H
#define TESTBENCH_H
#include <systemc.h>
#include<qs_connection.h>
#include"qs_message.h"

using namespace std;

class TestBench: public sc_module{
	QS_CONNECTION(SendFromServer,SendFromClient)

	public:
		sc_in<bool> clk_in;
		sc_out<sc_uint<4> > x_out;
		sc_in<bool> z_in[7];

		SC_CTOR(TestBench){
			QS_CREATE_CONNECTION(30001);
			SC_THREAD(test);
				sensitive<<clk_in.pos();
				dont_initialize();
			
			
			

}
	private:

		void test();
		void print();
};
#endif
