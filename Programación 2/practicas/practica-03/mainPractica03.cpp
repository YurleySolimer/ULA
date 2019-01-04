#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#include <limits.h>
#include "Register.h"
#define NUM_REG 50

using namespace std;




Register searchRegister(ifstream &file, const int &id);

void modifyRegister(fstream &file, const int &id);

int main(int argc, char **argv) {

	if (argc != 2) {
		cerr << endl << "Modo de uso: " << argv[0] << " " << "<nombre_archivo>" << endl;
		return 1;
	}

	string names[] = {"Luisa", "Jose", "Maria", "Juana", "Simon", "Manuel", "Carolina", "Ingrid", "Andres", "Daniela"};

	string lastNames[] = {"Torres", "Perez", "Barrios", "Rodriguez", "Bolivar", "Salcedo", "Mora", "Lopez", "Blanco", "Araujo"};

	srand(time(NULL));

	Register reg;
	ofstream file;
	ifstream file1;
	file.open("archivo.txt");
	int p = 100, comp[50];
	for (int i=0 ; i<=NUM_REG ; i++){	
		int r =  0 + (rand () % 51);	
		int q =  0 + (rand () % 10);
		int s =  0 + (rand () % 10);
		comp[i]= r;
		for (int cont=0 ; cont<=NUM_REG ; cont++){
			//searchRegister("archivo.txt", const int &id);
			
				
			
				while ( r != p){
					file << r <<","<< names[q] <<","<< lastNames[s] <<endl;	
					}
		}
		
	}
	file.close();
	cout <<"Indique el ID que desea buscar";
	int idB;
	cin >> idB;

	cout << endl;
	return 0;

}

Register searchRegister(ifstream &file, const int &id) {

	Register reg;

	//TODO

	return reg;

}

void modifyRegister(fstream &file, const int &id) {

	//TODO

}
