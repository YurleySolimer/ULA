#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <string.h>
#include <limits.h>
#include "Persona.h"

using namespace std;


	Persona::Persona(){}
	Persona::Persona(string &n){
		Nombre=n; 
	} 
	Persona::~Persona(){}

	bool Persona::openRegister(){
		if( !desc )
			return false;
		else
			return true;
	}


	bool Persona::closeRegister(){
		desc.close();
	}

	void Persona::aggRegister(string name[], string lastN[]){

	fstream file;
	Register reg;
	srand(time(NULL));
	int i;
	int j;
	int r;
	Persona p;
	file.open(Nombre.c_str(), ios::out | ios::app); //Apertura del archivo
		for (i=0; i<=50; i++) {
				
				reg.id=i;
			
				r = 0 + rand () % ( 9 + 1) ; 
				j = 0 + rand () % ( 9 + 1) ;
				
				reg.name=name[r];
				reg.lastName=lastN[j];

				file<<reg.id<<",";
				file<<reg.name<<",";
				file<<reg.lastName;
				file<<"\n";
		}
		
	file.close();
	
} 

	Register Persona::searchRegister(ifstream &file, const int &id){

		Register reg;
		string sr;
		file.open(Nombre.c_str(), ios::in);
	
		while(!file.eof() && file >> reg.id){ 
			file >> reg.name;
			file >> reg.id;
		
			if(id==reg.id) {
			
				cout<<reg.id<<",";
				cout<<reg.name<<",";
				cout<<reg.lastName<<"\n";
			}

		}

		file.close();
	}



	void Persona::modifyRegister(fstream &file, const int &id){
		Register reg;
		ofstream aux;
		string auxName;
		string auxLast;

		aux.open("Auxiliar.txt", ios::out);
		file.open(Nombre.c_str(), ios::in);

			while(!file.eof() && file){ 
						
				if(id==reg.id) {
					aux<<reg.id<<",";
					aux<<auxName<<",";
					aux<<auxLast;
			}

		}

		

		file.close();
	}

		
		


	ostream & operator<<(ostream &file, const Register &reg) {
	file << reg.id << "," //
			   << reg.name << "," //
			   << reg.lastName<<","<<endl;
	return(file);
	}

	

