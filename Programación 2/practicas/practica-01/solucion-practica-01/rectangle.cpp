#include "rectangle.h"

Rectangle::Rectangle() {
	this->pointA = Point();
	this->pointB = Point();
	this->pointC = Point();
	this->pointD = Point();
}

Rectangle::Rectangle(const Point &pointA, const Point &pointB, //
					 const Point &pointC, const Point &pointD) {
	this->pointA = pointA;
	this->pointB = pointB;
	this->pointC = pointC;
	this->pointD = pointD;
}

Rectangle::Rectangle(const Rectangle &rectangle) {
	this->pointA = rectangle.pointA;
	this->pointB = rectangle.pointB;
	this->pointC = rectangle.pointC;
	this->pointD = rectangle.pointD;
}

Point Rectangle::getPointA() {
	return pointA;
}

void Rectangle::setPointA(const Point &point) {
	this->pointA = point;
}

Point Rectangle::getPointB() {
	return pointB;
}

void Rectangle::setPointB(const Point &point) {
	this->pointB = point;
}

Point Rectangle::getPointC() {
	return pointC;
}

void Rectangle::setPointC(const Point &point) {
	this->pointC = point;
}

Point Rectangle::getPointD() {
	return pointD;
}

void Rectangle::setPointD(const Point &point) {
	this->pointD = point;
}

double Rectangle::perimeter() {
	return 2 * (pointA.getDistance(pointB) + pointA.getDistance(pointD));
}

double Rectangle::diagonal() {
	return sqrt(pow(pointA.getDistance(pointB), 2) + pow(pointA.getDistance(pointD), 2));
}

double Rectangle::area() {
	return pointA.getDistance(pointB) * pointA.getDistance(pointD);
}
