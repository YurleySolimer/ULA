#include"Complementador.h"	

Complementador::Complementador(sc_module_name nm):sc_module(nm){
	SC_METHOD(split);
		sensitive<<a_in<<ctrl_in;

	SC_METHOD(join);
		sensitive<<z_sg[0]<<z_sg[1]<<z_sg[2]<<z_sg[3]<<z_sg[4]<<z_sg[5]<<z_sg[6]<<z_sg[7];

				
		xor1[0]=new Xor_Gate("Xor1");
		xor1[1]=new Xor_Gate("Xor2");
		xor1[2]=new Xor_Gate("Xor3");
		xor1[3]=new Xor_Gate("Xor4");
		xor1[4]=new Xor_Gate("Xor5");
		xor1[5]=new Xor_Gate("Xor6");
		xor1[6]=new Xor_Gate("Xor7");
		xor1[7]=new Xor_Gate("Xor8");

		for (i=0; i<8; i++) {

				xor1[i]->a_in(x_sg[i]);
				xor1[i]->b_in(ctrl_in);
				xor1[i]->s_out(z_sg[i]); }

	
	}

Complementador::~Complementador(){ }
void Complementador::split(){
		
	for(i=0; i<8; i++) {
		sc_uint<8> s_aux=a_in.read();
	for(int i=0;i<8;i++)
		x_sg[i].write(s_aux[i]);
	}
}

void Complementador::join(){

	sc_uint<8> s_aux;
	for(i=0; i<8; i++) {
		s_aux[i]=z_sg[i].read();
	}


	s_out.write(s_aux);
}


