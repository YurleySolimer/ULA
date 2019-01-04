/**@file Compl.h
*@brief Modulo complementador a 1 de NBITS(2) modelado en alto nivel en systemc
*@author Ronald Sulbarán
@date 12/6/2011
*/


#ifndef COMPL_H
#define COMPL_H
#define NBITS 2//al cambiar el valor del macro, el complementador puede tener mas o menos capacidad
#include<systemc.h>

class Compl:public sc_module{
	public:
		sc_in<sc_uint<NBITS> > y_in;
		sc_in<bool> ctrl_in;
		sc_out<sc_uint<NBITS> > z_out;

		SC_CTOR(Compl){
			SC_METHOD(operation);
				sensitive<<y_in<<ctrl_in;

		}

		~Compl(){}
	private:
		void operation();
};
#endif
