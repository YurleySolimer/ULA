#include "xor_gate.h"

Xor_Gate::Xor_Gate(sc_module_name nm):sc_module(nm){
	
	SC_METHOD(operation);
		sensitive<<a_in<<b_in;
}

Xor_Gate::~Xor_Gate(){}

void Xor_Gate::operation(){
		
		c_out.write( a_in.read() xor b_in.read() );
}


