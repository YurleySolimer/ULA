#include <fstream>
#include "Agenda.h"

using namespace std;

	Agenda::Agenda(){ 
		//empty   
	}
	
	Agenda::Agenda(string &n){
		Nombre=n; 
	}

	Agenda::~Agenda(){
		//empty  
	}


void Agenda::agregar_contacto(Registro &reg){ // Este método permite agregar, en cualquier parte del archivo, 
									 //un registro del tipo Registro

	open(Nombre.c_str(), ios::out | ios::app); //Apertura del archivo
		(*this) << reg.nombre<<" ";
		(*this) << reg.apellido<<" ";
		(*this) << reg.edad<<" ";
		(*this) << reg.telefono<<" ";
		(*this) << reg.email<<"\n";
	close();
}


void Agenda::buscar(string & cad, Registro *& arr_reg, int & c){ // Este método se encarga de hacer una búsqueda sobre //
													//todos los campos de todos los registros del archivo.

	Registro r;
	open(Nombre.c_str(), ios::in);
		char edad[03];
		char telefono[10];
		string ed;
		string tlf;
		int Tam=0;
		int j=0;

		while(!eof() && (*this) >> r.nombre){ //Se recorre el archivo mientras no sea fin y mientras éste se pueda leer
			(*this) >> r.apellido;
			(*this) >> r.edad;	
			(*this) >> r.telefono;
			(*this) >> r.email;
			
			sprintf(edad, "%d", r.edad);  //Convierte int edad a un string
			ed=edad;

			sprintf(telefono, "%d", r.telefono);  //Convierte int telefono a un string
			tlf=telefono;


			if(r.nombre.find(cad)!=string::npos|| // Se implementa el método find de la clase string para buscar la posicion de un 												 caracter, de no encontrarse devuelve la contante npos
			   r.apellido.find(cad)!=string::npos|| //
			   ed.find(cad)!=string::npos|| //
			   tlf.find(cad)!=string::npos||//
			   r.email.find(cad)!=string::npos) {
			   
			Tam++; } //Número de veces que se encontró el registro
		}

			if (Tam){

				arr_reg=new Registro[Tam]; //Crea un nuevo arreglo en el cual se guardará el registro encontrado
				close();

				open(Nombre.c_str(), ios::in);
					while(!eof() && (*this)>>r.nombre){
						(*this)>>r.apellido;
						(*this)>>r.edad;
						(*this)>>r.telefono;
						(*this)>>r.email;

						if(r.nombre.find(cad)!=string::npos||// 
						r.apellido.find(cad)!=string::npos||//
						ed.find(cad)!=string::npos||//
						tlf.find(cad)!=string::npos||//
						r.email.find(cad)!=string::npos){

							//Guarda en el arreglo el registro encontrado

							arr_reg[j].nombre=r.nombre;
							arr_reg[j].apellido=r.apellido;
							arr_reg[j].edad=r.edad;
							arr_reg[j].telefono=r.telefono;
							arr_reg[j].email=r.email;
							j++;
						}
					}		
			}

			else {

			cout<<"Registro no encontrado"<<endl;

			}	
		
		close();
		c=Tam;
}

