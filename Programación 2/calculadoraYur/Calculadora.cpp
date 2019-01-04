#include "Calculadora.h"

using namespace std;

	template <class T>
	Calculadora<T>::Calculadora(){
	a=0;
	b=0;
	c=0;
	r1=0;
	r2=0;
}
	template <class T>	
	Calculadora<T>::Calculadora(const Calculadora &c){}
	
	template <class T>
	Calculadora<T>::Calculadora(T a, T b, T c){}


	template <class T>
	T Calculadora<T>::get_a(){
	return a;
		
	}
	template <class T>
	void Calculadora<T>::set_a(T a1){
	a=a1;	
	}
	
	template <class T>
	T Calculadora<T>::get_b(){
	return b;	
	}
	
	template <class T>
	void Calculadora<T>::set_b(T b1){
	b=b1;
	}

	template <class T>
	T Calculadora<T>::get_c(){
	return c;
	}
	
	template <class T>
	void Calculadora<T>::set_c(T c1){
	c=c1;
	}


	template <class T>
	void Calculadora<T>::leer_datos(){
	cout<<"Introduzca a: "<<endl;
	cin>>a;	

	cout<<"Introduzca b: "<<endl;
	cin>>b;

	cout<<"Introduzca c: "<<endl;
	cin>>c;
	}	
	

	template <class T>	
	void Calculadora<T>::suma(){	
	r1=a+b;
	}

	template <class T>
	void Calculadora<T>::resta(){
	r1=a-b;	
	}

	template <class T>
	void Calculadora<T>::division(){
	r1=a/b;
	}

	template <class T>
	void Calculadora<T>::multiplicacion(){
	r1=a*b;
}
	template <class T>
	void Calculadora<T>::raices(){
	T k, l;

	l=(b*b)-4*a*c;
	k=-b + sqrt(l);
	

	if (l>=0 && a!=0)
		r1=k/2*a;

	k=-b - sqrt(l);

	if (l>=0 && a!=0)
		r2=k/2*a;

	}

	template <class T>
	void Calculadora<T>::mostrar_R1(){
	cout<<r1<<endl;
	}

	template <class T>
	void Calculadora<T>::mostrar_R2(){
	cout<<r2<<endl;
	}


	template <class T>
	Calculadora<T>::~Calculadora(){}

