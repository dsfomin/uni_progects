
#include <iostream>
#include <vector>
#include "D-aryPyramid.h"

using namespace std;

int main() {
	int arr[capacity];
	int n = capacity;
	int d = 5; 
	D_aryPyr p(arr, n, d);

	for (int i = 0; i < capacity; i++) {
		arr[i] = i;
	}

	p.buildHeap();

	cout << "Built Heap : \n";
	for (int i = 0; i < p.GetSize(); i++)
		cout << arr[i] << " ";

	cout << endl << endl;

	/*int element = 3;

	p.insert(element);

	cout << "Heap after insertion of " << element << endl;
	for (int i = 0; i < p.GetSize(); i++)
		cout << arr[i] << " ";

	cout << endl << endl;

	cout << "Extracted max is " << p.extractMax();

	cout << endl << endl;
	
	cout << "Heap after extract max: " << endl;
	for (int i = 0; i < p.GetSize(); i++)
		cout << arr[i] << " ";

	cout << endl << endl;  

	p.insert(20);
	p.insert(19);
	p.insert(11);
	p.insert(12);


	cout << "Heap after insertion of " << element << endl;
	for (int i = 0; i < p.GetSize(); i++)
		cout << arr[i] << " ";

	cout << endl << endl;*/

	vector<int> output;

	int size = p.GetSize();

	for (int i = 0; i < size; i++) {
		output.push_back(p.extractMax());
	}
	
	for (int i : output) {
		cout << i << " ";
	}

	cout << endl;

	system("pause>nul");
	return 0;
}