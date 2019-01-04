#include"Sumador.h"	

Sumador::Sumador(sc_module_name nm):sc_module(nm){
	SC_METHOD(split);
		sensitive<<a_in<<b_in;

	SC_METHOD(join);
		sensitive<<z_sg[0]<<z_sg[1]<<z_sg[2]<<z_sg[3]<<z_sg[4]<<z_sg[5]<<z_sg[6]<<z_sg[7];

	
	FullAdder[0]=new Full_Adder("FullAdder0");
	FullAdder[1]=new Full_Adder("FullAdder1");
	FullAdder[2]=new Full_Adder("FullAdder2");
	FullAdder[3]=new Full_Adder("FullAdder3");
	FullAdder[4]=new Full_Adder("FullAdder4");
	FullAdder[5]=new Full_Adder("FullAdder5");
	FullAdder[6]=new Full_Adder("FullAdder6");
	FullAdder[7]=new Full_Adder("FullAdder7");
	
	for (i=0; i<8; i++) {
		FullAdder[i]->a_in(x_sg[i]);
		FullAdder[i]->b_in(y_sg[i]);
		FullAdder[i]->s_out(z_sg[i]);
	}

	FullAdder[0]->c_in(c_in);
	
	for (i=0; i<7; i++) {
		FullAdder[i+1]->c_in(c_sg[i]);
		FullAdder[i]->c_out(c_sg[i]);
	}

	FullAdder[7]->c_out(c_out);
}

Sumador::~Sumador(){ }
void Sumador::split(){
		
	for(i=0; i<8; i++) {
		x_sg[i].write(a_in.read().range(i,i));
		y_sg[i].write(b_in.read().range(i,i));
	}
}

void Sumador::join(){

	sc_uint<8> s_aux;
	for(i=0; i<8; i++) {
		s_aux[i]=z_sg[i].read();
	}


	s_out.write(s_aux);
}


