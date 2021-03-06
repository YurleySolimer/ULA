#include "testbench.h"

Testbench::Testbench(sc_module_name nm):sc_module(nm){

	SC_THREAD(test);
		
		sensitive<<clk_in.pos();
		
}

Testbench::~Testbench(){}

void Testbench::test(){
	
	cout<<"a b c"<<endl;

	a_out.write(12);
	b_out.write(0);
	c_out.write(1);
	wait();

	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
		<<c_out.read()<<" "\
		<<s_in.read()<<" "\
         <<c_in.read()<<endl;


	a_out.write(1);
	b_out.write(18);
	c_out.write(0);
	wait();

	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
		 <<c_out.read()<<" "\
		<<s_in.read()<<" "\
          <<c_in.read()<<endl;


	a_out.write(2);
	b_out.write(11);
	c_out.write(0);
	wait();

	cout<< a_out.read()<<" "\
	  <<b_out.read()<<" "\
	 <<c_out.read()<<" "\
	<<s_in.read()<<" "\
         <<c_in.read()<<endl;


	a_out.write(20);
	b_out.write(1);
	c_out.write(3);
	wait();

		cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
		<<c_out.read()<<" "\
		<<s_in.read()<<" "\
         <<c_in.read()<<endl;

	a_out.write(0);
	b_out.write(1);
	c_out.write(1);
	wait();

		cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
		 <<c_out.read()<<" "\
		<<s_in.read()<<" "\
          <<c_in.read()<<endl;



	a_out.write(1);
	b_out.write(0);
	c_out.write(1);
	wait();

	cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
		 <<c_out.read()<<" "\
		<<s_in.read()<<" "\
          <<c_in.read()<<endl;


	a_out.write(1);
	b_out.write(1);
	c_out.write(1);
	wait();

		cout<< a_out.read()<<" "\
		 <<b_out.read()<<" "\
		 <<c_out.read()<<" "\
		<<s_in.read()<<" "\
          <<c_in.read()<<endl;


	//fin de la simulacion 

	cout<<endl<<endl;
	sc_stop();
}




