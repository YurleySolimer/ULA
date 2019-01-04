#ifndef NAND_H_
#define NAND_H_
#include<systemc.h>

//Tabla de la verdad para la compuerta Nand 
		/****************************
			x | y | z
			__|___|__
			0 | 0 | 1
			0 | 1 | 1
			1 | 0 | 1
			1 | 1 | 0
		****************************/
	
class Nand:public sc_module{
	public:
		sc_in<bool> a_in,b_in;
		sc_out<bool> nand_out;
		SC_CTOR(Nand){
			SC_METHOD(operation);
			sensitive<<a_in<<b_in;
	
		}

	private:
		void operation(){
			nand_out.write(!(a_in.read() & b_in.read()));
		}
};/*end of class Nor*/


#endif/*end of NAND_H*/
