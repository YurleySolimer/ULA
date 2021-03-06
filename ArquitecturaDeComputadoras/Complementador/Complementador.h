#ifndef COMPLEMENTADOR_H
#define COMPLEMENTADOR_H
#include<systemc.h>
#include"Xor_gate.h"

class Complementador : public sc_module{
	
	public:
		sc_in<sc_uint<8> > a_in;
		sc_out<sc_uint<8> > s_out;
		sc_in<bool> ctrl_in;
		int i;

	SC_CTOR(Complementador);
	~Complementador();

	private:
		void split();
		void join();
		sc_signal<bool> x_sg[8], z_sg[8];
		Xor_Gate *xor1[8];
	
};
#endif
