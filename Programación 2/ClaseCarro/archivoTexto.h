#include <fstream>
#include "Cadena.h"

template <class Objeto>
class ArchivoTexto {
protected:
	Cadena nombre;
	int tamano;
	Cadena tipo;
	Cadena directorio;
	int lineas;
	fstream desc;


public:
	//Constructores
	ArchivoTexto(const Cadena);
	ArchivoTexto(const Cadena, const Cadena);
	ArchivoTexto(const Cadena, const int,
		     const Cadena, const Cadena,
		     const int);
	ArchivoTexto(const ArchivoTexto&);

	//Metodos de Acceso
	Cadena Nombre();
	int Tamano();
	Cadena Tipo();
	Cadena Directorio();
	int Lineas();

	//Metodos de Modificacion
	void Nombre(const Cadena&);
	void Tamano(const int&);
	void Tipo(const Cadena&);
	void Directorio(const Cadena&);
	void Lineas(const int&);

	//Metodos de gestion de archivos
	bool abrir();
	bool cerrar();

	//Metodos de gestion de registros
	Objeto leer();
	bool insertar(Objeto);
	//bool modificarObjeto(Objeto);
	//bool eliminarObjeto(Objeto);
	bool buscar(Objeto *);
};

//Constructores
template <class Objeto>
ArchivoTexto<Objeto>::ArchivoTexto(const Cadena nom){
	Cadena dir("");
	nombre = nom;
	directorio = dir;
}

template <class Objeto>
ArchivoTexto<Objeto>::ArchivoTexto(const Cadena nom, const Cadena dir){
	nombre = nom;
	directorio = dir;
}

template <class Objeto>
ArchivoTexto<Objeto>::ArchivoTexto(const Cadena n, const int tam,
	     const Cadena tip, const Cadena dir,
	     const int lins){
	nombre = n;
	tamano = tam;
	tipo = tip;
	directorio = dir;
	lineas = lins;
}

template <class Objeto>
ArchivoTexto<Objeto>::ArchivoTexto(const ArchivoTexto& arch){
	nombre = arch.nombre;
	tamano = arch.tamano;
	tipo = arch.tipo;
	directorio = arch.directorio;
	lineas = arch.lineas;
}

//Metodos de Acceso
template <class Objeto>
Cadena ArchivoTexto<Objeto>::Nombre(){
	return nombre;
}
template <class Objeto>
int ArchivoTexto<Objeto>::Tamano(){
	return tamano;
}
template <class Objeto>
Cadena ArchivoTexto<Objeto>::Tipo(){
	return tipo;
}
template <class Objeto>
Cadena ArchivoTexto<Objeto>::Directorio(){
	return directorio;
}
template <class Objeto>
int ArchivoTexto<Objeto>::Lineas(){
	return lineas;
}

//Metodos de Modificacion
template <class Objeto>
void ArchivoTexto<Objeto>::Nombre(const Cadena& cad){
	nombre = cad;
}
template <class Objeto>
void ArchivoTexto<Objeto>::Tamano(const int& tam){
	tamano = tam;
}
template <class Objeto>
void ArchivoTexto<Objeto>::Tipo(const Cadena& tip){
	tipo = tip;
}
template <class Objeto>
void ArchivoTexto<Objeto>::Directorio(const Cadena& dir){
	directorio = dir;
}
template <class Objeto>
void ArchivoTexto<Objeto>::Lineas(const int& lin){
	lineas = lin;
}

//Metodos de gestion de archivos
template <class Objeto>
bool ArchivoTexto<Objeto>::abrir(){
	desc.open(nombre.obtenerCaracteres(), fstream::in | fstream::out | fstream::app);
	if( !desc )
		return false;
	else
		return true;
}

template <class Objeto>
bool ArchivoTexto<Objeto>::cerrar(){
	desc.close();
}

template <class Objeto>
Objeto ArchivoTexto<Objeto>::leer(){
	Objeto obj;
	desc >> obj;
	return obj;
}


template <class Objeto>
bool ArchivoTexto<Objeto>::insertar(Objeto o){
	desc << o;
	return true;
}

template <class Objeto>
bool ArchivoTexto<Objeto>::buscar(Objeto *obj){
	bool encontrado = false;
	Objeto aux;
	aux.asignarClave(obj->obtenerClave());
	while ( ! desc.eof() && !encontrado){
		desc >> *obj;
		if(obj->obtenerClave() == aux.obtenerClave()){
			return true;
		}
	}
	return false;
}

