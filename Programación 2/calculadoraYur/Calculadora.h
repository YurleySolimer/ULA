#ifndef CALCULADORA_H
#define CALCULADORA_H

#include <iostream>
#include <math.h>
using namespace std;

template <class T>

class Calculadora { 

	private:
	T a;
	T b;
	T c;
	T r1;
	T r2;

	public:
	
	Calculadora();
	Calculadora(const Calculadora &c);
	Calculadora(T a, T b, T c);

	T get_a();
	void set_a(T a1);

	T get_b();
	void set_b(T b1);

	T get_c();
	void set_c(T c1);


	void leer_datos();	
	void suma();
	void resta();
	void division();
	void multiplicacion();
	void raices();
	void mostrar_R1();
	void mostrar_R2();

	~Calculadora();


};

#endif 


