#ifndef FULLADDER
#define FULLADDER
#include <and_gate.h>
#include <or_gate.h>
#include <xor_gate.h>
#include <systemc.h>


class Full_Adder : public sc_module{

	public:
		sc_in<bool> a_in, b_in, c_in;
		sc_out<bool> c_out, s_out;

		SC_CTOR(Full_Adder);
		~Full_Adder(){};

	private:
 		And_Gate *and0, *and1;
		Or_Gate *or0;
		Xor_Gate *xor0, *xor1;

	sc_signal<bool> sg_1, sg_2, sg_3;
 };

#endif
