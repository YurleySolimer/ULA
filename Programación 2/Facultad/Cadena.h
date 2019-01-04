#ifndef CADENA_H
#define CADENA_H
#include <iostream>
using namespace std;

class Cadena{
	friend ostream& operator<<(ostream& output, const Cadena& cad);
private:
	char *caracteres;
	int lon;

public:
	//Contructores
	Cadena();
	Cadena(const Cadena&);
	Cadena(const char *);
	~Cadena();

	//Métodos de Acceso
	int longitud();
	char * obtenerCaracteres();

	//Métodos de modificación
	void asignarCaracteres(const char *);
};
#endif
