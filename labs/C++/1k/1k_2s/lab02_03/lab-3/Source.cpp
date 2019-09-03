#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Huffman.h"

using namespace std;

const int SIZE = 256;

void Input(int **Arr, int sizeMatrix) {
	for (int i(0); i < sizeMatrix; i++) {
		for (int j(0); j < sizeMatrix; j++) {
			cout << "Element matrix [" << i << "][" << j << "]=";
			cin >> Arr[i][j];
		}
	}
}
void Print(int **Arr, int sizeMatrix) {
	for (int i(0); i < sizeMatrix; i++) {
		for (int j(0); j < sizeMatrix; j++) {
			cout << Arr[i][j] << " ";
		}
		cout << endl;
	}
}
void Sum(int **Arr1, int **Arr2, int **Arr3, int sizeMatrix) {
	for (int i(0); i < sizeMatrix; i++) {
		for (int j(0); j < sizeMatrix; j++) {
			Arr3[i][j] = Arr1[i][j] + Arr2[i][j];
		}
	}
}
void Mult(int **Arr1, int **Arr2, int **Arr3, int sizeMatrix) {
	int temp = 0;
	for (int i(0); i < sizeMatrix; i++) {
		for (int j(0); j < sizeMatrix; j++) {
			temp = 0;
			for (int i1(0); i1 < sizeMatrix; i1++) {
				temp += Arr1[i][i1] * Arr2[i1][j];
				Arr3[i][j] = temp;
			}
		}
	}
}

void ReadMatrixFromFile(int **Arr, string path, int sizeMatrix) {
	
	ifstream in(path, ios::in | ios::binary);

	if (in.is_open())
	{
		//Считаем матрицу из файла
		for (int i = 0; i < sizeMatrix; i++)
			for (int j = 0; j < sizeMatrix; j++)
				in >> Arr[i][j];

		in.close();//под конец закроем файла
	}
	else
	{
		//Если открытие файла прошло не успешно
		cout << "Файл не найден.";
	}
}

int main()
{
	setlocale(0, "rus");
	int **Arr1 = 0, **Arr2 = 0, **Arr3;
	int sizeMatrix;
	int key;
	int flag = 0;
	cout << "-------Menu-------" << endl;
	cout << "1-Read matrix from file" << endl;
	cout << "2-Input matrix" << endl;
	cout << "3-Print matrix" << endl;
	cout << "4-Sum matrix" << endl;
	cout << "5-Multiply matrix" << endl;
	cout << "6-Encode or Decode file" << endl;
	cout << "0-Exit" << endl;
	cout << "------------------" << endl;
	while (1) {
		cout << "You choice ";
		cin >> key;
		switch (key) {
		case 1: {
			string source;

			cout << "Input size matrix ";
			cin >> sizeMatrix;

			cout << "Input the path of first matrix: " << endl;
			cin >> source;
			Arr1 = new int*[sizeMatrix];
			for (int i(0); i < sizeMatrix; i++) { Arr1[i] = new int[sizeMatrix]; }
			ReadMatrixFromFile(Arr1, source, sizeMatrix);
			cout << "Input the path of second matrix: " << endl;
			cin >> source;
			Arr2 = new int*[sizeMatrix];
			for (int i(0); i < sizeMatrix; i++) { Arr2[i] = new int[sizeMatrix]; }
			ReadMatrixFromFile(Arr2, source, sizeMatrix);

			flag = 1;
			break;
		}
		case 2: {
			cout << "Input size matrix ";
			cin >> sizeMatrix;

			cout << "Matrix 1:" << endl;
			Arr1 = new int*[sizeMatrix];
			for (int i(0); i < sizeMatrix; i++) { Arr1[i] = new int[sizeMatrix]; }
			Input(Arr1, sizeMatrix);

			cout << "Matrix 2:" << endl;
			Arr2 = new int*[sizeMatrix];
			for (int i(0); i < sizeMatrix; i++) { Arr2[i] = new int[sizeMatrix]; }
			Input(Arr2, sizeMatrix);

			flag = 1;
			break;
		}
		case 3: {
			if (flag == 1) {
				cout << "----Matrix 1---- " << endl;
				Print(Arr1, sizeMatrix);
				cout << "----Matrix 2---- " << endl;
				Print(Arr2, sizeMatrix);
			}
			else
				cout << "Enter matrix choice 1!" << endl;
			break;
		}
		case 4: {
			if (flag == 1) {
				Arr3 = new int*[sizeMatrix];
				for (int i(0); i < sizeMatrix; i++) { Arr3[i] = new int[sizeMatrix]; }

				Sum(Arr1, Arr2, Arr3, sizeMatrix);
				cout << "Sum matrix 1 & matrix 2" << endl;
				Print(Arr3, sizeMatrix);

				for (int i(0); i < sizeMatrix; i++)
					delete[] Arr3[i];
				delete[] Arr3;
			}
			else
				cout << "Enter matrix choice 1!" << endl;
			break;
		}
		case 5: {
			if (flag == 1) {
				Arr3 = new int*[sizeMatrix];
				for (int i(0); i < sizeMatrix; i++) { Arr3[i] = new int[sizeMatrix]; }

				Mult(Arr1, Arr2, Arr3, sizeMatrix);
				cout << "Multiplex matrix 1 & matrix 2" << endl;
				Print(Arr3, sizeMatrix);

				for (int i(0); i < sizeMatrix; i++)
					delete[] Arr3[i];
				delete[] Arr3;
			}
			else
				cout << "Enter matrix choice 1!" << endl;
			break;
		}
		case 6: {
			

			break;
		}
		case 0: {
			exit(1);
		}
		}
	}
	for (int i(0); i < sizeMatrix; i++)
		delete[] Arr1[i];
	delete[] Arr1;

	for (int i(0); i < sizeMatrix; i++)
		delete[] Arr2[i];
	delete[] Arr2;

	return 0;
}