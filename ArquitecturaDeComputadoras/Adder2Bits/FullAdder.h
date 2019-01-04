/**@file FullAdder.h
*@brief Sumador completo modelado en systemc
*@author Ronald Sulbarán
*@mail ronalanto03@hotmail.com
@date 11/6/2011
*/


#ifndef FULLADDER_H
#define FULLADDER_H
#include<systemc.h>
#include"compuertas.h"
class FullAdder:public sc_module{
	public:
		sc_in<bool> x_in,y_in,c_in;
		sc_out<bool> z_out,c_out;

		SC_CTOR(FullAdder){
		xor1=new Xor("xor1");
		xor2=new Xor("xor2");

		and1=new And("and1");
		and2=new And("and2");
		and3=new And("and3");


		or1=new Or("or1");
		or2=new Or("or2");



		xor1->x_in(x_in);
		xor1->y_in(y_in);
		xor1->z_out(xor1_to_xor2);

		xor2->x_in(xor1_to_xor2);
		xor2->y_in(c_in);
		xor2->z_out(z_out);
	
		and1->x_in(x_in);
		and1->y_in(y_in);
		and1->z_out(and1_to_or1);


		and2->x_in(x_in);
		and2->y_in(c_in);
		and2->z_out(and2_to_or1);

		and3->x_in(y_in);
		and3->y_in(c_in);
		and3->z_out(and3_to_or2);

		or1->x_in(and1_to_or1);
		or1->y_in(and2_to_or1);
		or1->z_out(or1_to_or2);

		or2->x_in(or1_to_or2);
		or2->y_in(and3_to_or2);
		or2->z_out(c_out);

}

~FullAdder(){

	delete xor1;
	delete xor2;
	delete and1;
	delete and2;
	delete and3;
	delete or1;
	delete or2;

}

	private:

		Xor *xor1,*xor2;
		And * and1,*and2,*and3;
		Or *or1,*or2;
		sc_signal<bool> or1_to_or2;
		sc_signal<bool> xor1_to_xor2;
		sc_signal<bool> and1_to_or1;
		sc_signal<bool> and2_to_or1;
		sc_signal<bool> and3_to_or2;
};
#else 
#warning "Hay una definicion previa de FULLADDER_H"

#endif
