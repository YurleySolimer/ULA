#include"Facultad.h"
#include<fstream>
using namespace std;
/* Implantacion de  los metodos de la clase 
 * Facultad*/


//Constructor por omision
Facultad::Facultad(){ 
	//Valores asignados por omision
	strcpy(nombre, "Ninguna");
	strcpy(direccion,"Ninguno");
	estudiantes=0;
	profesores=0;
	salones=0;
	escuelas=0;
	empleados=0;
	
}
//Constructor por copia
Facultad::Facultad(const Facultad &f){
	strcpy(nombre, f.nombre);
	strcpy(direccion, f.direccion);
	estudiantes=f.estudiantes;
	profesores= f.profesores;
	salones= f.salones;
	escuelas = f.escuelas;
	empleados = f.empleados;
	
}
//Constructor parametrico
Facultad::Facultad(const char _nom[],const 
char _dir[], const short &_est, const short &_prof,
const short &_sal, const short &_escs, const short &_emp){
	strcpy(nombre, _nom);
	strcpy(direccion, _dir);
	estudiantes=_est;
	profesores= _prof;
	salones= _sal;
	escuelas = _escs;
	empleados = _emp;
	
}

/*Métodos de acceso*/
char* Facultad:: obtenerNombre() {
	return nombre; }


char* Facultad:: obtenerDireccion() { 
	return direccion ;} 

short Facultad:: obtenerEstudiantes() {
	return estudiantes; }

short Facultad:: obtenerProfesores() {
	return profesores; }

short Facultad:: obtenerSalones() {
	return salones; }

short Facultad:: obtenerEscuelas() {
	return escuelas; }

short Facultad:: obtenerEmpleados() {
	return empleados; }

char* Facultad:: obtenerClave() {
	return nombre; }


/*Métodos de Modificación*/
void Facultad:: asignarNombre(const char _nom[]){
	strcpy(nombre, _nom);
}
void Facultad:: asignarDireccion(const char _dir[]){
	strcpy(direccion, _dir);
}
void Facultad:: asignarEstudiantes(const short& _est){
	estudiantes=_est;
}
void Facultad:: asignarProfesores(const short&  _prof){
	profesores= _prof;
}
void Facultad:: asignarSalones(const short&  _sal){
	salones= _sal;
}
void Facultad:: asignarEscuelas(const short& _escs){
	escuelas=_escs;
}
void Facultad:: asignarEmpleados(const short& _emp){
	empleados=_emp;
}
void Facultad:: asignarClave(const char _cla[]){
	strcpy(nombre, _cla);
}

/*Métodos para leer imprimir y asignar*/
void  Facultad:: scan(){
	cout<<"Introduzca la nombre de la Facultad: ";
	cin>>nombre;
	cout<<"Introduzca la direccion de la Facultad ";
	cin>>direccion;
	cout<<"Introduzca el numero de estudiantes ";
	cin>>estudiantes;
	cout<<"Introduzca el numero de profesores";
	cin>>profesores;
	cout<<"Introduzca el numero de salones de la Facultad ";
	cin>>salones;
	cout<<"Introduzca el numero de escuelas de la Facultad ";
	cin>>escuelas;
	cout<<"Introduzca el numero de empleados ";
	cin>>empleados;
}
//Metodo para mostrar los valores de los atributos
void Facultad::print(){
	cout<<"nombre: "<<nombre<<endl;
	cout<<"direccion: "<<direccion<<endl;
	cout<<"estudiantes: "<<estudiantes<<endl;
	cout<<"profesores: "<<profesores<<endl;
	cout<<"salones: "<<salones<<endl;
	cout<<"escuelas: "<<escuelas<<endl;
	cout<<"empleados: "<<empleados<<endl;
}

//Metodo para mostrar los valores de los atributos
void Facultad::print2(){
	cout<<nombre<< ":" <<direccion<< ":" 
	<<estudiantes <<":"<<profesores <<":"<<salones
	<<":"<<escuelas <<":"<<empleados
	<<endl;
}


//Destructor 
Facultad::~Facultad(){
/*Vacio*/	
}

//Sobre carga de operadores de escritura y 
//lectura de archivos
ostream &operator<<(ostream &file, const Facultad &f) {
	file << f.nombre << ":" << f.direccion << ":"
	     << f.estudiantes << ":" << f.profesores << ":"
	     << f.salones << ":" << f.escuelas << ":"
	     << f.empleados << endl ;
	return (file);
}

istream &operator>>(istream &file, Facultad &f) {
	char linea[300];
	int estudiantes, profesores, salones, escuelas, empleados;
	char nombre[20], direccion[100];

	file >> linea;
	sustituirCaracter(linea, ':');
	sscanf(linea, "%s %s %d %d %d %d %d",
		nombre,
		direccion,
		&estudiantes,
		&profesores,
		&salones,		
		&escuelas,
		&empleados);
	f.asignarNombre(nombre);
	f.asignarDireccion(direccion);
	f.asignarEstudiantes(estudiantes);
	f.asignarProfesores(profesores);
	f.asignarSalones(salones);
	f.asignarEscuelas(escuelas);
	f.asignarEmpleados(empleados);

	return (file);
}

// Funcion de auxiliar

void sustituirCaracter(char *cadena, char caracter){
	int i=0;
	while( cadena[i] != '\0'){
		if(cadena[i] == ':'){
			cadena[i] = ' ';
		}
		i++;
	}
}

bool Facultad::buscarFacultad(){
	ifstream file;
	Facultad f;
	file.open("Facultads.txt");
	while ( ! file.eof() ){
		file >> f;
		if(strcpy(this->nombre, f.nombre)){
			strcpy(this->direccion, f.direccion);
			this->estudiantes = f.estudiantes;
			this->profesores = f.profesores;
			this->salones= f.salones;
			this->escuelas= f.escuelas;
			this->empleados = f.empleados;
			return true;
		}
	}
	return false;
}

bool Facultad::eliminarFacultad(){
	bool eliminado = false;
	if ( this->buscarFacultad() ){
		ifstream file1;
		ofstream file2;
		Facultad f;
		file1.open("Facultads.txt");
		file2.open("temporal.txt", ios::app);
		while ( ! file1.eof() ){
			file1 >> f;
			if(this->nombre != f.nombre){
				file2 << f;
			}
			else{
				eliminado = true;
			}
		}
		file1.close();
		file2.close();
		remove("Facultads.txt");
        	rename("temporal.txt","Facultads.txt");
	}
	if( eliminado ){
		return true;
	}
	else{
		return false;
	}
}
