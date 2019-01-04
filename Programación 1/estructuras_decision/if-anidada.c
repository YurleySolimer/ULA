#include <stdio.h>

int main() {

	float x, y;

	printf("Ingrese x: ");
	scanf("%f", &x);

	if (x > 0) {

		if (x < 2.5) {
			x *= x;
		}

		y = x + 10;

	}

	printf("y = %.2f\n", y);

	return 0;

}
