#include <iostream>
#include <iostream>
#include <fstream>
#include "Persona.h"

using namespace std;


int main(int argc, char **argv) {

	string Nombre="Registro.txt"; 
	Persona persona(Nombre);
	Register r1;
	//int id=9;

	string name[]={"Luisa", "Jose", "Maria", "Juana", "Simon", "Manuel", "Carolina", "Ingrid", "Andres", "Daniela"};
	string lastName[]={"Torres", "Perez", "Barrios", "Rodriguez", "Bolivar", "Salcedo", "Mora", "Lopez", "Blanco", "Araujo"};

	persona.aggRegister(name, lastName);

	
	return 0;

}

