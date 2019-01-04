#include"Carro.h"
#include<fstream>
using namespace std;
/* Implantacion de  los metodos de la clase 
 * Carro*/


//Constructor por omision
Carro::Carro(){ 
	//Valores asignados por omision
	strcpy(marca, "Ninguna");
	strcpy(modelo,"Ninguno");
	puertas=0;
	strcpy(placa,"Ninguna");
	strcpy(color,"Ninguno");
	year=0;
	ncilindros=0;
	
}
//Constructor por copia
Carro::Carro(const Carro& c){
	strcpy(marca, c.marca);
	strcpy(modelo, c.modelo);
	puertas=c.puertas;
	strcpy(placa, c.placa);
	strcpy(color, c.color);
	year = c.year;
	ncilindros = c.ncilindros;
	
}
//Constructor parametrico
Carro::Carro(const char _marc[],const 
char _mod[], const short _prts, const char _plac[],
const char _colr[], const short _year, const short _ncl){
	strcpy(marca, _marc);
	strcpy(modelo, _mod);
	puertas=_prts;
	strcpy(placa, _plac);
	strcpy(color, _colr);
	year = _year;
	ncilindros = _ncl;
	
}

/*Métodos de acceso*/
char* Carro:: obtenerMarca() {
	return marca; }


char* Carro:: obtenerModelo() { 
	return modelo ;} 

short Carro:: obtenerPuertas() {
	return puertas; }

char* Carro:: obtenerPlaca() {
	return placa; }

char* Carro:: obtenerColor() {
	return color; }

short Carro:: obtenerYear() {
	return year; }

short Carro:: obtenerNCilindros() {
	return ncilindros; }
char* Carro:: obtenerClave() {
	return placa; }


/*Métodos de Modificación*/
void Carro:: asignarMarca(const char _marc[]){
	strcpy(marca, _marc);
}
void Carro:: asignarModelo(const char _mod[]){
	strcpy(modelo, _mod);
}
void Carro:: asignarPuertas(const short& _prts){
	puertas=_prts;
}
void Carro:: asignarPlaca(const char  _plac[]){
	strcpy(placa, _plac);
}
void Carro:: asignarColor(const char  _colr[]){
	strcpy(color, _colr);
}
void Carro:: asignarYear(const short& _year){
	year=_year;
}
void Carro:: asignarNCilindros(const short& _ncl){
	ncilindros=_ncl;
}
void Carro:: asignarClave(const char clave[]){
	strcpy(placa, clave);
}

/*Métodos para leer imprimir y asignar*/
void  Carro:: scan(){
	cout<<"Introduzca la marca del carro: ";
	cin>>marca;
	cout<<"Introduzca el modelo del carro ";
	cin>>modelo;
	cout<<"Introduzca el numero de puertas ";
	cin>>puertas;
	cout<<"Introduzca la placa del carro ";
	cin>>placa;
	cout<<"Introduzca el color del carro ";
	cin>>color;
	cout<<"Introduzca el año del carro ";
	cin>>year;
	cout<<"Introduzca el numero de cilindros ";
	cin>>ncilindros;
}
//Metodo para mostrar los valores de los atributos
void Carro::print(){
	cout<<"Marca: "<<marca<<endl;
	cout<<"Modelo: "<<modelo<<endl;
	cout<<"Puertas: "<<puertas<<endl;
	cout<<"Placa: "<<placa<<endl;
	cout<<"Color: "<<color<<endl;
	cout<<"Año: "<<year<<endl;
	cout<<"Numero de Cilindros: "<<ncilindros<<endl;
}

//Metodo para mostrar los valores de los atributos
void Carro::print2(){
	cout<<marca<< ":" <<modelo<< ":" 
	<<puertas <<":"<<placa <<":"<<color
	<<":"<<year <<":"<<ncilindros
	<<endl;
}


//Destructor 
Carro::~Carro(){
/*Vacio*/	
}

//Sobre carga de operadores de escritura y 
//lectura de archivos
ostream &operator<<(ostream &file, const Carro &c) {
	file << c.marca << ":" << c.modelo << ":"
	     << c.puertas << ":" << c.placa << ":"
	     << c.color << ":" << c.year << ":"
	     << c.ncilindros << endl ;
	return (file);
}

istream &operator>>(istream &file, Carro &c) {
	char linea[300];
	int puertas, year, ncilindros;
	char marca[20], modelo[20], placa[12], color[10];

	file >> linea;
	sustituirCaracter(linea, ':');
	sscanf(linea, "%s %s %d %d %s %s %d",
		marca,
		modelo,
		&puertas,
		&year,
		color,
		placa,
		&ncilindros);
	c.asignarMarca(marca);
	c.asignarModelo(modelo);
	c.asignarPuertas(puertas);
	c.asignarPlaca(placa);
	c.asignarColor(color);
	c.asignarYear(year);
	c.asignarNCilindros(ncilindros);

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

bool Carro::buscarCarro(){
	ifstream file;
	Carro c;
	file.open("carros.txt");
	while ( ! file.eof() ){
		file >> c;
		if(this->placa == c.placa){
			strcpy(this->marca, c.marca);
			strcpy(this->modelo, c.modelo);
			this->puertas = c.puertas;
			strcpy(this->color, c.color);
			this->year= c.year;
			this->ncilindros = c.ncilindros;
			return true;
		}
	}
	return false;
}

bool Carro::eliminarCarro(){
	bool eliminado = false;
	if ( this->buscarCarro() ){
		ifstream file1;
		ofstream file2;
		Carro c;
		file1.open("carros.txt");
		file2.open("temporal.txt", ios::app);
		while ( ! file1.eof() ){
			file1 >> c;
			if(this->placa != c.placa){
				file2 << c;
			}
			else{
				eliminado = true;
			}
		}
		file1.close();
		file2.close();
		remove("carros.txt");
        	rename("temporal.txt","carros.txt");
	}
	if( eliminado ){
		return true;
	}
	else{
		return false;
	}
}
