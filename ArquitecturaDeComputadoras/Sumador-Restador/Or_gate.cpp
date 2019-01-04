#include "Or_gate.h"

Or_Gate::Or_Gate(sc_module_name nm):sc_module(nm){
	
	SC_METHOD(operation);
		sensitive<<a_in<<b_in;
}
Or_Gate::~Or_Gate(){}
void Or_Gate::operation(){
		
		c_out.write( a_in.read() or b_in.read() );
}


