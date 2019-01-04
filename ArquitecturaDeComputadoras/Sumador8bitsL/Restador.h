#ifndef RESTADOR_H
#define RESTADOR_H
#include <systemc.h>
#include "Sumador.h"
#include "Complementador.h"

class Restador : public sc_module{

	public:
		sc_in<sc_uint<8> > a_in, b_in;
		sc_out<sc_uint<8> > s_out;
		sc_in<bool> c_in;
		sc_out<bool> c_out;
		

	SC_CTOR(Restador);
	~Restador();

	private:
		
		sc_signal<sc_uint<8> > y_sg;
		Sumador *sumador;
		Complementador *complementador;
};
#endif
