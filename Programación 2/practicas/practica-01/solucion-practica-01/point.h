/**
 * @file point.h
 * @brief Definición de la clase Point, que representa un punto en el plano cartesiano.
 */

#ifndef POINT_H
#define POINT_H

#include <cmath>

/**
 * @brief Representa un punto en el plano cartesiano.
 */
class Point {

	/** @brief Coordenada x del punto en el plano */
	double x;

	/** @brief Coordenada y del punto en el plano */
	double y;

public:
	/** @brief Constructor por omisión */
	Point();

	/**
	 * @brief Constructor paramétrico.
	 * @param cx Valor de la coordenada x
	 * @param cy Valor de la coordenada y
	 */
	Point(const double &cx, const double &cy);

	/**
	 * @brief Constructor por copia.
	 * @param point Punto a partir del cual se copia la información
	 */
	Point(const Point &point);


	/** @brief Compara dos puntos retorna verdadero si son iguales */
	bool operator == (const Point &point);

	/** @brief Compara dos puntos retorna verdadero si son distintos */
	bool operator != (const Point &point);


	/** @brief Suma de puntos.
	 * Se define como la suma de cada una de sus coordenadas */
	Point operator + (const Point &point);

	/** @brief Suma de puntos.
	 * Se define como la suma de cada una de sus coordenadas */
	Point &operator += (const Point &point);


	/** @brief Resta de puntos.
	 * Para invertir resultado de la suma */
	Point operator - (const Point &point);

	/** @brief Resta de puntos.
	 * Para invertir resultado de la suma */
	Point &operator -= (const Point &point);


	/** @brief Retorna el valor de la coordenada x */
	const double &getX() const;

	/** @brief Asigna el valor de la coordenada x */
	void setX(const double &x);


	/** @brief Retorna el valor de la coordenada y */
	const double &getY() const;

	/** @brief Asigna el valor de la coordenada y */
	void setY(const double &y);


	/** @brief Retorna la distancia euclidiana entre dos puntos */
	const double getDistance(const double &cx, const double &cy);

	/** @brief Retorna la distancia euclidiana entre dos punto */
	const double getDistance(const Point &point);

};

#endif // POINT_H
