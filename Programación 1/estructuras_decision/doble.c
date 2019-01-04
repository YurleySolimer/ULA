#include <stdio.h>

int main() {

	int n;

	printf("Ingrese número: ");
	scanf("%d", &n);

	if (n <= 0) {
		printf("El número es menor o igual que cero.\n");
	} else {
		printf("El número es mayor que cero.\n");
	}

	return 0;

}
