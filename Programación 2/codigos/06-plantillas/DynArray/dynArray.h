/**
 * @file dynArray.h
 * @brief Definición de la Clase DynArray para representar un arreglo dinámico.
 * Se usan plantillas para el tipo de dato que se almacena en el arreglo.
 *
 */

#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <iostream>

using namespace std;

/**
 * @brief Definicion de la clase DynArray.
 */
template <typename T>
class DynArray {

	/** @brief Puntero a los datos que almacena el arreglo. */
	T *data;

	/** @brief Tamaño del arreglo. */
	int size;

public:
	/**
	 * @brief Constructor de DynArray.
	 * Inicializa los datos de la estructura.
	 */
	DynArray();

	/**
	 * @brief Constructor por copia de DynArray.
	 * Inicializa los datos de la estructura a partir de otro DynArray.
	 */
	DynArray(const DynArray<T> &);

	/**
	 * @brief Destructor de DynArray.
	 * Elimina los datos de la estructura.
	 */
	~DynArray();

	/**
	 * @brief Comprobar si el arreglo esta vacio.
	 * @return true si el arreglo esta vacio, false en caso contrario.
	 */
	bool isEmpty();

	/**
	 * @brief Muestra el tamaño y los elementos del arreglo.
	 */
	void print();

	/**
	 * @brief Buscar el subindice del elemento item en el arreglo.
	 * @param item Elemento que se desea buscar.
	 * @return Subindice del elemento item en el arreglo o -1 si el elemento no existe.
	 */
	int search(const T &);

	/**
	 * @brief Contar el numero de ocurrencias del elemento item en el arreglo.
	 * @param item Elemento que se desea contar.
	 * @return Numero de ocurrencias del elemento item en el arreglo.
	 */
	int countOccurrences(const T &);

	/**
	 * @brief Insertar el elemento item al final del arreglo.
	 * @param item Elemento que se desea insertar.
	 */
	void insert(const T &);

	/**
	 * @brief Insertar el elemento item al inicio del arreglo.
	 * @param item Elemento que se desea insertar.
	 */
	void append(const T &);

	/**
	 * @brief Eliminar el elemento item del arreglo.
	 * @param item Elemento que se desea eliminar.
	 */
	void remove(const T &);

	/**
	 * @brief Eliminar el elemento en la posicion i del arreglo.
	 * @param array
	 * @param i Subindice del elemento que se desea eliminar.
	 */
	void removeAt(const int &);

	/**
	 * @brief Eliminar todos los elementos del arreglo.
	 * @param array
	 */
	void empty();

};

#endif // DYNARRAY

