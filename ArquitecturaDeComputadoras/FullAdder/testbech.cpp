/**@file compuertas.h
*@brief Definición de los métodos para realizar las pruebas del FullAdder
*@author Ronald Sulbarán
*@mail ronalanto03@hotmail.com
@date 17/5/2011
*/

#include"testbech.h"
void testbech::test(){
	//imprimo el formato
	
	cout<<endl<<"\tx=primer operando"<<endl;
	cout<<endl<<"\ty=segundo operando"<<endl;
	cout<<endl<<"\tz=resultado"<<endl;
	cout<<endl<<"\tci=acarreo de entrada"<<endl;
	cout<<endl<<"\tco=acarreo de salida"<<endl;	
	cout<<endl<<endl<<"\t\tx\ty\tci\tz\tco"<<endl;
	cout<<"\t\t----------------------------------"<<endl<<endl;
	//inicio de pruebas
	x_out.write(0);
	y_out.write(0);
	c_out.write(0);
	wait();

	this->print_result();



	x_out.write(1);
	y_out.write(0);
	c_out.write(0);
	wait();

	this->print_result();



	x_out.write(0);
	y_out.write(1);
	c_out.write(0);
	wait();

	this->print_result();


	x_out.write(1);
	y_out.write(1);
	c_out.write(0);
	wait();

	this->print_result();



	x_out.write(0);
	y_out.write(1);
	c_out.write(1);
	wait();

	this->print_result();



	x_out.write(1);
	y_out.write(0);
	c_out.write(1);
	wait();

	this->print_result();



	x_out.write(1);
	y_out.write(1);
	c_out.write(1);
	wait();

	this->print_result();


	//fin de la simulacion

	cout<<endl<<endl;
	sc_stop();
}



void testbech::print_result(){
	cout<<"\t\t"<<x_out.read()<<\
		"\t"<<y_out.read()<<\
		"\t"<<c_out.read()<<\
		"\t"<<z_in.read()<<\
		"\t"<<c_in.read()<<\
		"\t"<<endl;

	cout<<"\t\t----------------------------------"<<endl;
}
