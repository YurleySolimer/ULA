//Yurley Solimer C.I. 22986327

#include <iostream>
#include <string>
#include <stdio.h>

using namespace std;


int transicion(int estado, char c)
{
	if(estado == 1){
		if (c=='a')
			return 5;
		else if (c=='b')
			return 3;
	}

	if(estado == 2){
		if (c=='a')
			return 6;
		else if (c=='b')
			return 1;
		
	}

	if(estado == 3){
		if (c=='a')
			return 8;
		else if (c=='b')
			return 4;
	}

	if(estado == 4){
		if (c=='a')
			return 7;
		else if (c=='b')
			return 1;
	}

	if(estado == 5){
		if (c=='a')
			return 4;
		else if (c=='b')
			return 8;
	}

	if(estado == 6){
		if (c=='a')
			return 4;
		else if (c=='b')
			return 5;
	}

	if(estado == 7){
		if (c=='a')
			return 1;
		else if (c=='b')
			return 5;
	}
	
	if(estado == 8){
		if (c=='a')
			return 2;
		else if (c=='b')
			return 7;
	}

}

bool salida (int estado, char c) 
{
	if(estado==1){
		if (c=='a' || c=='b')
			return 0; 
	}

	if(estado==2){
		if (c=='a')
			return 0; 
		
		else if (c=='b')
			return 1;
	}

	if(estado==3){
		if (c=='a')
			return 0; 
		else if (c=='b')
			return 1;
	}

	if(estado==4){
		if (c=='a')
			return 0; 
		else if (c=='b')
			return 1;
	}

	if(estado==5){
		if (c=='a' || c=='b')
			return 0; 
	}

	if(estado==6){
		if (c=='a')
			return 0; 
		else if (c=='b')
			return 1;
	}

	if(estado==7){
		if (c=='a' || c=='b')
			return 1; 
	}

	if(estado==8){
		if (c=='a' || c=='b')
			return 1; 
	}

}

void imprimir(int estadoF){

		if (estadoF == 1) {
		cout <<"         A            B    "<<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *    )     *     )    *" <<endl;
		cout <<"    *                      *" <<endl;
		cout <<"   *                        *" <<endl;
		cout <<" *                           *" <<endl;
		cout <<"*        *           *        *" <<endl;
		cout <<"*      *   *   )   *   *       *" <<endl;
		cout <<" *       *           *        *" <<endl;
		cout <<"  *                          *" <<endl;
		cout <<"   *           *            *" <<endl;
		cout <<"    *        *   *         *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"          C          D     " <<endl;

	}

	if (estadoF == 2) {
		cout <<"         A          B      "<<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *    )     *     (    *" <<endl;
		cout <<"    *                      *" <<endl;
		cout <<"   *                        *" <<endl;
		cout <<" *                           *" <<endl;
		cout <<"*        *           *        *" <<endl;
		cout <<"*      *   *   )   *   *       *" <<endl;
		cout <<" *       *           *        *" <<endl;
		cout <<"  *                          *" <<endl;
		cout <<"   *           *            *" <<endl;
		cout <<"    *        *   *         *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"          C          D     " <<endl;


	}


	if (estadoF == 3) {
		cout <<"         A          B      "<<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *    )     *     (    *" <<endl;
		cout <<"    *                      *" <<endl;
		cout <<"   *                        *" <<endl;
		cout <<" *                           *" <<endl;
		cout <<"*        *           *        *" <<endl;
		cout <<"*      *   *   (   *   *       *" <<endl;
		cout <<" *       *           *        *" <<endl;
		cout <<"  *                          *" <<endl;
		cout <<"   *           *            *" <<endl;
		cout <<"    *        *   *         *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"          C          D     " <<endl;


	}


  	if (estadoF == 4) {
		cout <<"         A          B      "<<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *    )     *     )    *" <<endl;
		cout <<"    *                      *" <<endl;
		cout <<"   *                        *" <<endl;
		cout <<" *                           *" <<endl;
		cout <<"*        *           *        *" <<endl;
		cout <<"*      *   *   (   *   *       *" <<endl;
		cout <<" *       *           *        *" <<endl;
		cout <<"  *                          *" <<endl;
		cout <<"   *           *            *" <<endl;
		cout <<"    *        *   *         *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"          C          D     " <<endl;


	}

	if (estadoF == 5) {
		cout <<"         A          B      "<<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *    (     *     )    *" <<endl;
		cout <<"    *                      *" <<endl;
		cout <<"   *                        *" <<endl;
		cout <<" *                           *" <<endl;
		cout <<"*        *           *        *" <<endl;
		cout <<"*      *   *   )   *   *       *" <<endl;
		cout <<" *       *           *        *" <<endl;
		cout <<"  *                          *" <<endl;
		cout <<"   *           *            *" <<endl;
		cout <<"    *        *   *         *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"          C          D     " <<endl;


	}

	if (estadoF == 6) {
		cout <<"         A          B      "<<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *    (     *     (    *" <<endl;
		cout <<"    *                      *" <<endl;
		cout <<"   *                        *" <<endl;
		cout <<" *                           *" <<endl;
		cout <<"*        *           *        *" <<endl;
		cout <<"*      *   *   )   *   *       *" <<endl;
		cout <<" *       *           *        *" <<endl;
		cout <<"  *                          *" <<endl;
		cout <<"   *           *            *" <<endl;
		cout <<"    *        *   *         *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"          C          D     " <<endl;


	}


	if (estadoF == 7) {
		cout <<"         A          B      "<<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *    (     *     )    *" <<endl;
		cout <<"    *                      *" <<endl;
		cout <<"   *                        *" <<endl;
		cout <<" *                           *" <<endl;
		cout <<"*        *           *        *" <<endl;
		cout <<"*      *   *   (   *   *       *" <<endl;
		cout <<" *       *           *        *" <<endl;
		cout <<"  *                          *" <<endl;
		cout <<"   *           *            *" <<endl;
		cout <<"    *        *   *         *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"          C          D     " <<endl;


	}

	if (estadoF == 8) {
		cout <<"         A          B      "<<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *        *   *       *" <<endl;
		cout <<"     *    (     *     (    *" <<endl;
		cout <<"    *                      *" <<endl;
		cout <<"   *                        *" <<endl;
		cout <<" *                           *" <<endl;
		cout <<"*        *           *        *" <<endl;
		cout <<"*      *   *   (   *   *       *" <<endl;
		cout <<" *       *           *        *" <<endl;
		cout <<"  *                          *" <<endl;
		cout <<"   *           *            *" <<endl;
		cout <<"    *        *   *         *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"     *       *   *        *" <<endl;
		cout <<"          C          D     " <<endl;


	}
}

int main()
{
	int estadoF = 1;

	while(estadoF!=0) {
  		char s;
  		cout << "Ingrese a / b para jugar, r para reiniciar, s para salir " << endl << endl;
  		imprimir (estadoF);
  		cin >> s;

   		if(s=='r'){
  			cout << "   *****REINICIO******       " << endl;
    		estadoF = 1;
	  	}
  		if (s == 'a' || s == 'b')
  		{
			if(salida(estadoF, s)==1)
    	    	cout << "       ******GANASTE******         " << endl << endl ;
    		if(salida(estadoF, s)==0)
    			cout << "       ******PERDISTE******        " << endl <<endl ;
    		estadoF = transicion(estadoF,s);
    		}
    	if (s == 's')
    	{
    		cout <<"Gracias por jugar. Bye!" << endl << endl;
    		return 0;
    	}

	}

  	return 0;
}