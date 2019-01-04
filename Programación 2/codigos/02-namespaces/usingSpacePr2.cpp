#include <iostream>

namespace pr2 {

int varA;
float varB;

int incrementarB() {
	return ++varB;
}

}

using namespace pr2;
using namespace std;

int main() {

	int varA;

	varA = 5;
	pr2::varA = 2;
	varB = 9.1;

	cout << "varA = " << varA << endl;
	cout << "varA (pr2) = " << pr2::varA << endl;
	cout << "varB (pr2) = " << varB << endl;

	incrementarB();

	cout << "varB (pr2) = " << varB << endl;

	return 0;

}
