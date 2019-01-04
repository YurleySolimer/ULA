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

	string name[]={"M", "I", "L", "E", "M", "A", "E", "S", "T", "U", "Y", "Y", "O"};
	//string lastName[]={"Torres", "Perez", "Barrios", "Rodriguez", "Bolivar", "Salcedo", "Mora", "Lopez", "Blanco", "Araujo"};

	persona.aggRegister(name);

	
	return 0;

}

