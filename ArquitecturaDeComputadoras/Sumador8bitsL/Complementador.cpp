#include "Complementador.h"

Complementador::Complementador(sc_module_name nm):sc_module(nm){
	SC_METHOD(split);
		sensitive<<b_in;

	SC_METHOD(join);
		sensitive<<z_sg[0]<<z_sg[1]<<z_sg[2]<<z_sg[3]<<z_sg[4]<<z_sg[5]<<z_sg[6]<<z_sg[7];
	

	xorgate[0]=new Xor_Gate("xorgate0");
	xorgate[1]=new Xor_Gate("xorgate1");
	xorgate[2]=new Xor_Gate("xorgate2");
	xorgate[3]=new Xor_Gate("xorgate3");
	xorgate[4]=new Xor_Gate("xorgate4");
	xorgate[5]=new Xor_Gate("xorgate5");
	xorgate[6]=new Xor_Gate("xorgate6");
	xorgate[7]=new Xor_Gate("xorgate7");

	for (i=0; i<8; i++) {
		xorgate[i]->a_in(ctrl_in);
		xorgate[i]->b_in(y_sg[i]);
		xorgate[i]->s_out(z_sg[i]);
	}
}
Complementador::~Complementador(){}

	void Complementador::split(){ //me divide en vectores
		for(i=0; i<8; i++) {
			sc_uint<8> s_aux=b_in.read();
				for(i=0; i<8; i++){
					y_sg[i].write(s_aux[i]);
			}
		}
	}

	void Complementador::join(){
	sc_uint<8> s_aux;
		for(i=0; i<8; i++){
			s_aux[i]=z_sg[i].read();
			}

		s_out.write(s_aux);

	}
