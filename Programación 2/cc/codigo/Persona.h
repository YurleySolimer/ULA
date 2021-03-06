#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#include <limits.h>

#define NUM_REG 50
#ifndef PERSONA_H
#define PERSONA_H

using namespace std;

struct TRegister {
	int id;
	string name;
	string lastName;
};

typedef struct TRegister Register;

class Persona {

	protected:
		fstream desc;

	private: 
		string Nombre;
		string name[];
		string lastN[];

	public:

		Persona();
		Persona(string &n); 
		~Persona();
		
		bool openRegister();
		bool closeRegister();
		void aggRegister(string name[]);
		//Register searchRegister(ifstream &file, const int &id);
		//void modifyRegister(fstream &file, const int &id);

		friend ostream & operator<<(ostream &file, const Register &reg);


};

#endif 

