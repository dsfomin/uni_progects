#include <iostream>

using namespace std;
#define RANGE 1

//1) O(n), mem O(1)
//2) O(n), stoikii
//3) mem O(1), stoikii

void swap(int A[], int i, int j) {
	int temp = A[i];
	A[i] = A[j];
	A[j] = temp;
}

void SortingBinaryArr_1(int arr[], int n)  // O(n) , mem: O(1), ne stoikii
{
	int i = 0;
	int j = n - 1;
	while (i < j) {
		if (arr[i] == 0) {
			i++;
			continue;
		}
		if (arr[j] == 1) {
			j--;
			continue;
		}
		swap(arr, i, j);
	}
}

void SortingBinaryArr_2(int arr[], int n)  // O(n^2) , mem: O(1), stoikii
{
	for (int i = 1; i < n; i++) {
		int x = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > x) {
			arr[j] = arr[j - 1];
			j = j - 1;
		}
		arr[j] = x;
	}
}

void SortingBinaryArr_3(int arr[], int n)  // O(n) , mem: O(n + 1), stoikii
{
	int *C = new int[2];
	int *B= new int[n];
	for (int i = 0; i < 2; i++)
		C[i] = 0;
	for (int i = 0; i < n; i++)
		C[arr[i]] = C[arr[i]] + 1;
	for (int j = 1; j < 2; j++)
		C[j] = C[j] + C[j - 1];
	for (int i = n - 1; i >= 0; i--) {
		C[arr[i]] = C[arr[i]] - 1;
		B[C[arr[i]]] = arr[i];
	}
	for (int i = 0; i < n; i++) {
		arr[i] = B[i];
	}
}

int main() {
	int arr1[] = { 0, 1, 0, 1, 1, 1 };
	int i, arr_size1 = sizeof(arr1) /
		sizeof(arr1[0]);

	SortingBinaryArr_1(arr1, arr_size1);

	cout << "Array after segregation is ";
	for (i = 0; i < arr_size1; i++)
		cout << arr1[i] << " ";

	cout << endl;

	int arr2[] = { 1, 0, 0, 1, 0, 0, 1 };
	int arr_size2 = sizeof(arr2) /
		sizeof(arr2[0]);

	SortingBinaryArr_2(arr2, arr_size2);

	cout << "Array after segregation is ";
	for (i = 0; i < arr_size2; i++)
		cout << arr2[i] << " ";

	cout << endl;

	int arr3[] = { 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1 };
	int arr_size3 = sizeof(arr3) /
		sizeof(arr3[0]);

	SortingBinaryArr_3(arr3, arr_size3);

	cout << "Array after segregation is ";
	for (i = 0; i < arr_size3; i++)
		cout << arr3[i] << " ";

	system("pause>nul");
	return 0;
}