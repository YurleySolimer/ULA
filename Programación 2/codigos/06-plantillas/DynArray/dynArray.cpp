/**
 * @file dynArray.cpp
 * @brief Implementación de la Clase DynArray para representar un arreglo dinámico.
 * Se usan plantillas para el tipo de dato que se almacena en el arreglo.

 */

#include "dynArray.h"

template <typename T>
DynArray<T>::DynArray() {
	data = NULL;
	size = 0;
}

template <typename T>
DynArray<T>::DynArray(const DynArray<T> &array) {
	data = array.data;
	size = array.size;
}

template <typename T>
DynArray<T>::~DynArray() {
	empty();
}

template <typename T>
bool DynArray<T>::isEmpty() {
	return size == 0;
}

template <typename T>
void DynArray<T>::print() {

	if (isEmpty()) {
		cout << endl << "El arreglo esta vacio." << endl;
		return;
	}

	cout << endl << "Tamaño del arreglo = " << size << endl;

	for (int i = 0; i < size; i++) {
		cout << data[i];
		if (i < size - 1) {
			cout << ", ";
		}
	}

	cout << endl;

}

template <typename T>
int DynArray<T>::search(const T &item) {

	if (isEmpty()) {
		return -1;
	}

	int idx = -1;

	for (int i = 0; i < size; i++) {
		if (this->data[i] == item) {
			idx = i + 1;
			break;
		}
	}

	return idx;

}

template <typename T>
int DynArray<T>::countOccurrences(const T &item) {

	if (isEmpty()) {
		return 0;
	}

	int occurrences = 0;

	for (int i = 0; i < size; i++) {
		if (this->data[i] == item) {
			occurrences++;
		}
	}

	return occurrences;

}

template <typename T>
void DynArray<T>::insert(const T &item) {

	T *aux = new T[size + 1];

	for (int i = 0; i < size; i++) {
		aux[i] = this->data[i];
	}

	aux[size] = item;
	size++;
	delete [] this->data;
	this->data = aux;
	aux = NULL;
	delete aux;

}

template <typename T>
void DynArray<T>::append(const T &item) {

	T *aux = new T[size + 1];

	aux[0] = item;

	for (int i = 0; i < size; i++) {
		aux[i + 1] = this->data[i];
	}

	size++;
	delete [] this->data;
	this->data = aux;
	aux = NULL;
	delete aux;

}

template <typename T>
void DynArray<T>::remove(const T &item) {

	if (isEmpty()) {
		cout << endl << "El arreglo esta vacio." << endl;
		return;
	}

	int reps = countOccurrences(item);

	if (reps == 0) {
		cout << endl << "El elemento no existe." << endl;
		return;
	}

	T *aux = new T[size - reps];

	for (int i = 0, j = 0; i < size; i++) {
		if (this->data[i] == item) {
			continue;
		}
		aux[j++] = this->data[i];
	}

	size -= reps;
	delete [] this->data;
	this->data = aux;
	aux = NULL;
	delete aux;

}

template <typename T>
void DynArray<T>::removeAt(const int &i) {

	if (isEmpty()) {
		cout << endl << "El arreglo esta vacio." << endl;
		return;
	}

	remove(this->data[i - 1]);

}

template <typename T>
void DynArray<T>::empty() {

	if (isEmpty()) {
		return;
	}

	delete [] data;
	size = 0;

}
