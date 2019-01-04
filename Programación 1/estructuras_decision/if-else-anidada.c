#include <stdio.h>

int main() {

	float nota;

	printf("Ingrese nota: ");
	scanf("%f", &nota);

	if ((nota >= 0) && (nota <= 20)) {

		if (nota < 9.5) {
			printf("Está reprobado.\n");
		} else if (nota >= 16) {
			printf("Está eximido.\n");
		} else {
			printf("Está aprobado.\n");
		}

	} else {
		printf("Error en la nota.\n");
	}

	return 0;

}
