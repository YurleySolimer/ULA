#include"Compl.h"
void Compl::operation(){
	if(ctrl_in.read()){
		sc_uint<NBITS> aux=y_in.read();
		for(int i=0;i<NBITS;i++)
		aux[i]=!aux[i];

		z_out.write(aux);
	}
	else
		z_out.write(y_in.read());
}
