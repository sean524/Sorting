#ifndef QUICKSORT_CPP
#define QUICKSORT_CPP

#include <iostream>

using namespace std;

class Quicksort {
private:
	int length;
	int* values;
public:
	Quicksort(int* arr, int l) {
		length = l;
		values = new int[l];
		for (int i = 0; i < l; i++)
			values[i] = arr[i];
		Sort(0, length - 1);
	}

	void Sort(int low, int high) {
		if (low < high) {
			int p = 0;
			p = partition(low, high);
			Sort(low, p - 1);
			Sort(p + 1, high);
		}
	}
	int partition(int low, int high) {
		int pivot = values[high];
		int index = low - 1;
		for (int i = low; i < high; i++) {
			if (values[i] < pivot) {
				index++;
				swap(index, i);
			}
		}
		swap(index + 1, high);
		return index + 1;
	}
	void swap(int i, int j) {
		int temp = values[i];
		values[i] = values[j];
		values[j] = temp;
	}

	void printValues() {
		for (int i = 0; i < length; i++) {
			cout << values[i] << endl;
		}
	}
};

#endif