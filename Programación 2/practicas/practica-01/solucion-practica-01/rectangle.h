#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "geometricFigure.h"

class Rectangle : public GeometricFigure {

	Point pointA;
	Point pointB;
	Point pointC;
	Point pointD;

public:
	Rectangle();
	Rectangle(const Point &pointA, const Point &pointB, //
			  const Point &pointC, const Point &pointD);
	Rectangle(const Rectangle &rectangle);

	Point getPointA();
	void setPointA(const Point &point);

	Point getPointB();
	void setPointB(const Point &point);

	Point getPointC();
	void setPointC(const Point &point);

	Point getPointD();
	void setPointD(const Point &point);

	double perimeter();
	double diagonal();
	double area();

};

#endif // RECTANGLE_H
