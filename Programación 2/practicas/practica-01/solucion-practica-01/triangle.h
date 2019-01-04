#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "geometricFigure.h"

class Triangle : public GeometricFigure {

	Point pointA;
	Point pointB;
	Point pointC;

public:
	Triangle();
	Triangle(const Point &pointA, //
			 const Point &pointB, //
			 const Point &pointC);
	Triangle(const Triangle &triangle);

	Point getPointA();
	void setPointA(const Point &point);

	Point getPointB();
	void setPointB(const Point &point);

	Point getPointC();
	void setPointC(const Point &point);

	double perimeter();
	double area();
	double areaHeight();

private:
	double lengthA();
	double lengthB();
	double lengthC();
	double heightA();
	double heightB();
	double heightC();
	double tao();

};

#endif // TRIANGLE_H
