#ifndef SUMADOR_H
#define SUMADOR_H
#include <systemc.h>
#include"Full_Adder.h"

class Sumador : public sc_module{
	
	public:
		sc_in<sc_uint<8> > a_in, b_in;
		sc_out<sc_uint<8> > s_out;
		sc_in<bool> c_in;
		sc_out<bool> c_out;
		int i;

	SC_CTOR(Sumador);
	~Sumador();

	private:
		void split();
		void join();
		sc_signal<bool> x_sg[8], y_sg[8], z_sg[8], c_sg[7];
		Full_Adder *FullAdder[8];
};
#endif
