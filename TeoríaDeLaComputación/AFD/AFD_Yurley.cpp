//Yurley Solimer C.I. 22986327

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


int transicion(int estado, char c)
{
	if(estado==0){
		if (c=='a')
			return 1;
		else if (c=='b')
			return 2;
	}

	if(estado==1){
		if (c=='a')
			return 3;
		else if (c=='b')
			return 4;

	}

	if(estado==2){
		if (c=='a')
			return 2;
		else if (c=='b')
			return 2;
	}

	
	
	if(estado==4){
		if (c=='a')
			return 1;
		else if (c=='b')
			return 4;
	}

}

int transicionE(int estado, string s)
{

  if (s.empty() == true)
    return estado;

  else
    return transicion(transicionE(estado, s.substr(0,s.length()-1)), s[s.length()-1]);
}

int main()
{

  string s;
  int estadoF = 0;

  cout << "AFD que reconoce cadenas generadas a partir a,b , donde si empieza por a no contiene ";
  cout << "la subcadena aa y si empieza por b contiene la subcadena aa" << endl;
  cout << endl;

  cout << "Estado inicial: " << 0 << endl;
  cout << "Inserte la cadena a evaluar: ";
  getline (cin, s);

  estadoF = transicionE(0,s);

  if(estadoF == 1 || estadoF == 2 || estadoF == 4)
    {
      cout << "Estado de aceptacion: " << estadoF << endl;
      cout << "La cadena  '" << s << "'  SI esta en el lenguaje" << endl;
    }
  else
    cout << "La cadena  '" << s  << "'  NO esta en el lenguaje" << endl;
  cout << endl;

  return 0;
}