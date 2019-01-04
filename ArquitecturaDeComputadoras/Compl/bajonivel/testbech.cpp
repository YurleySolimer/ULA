/**@file compuertas.h
*@brief Definición de los métodos para realizar las pruebas del Complementador
*@author Ronald Sulbarán
@date 17/5/2011
*/

#include"testbech.h"
void testbech::test(){
	//imprimo el formato
	cout<<endl<<endl<<"\t\t  y\tctrl\tz"<<endl;
	cout<<"\t\t---------------------"<<endl<<endl;
	//inicio de pruebas
	ctrl_out.write(1);
	y_out.write(0x0);//00
	wait();

	this->print_values();



	ctrl_out.write(1);
	y_out.write(0x1);//01
	wait();

	this->print_values();


	ctrl_out.write(1);
	y_out.write(0x2);//10
	wait();

	this->print_values();

	ctrl_out.write(1);
	y_out.write(0x3);//11
	wait();

	this->print_values();



	//fin de la simulacion

	cout<<endl<<endl;
	sc_stop();
}



void testbech::print_values(){
	cout<<"\t\t"<<sc_int<2>(y_out.read()).to_string(SC_BIN)<<\
		"\t"<<ctrl_out.read()<<\
		"\t"<<sc_int<2>(z_in.read()).to_string(SC_BIN)<<\
		endl;
	cout<<"\t\t---------------------"<<endl;
}
