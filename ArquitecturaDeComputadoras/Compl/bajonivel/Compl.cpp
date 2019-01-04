#include"Compl.h"

Compl::~Compl(){
	for(int i=0;i<NBITS;i++)
		delete xor1[i];
}


void Compl::split(){
	sc_uint<NBITS> aux=y_in.read();
	for(int i=0;i<NBITS;i++)
		x[i].write(aux[i]);
}


void Compl::join(){
	sc_uint<NBITS> aux=y_in.read();
	for(int i=0;i<NBITS;i++)
		aux[i]=z[i].read();
	z_out.write(aux);
}

