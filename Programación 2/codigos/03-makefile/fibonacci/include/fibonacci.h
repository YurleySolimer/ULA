#include <iostream>

int fibonacci(int n) {

	int i, j, t;

	i = 1;
	j = 0;

	for (int k = 0; k < n; k++) {
		t = i + j;
		i = j;
		j = t;
	}

	return j;

}
