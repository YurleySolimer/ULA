#ifndef NOT_H
#define NOT_H
#include<systemc.h>

//Tabla de la verdad para la compuerta or

		/****************************
			x | z
			__|__
			0 | 1
			1 | 0
		****************************/	
class Not:public sc_module{

	public:
		sc_in<bool> x_in;
		sc_out<bool> z_out;
		SC_CTOR(Not){
			SC_METHOD(operation);
			sensitive<<x_in;
	
		}


	private:
		void operation(){
			z_out.write(!x_in.read());
		}

};/*end of class Not*/



#endif/*end of NOT_H*/
