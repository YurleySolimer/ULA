#include <stdio.h>

int main() {

	int n;

	printf("Ingrese número: ");
	scanf("%d", &n);

	if (n == 0) {
		printf("El número es igual a cero.\n");
	}

	if (n > 0) {
		printf("El número es mayor que cero.\n");
	}

	if (n < 0) {
		printf("El número es menor que cero.\n");
	}

	return 0;

}
