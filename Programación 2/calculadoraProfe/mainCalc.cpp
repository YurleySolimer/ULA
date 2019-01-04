#include <iostream>
#include<math.h>
using namespace std;

class Raices{
	private:
		
	public:
		float r1;
		float r2;
		Raices();
		void mostrar_raices();
		friend ostream& operator<<(ostream& output, const Raices& r);
};
Raices::Raices()
{
}
void Raices::mostrar_raices(){
	cout << "Raiz 1: " << r1 << endl;
	cout << "Raiz 2: " << r2 << endl;
}
ostream& operator<<(ostream& output, const Raices& r){
		cout << "Raiz 1: " << r.r1 << endl << "Raiz 2: " << r.r2 << endl;
}

class Calculadora{

	private:

	public:
		Calculadora();
		Raices calc_raices(float, float, float);
};
Calculadora::Calculadora(){
}
Raices Calculadora::calc_raices(float a,float b,float c){
		Raices R;
			R.r1 = (-b+sqrt(b*b-4*a*c))/(2*a);
			R.r2 = (-b-sqrt(b*b-4*a*c))/(2*a);
		return (R);	
}
int main(){
	Raices r;
	Calculadora C;
	
	r=C.calc_raices(1,-1,-2);
	r.mostrar_raices();
	cout << r;

}

