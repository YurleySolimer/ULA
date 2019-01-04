#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#include <limits.h>

#define NUM_REG 50

using namespace std;

struct TRegister {
	int id;
	string name;
	string lastName;
};

typedef struct TRegister Register;

ostream & operator<<(ostream &out, const Register &reg) {
	return out << reg.id << "," //
			   << reg.name << "," //
			   << reg.lastName;
}

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

	//TODO

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