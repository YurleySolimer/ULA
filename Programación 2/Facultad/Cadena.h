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

	//M�todos de Acceso
	int longitud();
	char * obtenerCaracteres();

	//M�todos de modificaci�n
	void asignarCaracteres(const char *);
};
#endif
