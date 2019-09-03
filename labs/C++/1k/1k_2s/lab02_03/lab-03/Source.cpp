#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

using namespace std;

struct R_Matrix {
	int *Aj, *Ai, *Val;
};

void Input(R_Matrix& rm, int sizeMatrix) {
	for (int i(0); i < sizeMatrix; i++) {
		for (int j(0); j < sizeMatrix; j++) {
			cout << "Element matrix [" << i << "][" << j << "]=";
			cin >> Arr[i][j];
		}
	}
}
void Print(R_Matrix& rm, int sizeMatrix) {
	int counter = 0;
	for (int i = 0; i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			if (rm.Ai[i] != counter) {

			}
		}
		cout << endl;
	}
}
void Sum(R_Matrix& rm1, R_Matrix& rm2, R_Matrix& rm3, int sizeMatrix) {
	for (int i(0); i < sizeMatrix; i++) {
		for (int j = 0; j < sizeMatrix; j++) {
			for (int i0 = 0; i0 < sizeMatrix; i0++) {
				for (int j0 = 0; j0 < sizeMatrix; j0++) {
					if (rm1.Ai[i] == rm2.Ai[i0] && rm1.Aj[j] == rm2.Aj[j0]) {
						rm3.Ai[i] = rm1.Ai[i];
						rm3.Aj[i] = rm1.Aj[i];
						rm3.Val[i] = rm1.Val[i] + rm2.Val[i];
					}
					else if (rm1.Ai[i] == rm2.Ai[i] && rm1.Aj[j] != rm2.Aj[j]) {

					}
					else if (rm1.Ai[i] != rm2.Ai[i] && rm1.Aj[j] == rm2.Aj[j]) {

					}
					else if (rm1.Ai[i] != rm2.Ai[i] && rm1.Aj[j] != rm2.Aj[j]) {

					}
				}
			}
		}
	}
}
void Mult(R_Matrix& rm1, R_Matrix& rm2, R_Matrix& rm3, int sizeMatrix) {
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

void ReadMatrixFromFile(R_Matrix& rm, string path, int sizeMatrix) {

	ifstream in(path, ios::in | ios::binary);

	int tmp = 0;

	if (in.is_open())
	{
		int counter = 0;
		//Считаем матрицу из файла
		for (int i = 0; i < sizeMatrix; i++) {
			for (int j = 0; j < sizeMatrix; j++) {
				if (in >> tmp && tmp != 0) {
					rm.Ai[counter] = i;
					rm.Aj[counter] = j;
					rm.Val[counter] = tmp;
					counter++;
				}
			}
		}

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
	R_Matrix rm1, rm2, rm3;
	int sizeMatrix;
	int key;
	int flag = 0;
	cout << "-------Menu-------" << endl;
	cout << "1-Read matrix from file" << endl;
	cout << "2-Input matrix" << endl;
	cout << "3-Print matrix" << endl;
	cout << "4-Sum matrix" << endl;
	cout << "5-Multiply matrix" << endl;
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
			rm1.Ai = new int[3 * sizeMatrix];
			rm1.Aj = new int[3 * sizeMatrix];
			rm1.Val = new int[3 * sizeMatrix];
			ReadMatrixFromFile(rm1, source, sizeMatrix);
			cout << "Input the path of second matrix: " << endl;
			cin >> source;
			rm2.Ai = new int[3 * sizeMatrix];
			rm2.Aj = new int[3 * sizeMatrix];
			rm2.Val = new int[3 * sizeMatrix];
			ReadMatrixFromFile(rm2, source, sizeMatrix);

			flag = 1;
			break;
		}
				//case 2: {
				//	cout << "Input size matrix ";
				//	cin >> sizeMatrix;

				//	cout << "Matrix 1:" << endl;
				//	Arr1 = new int*[sizeMatrix];
				//	for (int i(0); i < sizeMatrix; i++) { Arr1[i] = new int[sizeMatrix]; }
				//	Input(Arr1, sizeMatrix);

				//	cout << "Matrix 2:" << endl;
				//	Arr2 = new int*[sizeMatrix];
				//	for (int i(0); i < sizeMatrix; i++) { Arr2[i] = new int[sizeMatrix]; }
				//	Input(Arr2, sizeMatrix);

				//	flag = 1;
				//	break;
				//}
		case 3: {
			if (flag == 1) {
				cout << "----Matrix 1---- " << endl;
				Print(rm1, sizeMatrix);
				cout << "----Matrix 2---- " << endl;
				Print(rm2, sizeMatrix);
			}
			else
				cout << "Enter matrix choice 1!" << endl;
			break;
		}
		case 4: {
			if (flag == 1) {
				rm3.Ai = new int[3 * sizeMatrix];
				rm3.Aj = new int[3 * sizeMatrix];
				rm3.Val = new int[3 * sizeMatrix];

				Sum(rm1, rm2, rm3, 3 * sizeMatrix);
				cout << "Sum matrix 1 & matrix 2" << endl;
				Print(rm3, 3 * sizeMatrix);

				delete[] rm3.Ai;
				delete[] rm3.Aj;
				delete[] rm3.Val;
			}
			else
				cout << "Enter matrix choice 1!" << endl;
			break;
		}
		case 5: {
			if (flag == 1) {
				rm3.Ai = new int[3 * sizeMatrix];
				rm3.Aj = new int[3 * sizeMatrix];
				rm3.Val = new int[3 * sizeMatrix];

				Mult(rm1, rm2, rm3, 3 * sizeMatrix);
				cout << "Multiplex matrix 1 & matrix 2" << endl;
				Print(rm3, 3 * sizeMatrix);

				delete[] rm3.Ai;
				delete[] rm3.Aj;
				delete[] rm3.Val;
			}
			else
				cout << "Enter matrix choice 1!" << endl;
			break;
		}
		case 0: {
			exit(1);
		}
		}
	}
	delete[] rm1.Ai;
	delete[] rm1.Aj;
	delete[] rm1.Val;
	delete[] rm2.Ai;
	delete[] rm2.Aj;
	delete[] rm2.Val;

	return 0;
}