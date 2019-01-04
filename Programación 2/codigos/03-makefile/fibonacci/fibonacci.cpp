/**
 * @file fibonacci.cpp
 * @brief Programa para calcular un número de la Sucesión de Fibonacci.
 *
 * Algoritmo iterativo:
 * función fibonacci(n)
 *   i = 1
 *   j = 0
 *   para k desde 0 hasta n - 1 hacer
 *     t = i + j
 *     i = j
 *     j = t
 *   fin para
 *   devuelve j
 * fin función
 *
 */

#include "fibonacci.h"

using namespace std;

int main() {

	int n;

	cout << "\n\tIntroduza valor limite de la sucesion de Fibonacci: ";
	cin >> n;

	cout << "\n\tSucesion de Fibonacci, hasta f(" << n << "): \n\t";

	for (int i = 0; i <= n; i++) {
		cout << fibonacci(i) << " " ;
	}

	cout << endl << endl;

	return 0;

}

