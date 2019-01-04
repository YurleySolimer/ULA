#ifndef CARRO_H
#define CARRO_H
#include<iostream>
#include<string.h>

using namespace std;
class Carro {
	//Definicion de atributos de la clase Carro
 	
	
	private:
		char marca[15];
		char modelo[15];
		short puertas;
		char placa[12];
		char color[10];
		short year;
		short ncilindros;
		
	public:
	//Métodos de la clase Carro
	
	//Constructores
	Carro();		  //Por omisión
	Carro(const Carro& ); 	  //Por copia
	Carro(const char[],	  //Parametrico
		const char[],
		const short &,
		const char[],
		const char[],
		const short &,
		const short &);
			
	//Metodos de acceso
	char* obtenerMarca();
	char* obtenerModelo();
	short obtenerPuertas();
	char* obtenerPlaca();
	char* obtenerColor();
	short obtenerYear();
	short obtenerNCilindros();
	char* obtenerClave();

	//Metodos de modificacion
	void asignarMarca(const char []);
	void asignarModelo(const char []);
	void asignarPuertas(const short&);
	void asignarPlaca(const char []);
	void asignarColor(const char []);
	void asignarYear(const short&);
	void asignarNCilindros(const short&);
	void asignarClave(const char[]);
	
	
	//Metodos de lectura escritura y asignacion
	void scan();
	void print();
	void print2();

	//Destructor
	~Carro();
	
	//Sobrecarga de operadores
	friend ostream &operator<<(ostream &, const Carro &);
	friend istream &operator>>(istream &, Carro &);

	//Busqueda dentro de un archivo
	bool buscarCarro();
	bool eliminarCarro();
};

// Funcion auxiliar
void sustituirCaracter(char *, char );
#endif
