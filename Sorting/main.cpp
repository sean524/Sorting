#include <iostream>
#include <fstream>
#include <string>
#include "SelectionSort.cpp"
#include "Quicksort.cpp"

using namespace std;

bool isSorted(int*, int);

int main() {
	int choice1;
	cout << "1. values.txt\n2. halfmillion.txt\nSelect the file to sort (number only): ";
	cin >> choice1;
	ifstream input;
	if (choice1 == 1) {
		input.open("values.txt");
	}
	else if (choice1 == 2) {
		input.open("halfmillion.txt");
	}

	int length;
	input >> length;
	int* values;
	values = new int[length];
	int i = 0;
	while (!input.eof()) {
		input >> values[i];
		i++;
	}
	input.close();

	int choice2;
	cout << "1. isSorted\n2. SelectionSort\n3. Quicksort\nChoice (number only): ";
	cin >> choice2;
	if (choice2 == 1) {
		cout << "\nisSorted:\n";
		if (isSorted(values, length))
			cout << "The array is sorted.\n";
		else
			cout << "The array is not sorted.\n";
	}
	else if (choice2 == 2) {
		SelectionSort selection(values, length);
		cout << "\nSelectionSort:\n";
		selection.printValues();
		cout << "The array is sorted.\n\n";
	}
	else if (choice2 == 3) {
		Quicksort quick(values, length);
		cout << "\nQuicksort:\n";
		quick.printValues();
		cout << "The array is sorted.\n\n";
	}

	system("PAUSE");
	return 0;
}

bool isSorted(int* values, int length) {
	for (int i = 0; i < length - 1; i++) {
		if (values[i + 1] < values[i])
			return false;
	}
	return true;
}