#include <iostream>

#include "triangle.h"
#include "rectangle.h"

using namespace std;

int main(int argc, char *argv[]) {

	Point prA(0, 0);
	Point prB(4, 0);
	Point prC(4, 3);
	Point prD(0, 3);

	Rectangle rectangle(prA, prB, prC, prD);

	Point ptA(3, 4);
	Point ptB(7, 5);
	Point ptC(5, 9);

	Triangle triangle(ptA, ptB, ptC);

	cout << endl << "Perímetro del rectángulo = " //
		 << rectangle.perimeter() //
		 << endl << "Área del rectángulo = " //
		 << rectangle.area() //
		 << endl << "Diagonal del rectángulo = " //
		 << rectangle.diagonal() << endl;

	cout << endl << "Perímetro del triángulo = " //
		 << triangle.perimeter() //
		 << endl << "Área del triángulo (por perímetro) = " //
		 << triangle.area() //
		 << endl << "Área del triángulo (por la altura) = " //
		 << triangle.areaHeight() << endl;

	cout << endl;
	return 0;

}
