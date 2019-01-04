#ifndef OR_GATE
#define OR_GATE
#include <systemc.h>

class Or_Gate : public sc_module{
	
	public:
		sc_in<bool> a_in;
		sc_in<bool> b_in;
		sc_out<bool> c_out;

		SC_CTOR(Or_Gate);
		~Or_Gate();
	private:
		void operation();

};

#endif

