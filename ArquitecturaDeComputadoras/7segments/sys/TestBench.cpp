#include "TestBench.h"
#include <iostream>
using namespace std;

void TestBench::test(){
	int i=0;

	QS_THREAD_BEGIN

		QS_READ

		x_out.write(QS_GET_READ.number);

		wait();
		print();


		QS_SET_MESSAGE.z0=z_in[0].read();
		QS_SET_MESSAGE.z1=z_in[1].read();
		QS_SET_MESSAGE.z2=z_in[2].read();
		QS_SET_MESSAGE.z3=z_in[3].read();
		QS_SET_MESSAGE.z4=z_in[4].read();
		QS_SET_MESSAGE.z5=z_in[5].read();
		QS_SET_MESSAGE.z6=z_in[6].read();
			

		QS_WRITE

			
	QS_THREAD_END

	sc_stop();
}




void TestBench::print(){
	cout<<"\t"<<x_out.read()<<endl;
}
