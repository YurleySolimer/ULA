/**
 * @file calcular_angulo.c
 * @brief Este programa calcula un ángulo de un triangulo, conocidos los otros dos ángulos
 *

 */

#include <stdio.h>

int main() {

	float alpha, gamma, beta;

	printf("Ingrese alpha: ");
	scanf("%f", &alpha);

	printf("Ingrese gamma: ");
	scanf("%f", &gamma);

	beta = 180 - (gamma + alpha);

	printf("El resultado es %.0f\n", beta);

	return 0;

}
