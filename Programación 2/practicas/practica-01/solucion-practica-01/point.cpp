/**
 * @file point.cpp
 * @brief Implementación de la clase Point, que representa un punto en el plano cartesiano.
 */

#include "point.h"

Point::Point() : x(0), y(0) {
	/* empty */
}

Point::Point(const double &cx, const double &cy) : x(cx), y(cy) {
	/* empty */
}

Point::Point(const Point &point) : x(point.x), y(point.y) {
	/* empty */
}

bool Point::operator == (const Point &point) {
	return x == point.x && y == point.y;
}

bool Point::operator != (const Point &point) {
	return !(*this == point);
}

Point Point::operator + (const Point &point) {
	return Point(x + point.x, y + point.y);
}

Point &Point::operator += (const Point &point) {
	x += point.x;
	y += point.y;

	return *this;
}

Point Point::operator - (const Point &point) {
	return Point(x - point.x, y - point.y);
}

Point &Point::operator -= (const Point &point) {
	x -= point.x;
	y -= point.y;

	return *this;
}

const double &Point::getX() const {
	return x;
}

void Point::setX(const double &x) {
	this->x = x;
}

const double &Point::getY() const {
	return y;
}

void Point::setY(const double &y) {
	this->y = y;
}

const double Point::getDistance(const double &cx, const double &cy) {
	return sqrt(pow(cx - this->x, 2.0) + pow(cy - this->y, 2.0));
}

const double Point::getDistance(const Point &point) {
	return this->getDistance(point.getX(), point.getY());
}
