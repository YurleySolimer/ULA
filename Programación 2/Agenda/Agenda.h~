#ifndef AGENDA_H
#define AGENDA_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct TRegistro { //Declaración del Registro
	string nombre;
	string apellido;
	int edad;
	int telefono;
	string email;

};

typedef struct TRegistro Registro; //Se definición del tipo Registro


class Agenda : public fstream {

	private: 
		string Nombre;

	public:

		Agenda(); //Constructor por omision
		Agenda(string &n); //Constructor por copia

		~Agenda(); //Destructor

	
		void agregar_contacto(Registro & reg);
		void buscar(string & cad, Registro *& arr_reg, int & c);
};

#endif
