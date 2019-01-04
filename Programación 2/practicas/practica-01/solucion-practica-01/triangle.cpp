#include "triangle.h"

Triangle::Triangle() {
	this->pointA = Point();
	this->pointB = Point();
	this->pointC = Point();
}

Triangle::Triangle(const Point &pointA, //
				   const Point &pointB, //
				   const Point &pointC) {
	this->pointA = pointA;
	this->pointB = pointB;
	this->pointC = pointC;
}

Triangle::Triangle(const Triangle &triangle) {
	this->pointA = triangle.pointA;
	this->pointB = triangle.pointB;
	this->pointC = triangle.pointC;
}

Point Triangle::getPointA() {
	return pointA;
}

void Triangle::setPointA(const Point &point) {
	this->pointA = point;
}

Point Triangle::getPointB() {
	return pointB;
}

void Triangle::setPointB(const Point &point) {
	this->pointB = point;
}

Point Triangle::getPointC() {
	return pointC;
}

void Triangle::setPointC(const Point &point) {
	this->pointC = point;
}

double Triangle::perimeter() {
	return pointA.getDistance(pointB) //
			+ pointB.getDistance(pointC) //
			+ pointC.getDistance(pointA);
}

double Triangle::area() {

	double s = perimeter() / 2;
	double a = lengthA();
	double b = lengthB();
	double c = lengthC();

	return sqrt(s * (s - a) * (s - b) * (s - c));

}

double Triangle::areaHeight() {
	return lengthC() * heightC() / 2;
}

double Triangle::lengthA() {
	return pointB.getDistance(pointC);
}

double Triangle::lengthB() {
	return pointC.getDistance(pointA);
}

double Triangle::lengthC() {
	return pointA.getDistance(pointB);
}

double Triangle::heightA() {
	return tao() / lengthA();
}

double Triangle::heightB() {
	return tao() / lengthB();
}

double Triangle::heightC() {
	return tao() / lengthC();
}

double Triangle::tao() {

	double a = lengthA();
	double b = lengthB();
	double c = lengthC();

	return sqrt((a + b - c) * (a - b + c) * (-a + b + c) * (a + b + c)) / 2;

}
