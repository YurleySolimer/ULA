#ifndef XOR_GATE
#define XOR_GATE
#include <systemc.h>

class Xor_Gate : public sc_module{
	
	public:
		sc_in<bool> a_in;
		sc_in<bool> b_in;
		sc_out<bool> c_out;

		
		SC_CTOR(Xor_Gate);
		~Xor_Gate();
	private:
		void operation();

};

#endif
