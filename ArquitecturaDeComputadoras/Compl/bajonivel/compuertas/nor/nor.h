#ifndef NOR_H
#define NOR_H
#include<systemc.h>
//Tabla de la verdad para la compuerta nor

		/****************************
			x | y | z
			__|___|__
			0 | 0 | 1
			0 | 1 | 0
			1 | 0 | 0
			1 | 1 | 0
		****************************/

class Nor:public sc_module{
	public:
		sc_in<bool> x_in,y_in;
		sc_out<bool> z_out;
		SC_CTOR(Nor){
			SC_METHOD(operation);
				sensitive<<x_in<<y_in;
	
		}

	private:
		void operation(){
			z_out.write(!(x_in.read() | y_in.read()));
		}

};/*end of class Nor*/


#endif/*end of NOR_H*/
