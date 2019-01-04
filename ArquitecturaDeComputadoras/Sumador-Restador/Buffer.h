#ifndef BUFFER_H
#define BUFFER_H

class Buffer: public sc_module{
	
	public: 
	sc_in<sc_uint<8> > a_in, c_in;
	sc_out<sc_lv<8> > s_out; 

	SC_CTOR(Buffer);
	~Buffer();

	private: 
	void Comprobador;

};

#endif


