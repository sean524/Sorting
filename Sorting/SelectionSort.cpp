#ifndef SELECTIONSORT_CPP
#define SELECTIONSORT_CPP

#include <iostream>

using namespace std;

class SelectionSort {
private:
	int min,
		length;
	int* values;
public:
	SelectionSort(int* arr, int l) {
		length = l;
		values = new int[l];
		for (int i = 0; i < l; i++)
			values[i] = arr[i];
		Sort();
	}
	void Sort() {
		for (int i = 0; i < length - 1; i++) {
			min = i;
			for (int j = i + 1; j < length; j++) {
				if (values[j] < values[min])
					min = j;
			}
			if (i != min) {
				swap(min, i);
			}
		}
	}
	void swap(int i, int j) {
		int temp = values[i];
		values[i] = values[j];
		values[j] = temp;
	}

	void printValues() {
		for (int i = 0; i < length; i++)
			cout << values[i] << endl;
	}
};


#endif