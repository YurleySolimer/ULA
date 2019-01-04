/**@file Compl.h
*@brief Modulo complementador de NBITS bits usando NBITS compuertas xor modelado en systemc
*@author Ronald Sulbarán
@date 12/6/2011
*/

#ifndef COMPL_H
#define COMPL_H
#include<systemc.h>
#include"compuertas.h"
#include<string>
#define NBITS 2//al cambiar el valor del macro el complementador puede tener mas o menos capacidad
using namespace std;
class Compl:public sc_module{
	public:
		sc_in<sc_uint<NBITS> > y_in;
		sc_in<bool> ctrl_in;
		sc_out<sc_uint<NBITS> > z_out;

		SC_CTOR(Compl){
			SC_METHOD(split);
				sensitive<<y_in<<ctrl_in;

			SC_METHOD(join);
				for(int i=0;i<NBITS;i++)
					sensitive<<z[i];

			
			string name;
			char *num;
			for(int i=0;i<NBITS;i++){
				num=new char;		
				sprintf(num,"%d",i+1);			
				name="Xor";
				name+=num;
				xor1[i]=new Xor(name.c_str());
				delete num;

				xor1[i]->x_in(x[i]);
				xor1[i]->y_in(ctrl_in);
				xor1[i]->z_out(z[i]);
				
				
			}


		}

	~Compl();
	private:
		void split();
		void join();
		Xor *xor1[NBITS];
		sc_signal<bool> x[NBITS],z[NBITS];

};
#else 
#warning "Hay una definicion previa de COMPL_H"

#endif
