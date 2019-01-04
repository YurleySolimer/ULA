#ifndef AND_GATE
#define AND_GATE
#include <systemc.h>

class And_Gate : public sc_module{
	
	public:
		sc_in<bool> a_in;
		sc_in<bool> b_in;
		sc_out<bool> c_out;

		
		SC_CTOR(And_Gate);
		~And_Gate();
	private:
		void operation();

};

#endif



