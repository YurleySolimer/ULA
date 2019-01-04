#include "and_gate.h"

And_Gate::And_Gate(sc_module_name nm):sc_module(nm){
	
	SC_METHOD(operation);
		sensitive<<a_in<<b_in;
}

And_Gate::~And_Gate(){}

void And_Gate::operation(){
		
		c_out.write( a_in.read() and b_in.read() );
}






