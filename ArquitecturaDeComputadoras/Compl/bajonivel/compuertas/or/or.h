#ifndef OR_H
#define OR_H
#include<systemc.h>

//Tabla de la verdad para la compuerta or

		/****************************
			x | y | z
			__|___|__
			0 | 0 | 0
			0 | 1 | 1
			1 | 0 | 1
			1 | 1 | 1
		****************************/	
class Or:public sc_module{

	public:
		sc_in<bool> x_in,y_in;
		sc_out<bool> z_out;
		SC_CTOR(Or){
			SC_METHOD(operation);
			sensitive<<x_in<<y_in;
	
		}


	private:
		void operation(){
			z_out.write(x_in.read() | y_in.read());
		}

};/*end of class Or*/



#endif/*end of OR_H*/
