#include <iostream>

#include "dynArray.cpp"

using namespace std;

int main() {

	DynArray<int> array;

	for (int i = 0; i < 10; i++) {
		array.insert(i + 1);
	}

	array.print();

	array.remove(5);
	array.print();

	array.insert(4);
	array.insert(4);
	array.insert(4);
	array.insert(9);

	array.print();

	cout << endl << "Subindice de 3 = " << array.search(3) << endl;

	array.remove(4);
	array.print();

	array.append(15);
	array.append(22);
	array.append(25);
	array.print();

	array.removeAt(3);
	array.print();

	array.removeAt(3);
	array.print();

	array.empty();

	cout << endl;
	return 0;

}
