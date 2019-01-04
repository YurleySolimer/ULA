#ifndef XOR_H_
#define XOR_H_
#include<systemc.h>
//Tabla de la verdad para la compuerta Xor

		/****************************
			x | y | z
			__|___|__
			0 | 0 | 0
			0 | 1 | 1
			1 | 0 | 1
			1 | 1 | 0
		****************************/
class Xor:public sc_module{

	public:
		sc_in<bool> x_in,y_in;
		sc_out<bool> z_out;

		SC_CTOR(Xor){
			SC_METHOD(operation);
			sensitive<<x_in<<y_in;
		}


	private:
		void operation(){
			z_out.write(x_in.read() xor y_in.read());
		}

};/*end of class Xor*/



#endif/*end of XOR_H*/
