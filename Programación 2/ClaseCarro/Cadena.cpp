#include "Cadena.h"
#include <string.h>
//Constructores
Cadena::Cadena(){
	lon = 0;
}
Cadena::Cadena(const Cadena& cad){
	int i;
	lon = cad.lon;
	caracteres = new char [lon];
	for(i=0; i<lon; i++)
		caracteres[i] = cad.caracteres[i];
	caracteres[lon] = '\0';
}
Cadena::Cadena(const char *c){
	int i;
	lon = strlen(c);
	caracteres = new char [lon];
	for(i=0; i<lon; i++)
		caracteres[i] = c[i];
	caracteres[lon] = '\0';
}
Cadena::~Cadena(){
}

//Métodos de Acceso
int Cadena::longitud(){
	return lon;
}
char * Cadena::obtenerCaracteres(){
	return caracteres;
}

//Métodos de modificación
void Cadena::asignarCaracteres(const char *c){
}

//Sobrecarga de operadores
ostream& operator<<(ostream& output, const Cadena& cad){
	int i;
	for(i=0; i<cad.lon; i++)
		cout << cad.caracteres[i];
	cout << endl;
}
