/**@file Adder2Bits.h
*@brief Sumador de 2 bits modelado en systemc
*@author Ronald Sulbarán
@date 11/6/2011
*/

#ifndef ADDER2BITS_H
#define ADDER2BITS_H

#include"FullAdder.h"
typedef sc_uint<2> uint2;
class Adder2Bits:public sc_module{
	public:
	sc_in<uint2> x_in,y_in;
	sc_in<bool> c_in;
	sc_out<uint2> z_out;
	sc_out<bool> c_out;
	
	SC_CTOR(Adder2Bits){
	SC_METHOD(split);
	sensitive<<x_in<<y_in<<c_in;
	SC_METHOD(join);
	sensitive<<z[0]<<z[1];
	SC_METHOD(check_carry);
	sensitive<<c[2];
	adder[0]= new FullAdder("adder12");
	adder[1]=new FullAdder("adder22");
	

	for(int i=0;i<2;i++){
		adder[i]->x_in(x[i]);
		adder[i]->y_in(y[i]);
		adder[i]->z_out(z[i]);
		adder[i]->c_in(c[i]);
		adder[i]->c_out(c[i+1]);
}

	
	

}

	private:
	FullAdder * adder[2];
	sc_signal<bool> x[2],y[2],z[2],c[3];
	void split();
	void check_carry();
	void join();



};

#endif
