#include <iostream>

namespace pr2 {

int varA;
float varB;

int incrementarB() {
	return ++varB;
}

}

int main() {

	int varA;

	varA = 5;
	pr2::varA = 2;

	std::cout << "varA = " << varA << std::endl;
	std::cout << "varA (pr2) = " << pr2::varA << std::endl;

	return 0;

}
