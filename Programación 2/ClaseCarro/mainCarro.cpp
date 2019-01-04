#include "Cadena.h"
#include "archivoTexto.h"
#include"Carro.h"
#include<stdio.h>
#include<iostream>
#include<fstream>
using namespace std;
int main(){
	

	
	Cadena nombreArchivoCarro("carros.txt");
	ArchivoTexto<Carro> archivoCarro(nombreArchivoCarro);

	Carro aveo("aveo", "gghh", 4, "Cgdyg", "Rojo", 2000, 2);
	if(archivoCarro.abrir()){
		archivoCarro.insertar(aveo);
		archivoCarro.cerrar();
	}
	else{
		cout << "No abrio" << endl;
	}

	Carro car;
	car.asignarPlaca("fh4h" );

	if(archivoCarro.abrir()){
		archivoCarro.buscar(&car);
		car.print();
		archivoCarro.cerrar();
	}
	else{
		cout << "No abrio" << endl;
	}



	return 0;
}
