#include <iostream>
#include <string>
#include <cstdlib>
#include "Agenda.h"

using namespace std;

int main() {
	int c;
	int i;
	
	string Nombre="Agenda.txt"; //Se nombra al archivo
	
	Agenda agenda(Nombre);
	Registro r1, r2, *r3;

		r1.nombre="Yurley";
		r1.apellido="Barrios";
		r1.edad=20;
		r1.telefono=123455;
		r1.email="yurleysolimer";

		r2.nombre="Maria";
		r2.apellido="Perez";
		r2.edad=18;
		r2.telefono=654321;
		r2.email="correo_electronico";
		

		agenda.agregar_contacto(r1); //Implementación del método agregar_contacto
		agenda.agregar_contacto(r2);
		
		string cad="_"; //Caracter o cadena de caracteres que se desea buscar en el registro
		agenda.buscar(cad,r3,c); //Implementación del método buscar

		for(i=0; i<c; i++){
			
			//Se muestra en pantalla el registro encontrado

			cout <<r3 [i].nombre<<endl;
			cout <<r3 [i].apellido<<endl;
			cout <<r3 [i].edad<<endl;
			cout <<r3 [i].telefono<<endl;
			cout <<r3 [i].email;

		}	
	return 0;	
}

