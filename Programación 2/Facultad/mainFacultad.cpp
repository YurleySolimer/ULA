#include "Cadena.h"
#include "archivoTexto.h"
#include"Facultad.h"
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<fstream>
using namespace std;
int main(){
	

	
	Cadena nombreArchivoFacultad("Facultads.txt");
	ArchivoTexto<Facultad> archivoFacultad(nombreArchivoFacultad);

	Facultad f1("ingenieria", "hechicera", 7000, 5500, 333, 6, 7500);
	Facultad f2("ciencias", "hechicera", 4000, 350, 250, 3, 4000);
	Facultad f3("arquitectura", "hechicera", 4500, 360, 500, 3, 5000);
	
	
	
	f1.asignarNombre("ingenieria" );
	
	
	if(archivoFacultad.abrir()){
		archivoFacultad.insertar(f1);
		archivoFacultad.eliminar(f1);
		archivoFacultad.modificar(f1, f2);
		f1.print();
		f2.print();
		
		archivoFacultad.cerrar();
	}
	else{
		cout << "No abrio" << endl;
	}

	





}
