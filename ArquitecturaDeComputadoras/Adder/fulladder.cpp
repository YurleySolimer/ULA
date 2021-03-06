#include "fulladder.h"

Full_Adder::Full_Adder(sc_module_name nm):sc_module(nm){

	and0 = new And_Gate("and0");
	and1 = new And_Gate("and1");
	or0 = new Or_Gate("or0");
	xor0 = new Xor_Gate("xor0");
	xor1 = new Xor_Gate("xor1");

	and0->a_in(c_in);
	and0->b_in(sg_1);
	and0->c_out(sg_2);

	and1->a_in(b_in);
	and1->b_in(a_in);
	and1->c_out(sg_3);

	or0->a_in(sg_2);
	or0->b_in(sg_3);
	or0->c_out(c_out);

	xor0->a_in(a_in);
	xor0->b_in(b_in);
	xor0->c_out(sg_1);

	xor1->a_in(sg_1);
	xor1->b_in(c_in);
	xor1->c_out(s_out);

	
	
}
