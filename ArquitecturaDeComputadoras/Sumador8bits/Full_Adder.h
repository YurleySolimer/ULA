#ifndef FULLADER_H
#define FULLADER_H
#include<systemc.h>
#include "and_gate.h"
#include "Or_gate.h"
#include "Xor_gate.h"

class Full_Adder: public sc_module {

	public: 
	sc_in<bool> a_in,b_in,c_in;
	sc_out<bool> s_out, c_out;

	SC_CTOR(Full_Adder);
	~Full_Adder();

	private:
	And_Gate *and0, *and1;
	Or_Gate *or0;
	Xor_Gate *xor0, *xor1;

	sc_signal<bool> sg_1;
	sc_signal<bool> sg_2;
	sc_signal<bool> sg_3;

};
#endif

