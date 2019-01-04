#ifndef FACULTAD_H
#define FACULTAD_H
#include<iostream>
#include<string.h>

using namespace std;
class Facultad {
	//Definicion de atributos de la clase Facultad
 	
	
	private:
		char nombre[20];
		char direccion[20];
		short estudiantes;
		short profesores;
		short salones;
		short escuelas;
		short empleados;
		
	public:
	//Métodos de la clase Facultad
	
	//Constructores
	Facultad();		  //Por omisión
	Facultad(const Facultad&); 	  //Por copia
	Facultad(const char[],	  //Parametrico
		const char[],
		const short &,
		const short &,
		const short &,
		const short &,
		const short &);
			
	//Metodos de acceso
	char* obtenerNombre();
	char* obtenerDireccion();
	short obtenerEstudiantes();
	short obtenerProfesores();
	short obtenerSalones();
	short obtenerEscuelas();
	short obtenerEmpleados();
	char* obtenerClave();

	//Metodos de modificacion
	void asignarNombre(const char []);
	void asignarDireccion(const char []);
	void asignarEstudiantes(const short&);
	void asignarProfesores(const short&);
	void asignarSalones(const short&);
	void asignarEscuelas(const short&);
	void asignarEmpleados(const short&);
	void asignarClave(const char[]);
	
	
	//Metodos de lectura escritura y asignacion
	void scan();
	void print();
	void print2();

	//Destructor
	~Facultad();
	
	//Sobrecarga de operadores
	friend ostream &operator<<(ostream &, const Facultad &);
	friend istream &operator>>(istream &, Facultad &);

	//Busqueda dentro de un archivo
	bool buscarFacultad();
	bool eliminarFacultad();
};

// Funcion auxiliar
void sustituirCaracter(char *, char );
#endif
