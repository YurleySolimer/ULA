#ifndef BUFFER
#define BUFFER
#include <systemc.h>
#include "restador.h"

class Buffer : public sc_module{
	
	public:
		
		sc_in<sc_lv<8> > z_in;
		sc_in<sc_lv<8> > c_in;
		sc_out<sc_uint<8> > s_out;
		

	SC_CTOR(Buffer);
	~Buffer();
	private:
		void comprobar();

};

#endif
