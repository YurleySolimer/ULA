/**
 * @file fibonacci.c
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

#include <stdio.h>

int fibonacci(int n);

int main() {

	int n, i;

	printf("\n\tIntroduza valor limite de la sucesion de Fibonacci: ");
	scanf("%d", &n);

	printf("\n\tSucesion de Fibonacci, hasta f(%d): \n\t", n);

	for (i = 0; i <= n; i++) {
		printf("%d ", fibonacci(i));
	}

	printf("\n\n");

	return 0;

}

int fibonacci(int n) {

	int i, j, t, k;

	i = 1;
	j = 0;

	for (k = 0; k < n; k++) {
		t = i + j;
		i = j;
		j = t;
	}

	return j;

}
