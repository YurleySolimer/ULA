#include"Restador.h"	


Restador::Restador(sc_module_name nm):sc_module(nm){
	
	
	sumador=new Sumador("sumador");
	
	
	complementador=new Complementador("complementador");
	
	
		sumador->a_in(a_in);
		sumador->c_in(c_in);
		sumador->b_in(y_sg);
		sumador->c_out(c_out);
		sumador->s_out(s_out);

		complementador->b_in(b_in);
		complementador->s_out(y_sg);
		complementador->ctrl_in(c_in);

	}

Restador::~Restador(){}



