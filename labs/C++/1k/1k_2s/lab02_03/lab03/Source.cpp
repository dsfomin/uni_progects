#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "LZW.h"

using namespace std;

const int MAX = 100;

class sparse_matrix {

public:
	// Maximum number of elements in matrix 

	// Array representation 
	// of sparse matrix 
	//[][0] represents row 
	//[][1] represents col 
	//[][2] represents value 
	int data[MAX][3];

	// dimensions of matrix 
	int row, col;

	// total number of elements in matrix 
	int len;
	sparse_matrix() {
		row = 0;

		col = 0;

		len = 0;
	}

	sparse_matrix(int r, int c)
	{

		// initialize row 
		row = r;

		// initialize col 
		col = c;

		// intialize length to 0 
		len = 0;
	}

	// insert elements into sparse matrix 
	void insert(int r, int c, int val)
	{

		// invalid entry 
		if (r > row || c > col) {
			cout << "Wrong entry" << endl;
		}

		else {

			// insert row value 
			data[len][0] = r;

			// insert col value 
			data[len][1] = c;

			// insert element's value 
			data[len][2] = val;

			// increment number of data in matrix 
			len++;
		}
	}

	sparse_matrix transpose()
	{

		// new matrix with inversed row X col 
		sparse_matrix result = sparse_matrix(col, row); /*TYYYYYYYYYYYYYYYYYYYYYYYYYYYYYT*/

		// same number of elements 
		result.len = len;

		// to count number of elements in each column 
		int *count = new int[col + 1];

		// initialize all to 0 
		for (int i = 1; i <= col; i++)
			count[i] = 0;

		for (int i = 0; i < len; i++)
			count[data[i][1]]++;

		int *index = new int[col + 1];

		// to count number of elements having col smaller 
		// than particular i 

		// as there is no col with value < 1 
		index[1] = 0;

		// initialize rest of the indices 
		for (int i = 2; i <= col; i++)

			index[i] = index[i - 1] + count[i - 1];

		for (int i = 0; i < len; i++) {

			// insert a data at rpos and increment its value 
			int rpos = index[data[i][1]]++;

			// transpose row=col 
			result.data[rpos][0] = data[i][1];

			// transpose col=row 
			result.data[rpos][1] = data[i][0];

			// same value 
			result.data[rpos][2] = data[i][2];
		}

		// the above method ensures 
		// sorting of transpose matrix 
		// according to row-col value 
		return result;
	}
};

sparse_matrix operator+(sparse_matrix& a, sparse_matrix& b) {

	// if matrices don't have same dimensions 
	if (a.row != b.row || a.col != b.col) {
		cout << "Matrices can't be added" << endl;
	}

	else {

		int apos = 0, bpos = 0;
		sparse_matrix result = sparse_matrix(a.row, a.col);

		while (apos < a.len && bpos < b.len) {

			// if b's row and col is smaller 
			if (a.data[apos][0] > b.data[bpos][0] ||
				(a.data[apos][0] == b.data[bpos][0] &&
					a.data[apos][1] > b.data[bpos][1]))

			{

				// insert smaller value into result 
				result.insert(b.data[bpos][0],
					b.data[bpos][1],
					b.data[bpos][2]);

				bpos++;
			}

			// if a's row and col is smaller 
			else if (a.data[apos][0] < b.data[bpos][0] ||
				(a.data[apos][0] == b.data[bpos][0] &&
					a.data[apos][1] < b.data[bpos][1]))

			{

				// insert smaller value into result 
				result.insert(a.data[apos][0],
					a.data[apos][1],
					a.data[apos][2]);

				apos++;
			}

			else {

				// add the values as row and col is same 
				int addedval = a.data[apos][2] + b.data[bpos][2];

				if (addedval != 0)
					result.insert(a.data[apos][0],
						a.data[apos][1],
						addedval);
				// then insert 
				apos++;
				bpos++;
			}
		}

		// insert remaining elements 
		while (apos < a.len) {
			result.insert(a.data[apos][0],
				a.data[apos][1],
				a.data[apos][2]);
			apos++;
		}


		while (bpos < b.len) {
			result.insert(b.data[bpos][0],
				b.data[bpos][1],
				b.data[bpos][2]);
			bpos++;
		}


		return result;
	}
}


sparse_matrix operator*(sparse_matrix& lhs, sparse_matrix& rhs) {
	if (lhs.col != rhs.row) {

		// Invalid muliplication 
		cout << "Can't multiply, Invalid dimensions" << endl;

		exit(1);
	}

	// transpose b to compare row 
	// and col values and to add them at the end 
	rhs = rhs.transpose();
	int apos, bpos;

	// result matrix of dimension row X rhs.col 
	// however b has been transposed, hence row X rhs.row 
	sparse_matrix result = sparse_matrix(lhs.row, rhs.row); /*TTYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYT*/

	// iterate over all elements of A 
	for (apos = 0; apos < lhs.len;) {

		// current row of result matrix 
		int r = lhs.data[apos][0];

		// iterate over all elements of B 
		for (bpos = 0; bpos < rhs.len;) {

			// current column of result matrix 
			// data[][0] used as b is transposed 
			int c = rhs.data[bpos][0];

			// temporary pointers created to add all 
			// multiplied values to obtain current 
			// element of result matrix 
			int tempa = apos;
			int tempb = bpos;

			int sum = 0;

			// iterate over all elements with 
			// same row and col value 
			// to calculate result[r] 
			while (tempa < lhs.len && lhs.data[tempa][0] == r
				&& tempb < rhs.len && rhs.data[tempb][0] == c) {

				if (lhs.data[tempa][1] < rhs.data[tempb][1])

					// skip a 
					tempa++;

				else if (lhs.data[tempa][1] > rhs.data[tempb][1])

					// skip b 
					tempb++;
				else

					// same col, so multiply and increment 
					sum += lhs.data[tempa++][2] * rhs.data[tempb++][2];
			}

			// insert sum obtained in result[r] 
			// if its not equal to 0 
			if (sum != 0)
				result.insert(r, c, sum);

			while (bpos < rhs.len && rhs.data[bpos][0] == c)

				// jump to next column 
				bpos++;
		}

		while (apos < lhs.len && lhs.data[apos][0] == r)

			// jump to next row 
			apos++;
	}

	return result;
}

ostream& operator<<(ostream& stream, sparse_matrix& matrix) {
	stream << "Dimension: " << matrix.row << "x" << matrix.col << endl;
	stream << "Sparse Matrix: " << endl << "Row Column Value" << endl;

	for (int i = 0; i < matrix.len; i++) {

		stream << setw(3) << matrix.data[i][0] << setw(7)
			<< matrix.data[i][1] << setw(6) << matrix.data[i][2] << endl;
	}
	return stream;
}

void ReadMatrixFromFile(sparse_matrix& matrix, string path, int rows, int cols) {

	ifstream in(path, ios::in | ios::binary);
	int a;

	if (in.is_open())
	{
		for (int i = 1; i <= rows; i++) {
			for (int j = 1; j <= cols; j++) {
				in >> a;
				if (a != 0)
					matrix.insert(i, j, a);
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

void PrintFullMatrix(sparse_matrix& matrix) {
	int tmp = 0;
	for (int i = 1; i <= matrix.row; i++) {
		for (int j = 1; j <= matrix.col; j++) {
			if (matrix.data[tmp][0] == i && matrix.data[tmp][1] == j) {
				cout << matrix.data[tmp][2] << ' ';
				tmp++;
			}
			else
				cout << 0 << ' ';
		}
		cout << endl;
 	}
}

void Cout(char** argv) {
	string temp;
	char char_temp0[256];
	char char_temp1[256];
	char char_temp2[256];
	cin >> temp;
	strcpy(char_temp0, temp.c_str());
	argv[0] = char_temp0;
	cin >> temp;
	strcpy(char_temp1, temp.c_str());
	argv[1] = char_temp1;
	cin >> temp;
	strcpy(char_temp2, temp.c_str());
	argv[2] = char_temp2;
}

int main() {
	sparse_matrix first, second, third;
	int key, rows, cols;
	string source;
	bool flag = 0;

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

			cout << "Input number of rows of first matrix " << endl;
			cin >> rows;
			cout << "Input number of cols of first matrix " << endl;
			cin >> cols;

			cout << "Input the path of first matrix: " << endl;
			cin >> source;
			first = sparse_matrix(rows, cols);
			ReadMatrixFromFile(first, source, rows, cols);

			cout << "Input number of rows of second matrix " << endl;			
			cin >> rows;
			cout << "Input number of cols of second matrix " << endl;
			cin >> cols;

			cout << "Input the path of second matrix: " << endl;
			cin >> source;
			second = sparse_matrix(rows, cols);
			ReadMatrixFromFile(second, source, rows, cols);

			flag = 1;
			break;
		}
		case 2: {
			int count;
			cout << "Input number of rows of matrix " << endl;
			cin >> rows;
			cout << "Input number of cols of matrix " << endl;
			cin >> cols;

			first = sparse_matrix(rows, cols);
			cout << "-----First_Matrix-----" << endl;
			cout << "Set the number of adding" << endl;
			cin >> count;

			for (int i = 0; i < count; i++) {
				int r, c, v;
				cout << "Row: ";
				cin >> r;
				cout << "Col: ";
				cin >> c;
				cout << "Value: ";
				cin >> v;
				first.insert(r, c, v);
			}

			second = sparse_matrix(rows, cols);
			cout << "-----Second_Matrix-----" << endl;
			cout << "Set the number of adding" << endl;
			cin >> count;

			for (int i = 0; i < count; i++) {
				int r, c, v;
				cout << "Row: ";
				cin >> r;
				cout << "Col: ";
				cin >> c;
				cout << "Value: ";
				cin >> v;
				second.insert(r, c, v);
			}

			flag = 1;
			break;
		}
		case 3: {
			if (flag == 1) {
				bool variable;
				cout << "Full matrix(0) or just non-zero values(1)?" << endl;
				cin >> variable;
				if (variable == 1) {
					cout << "----Matrix 1---- " << endl;
					cout << first;
					cout << "----Matrix 2---- " << endl;
					cout << second;
				}
				else {
					cout << "----Matrix 1---- " << endl;
					PrintFullMatrix(first);
					cout << "----Matrix 2---- " << endl;
					PrintFullMatrix(second);
				}
			}
			else {
				cout << "Enter matrix choice 1!" << endl;
			}
			break;
		}
		case 4: {
			if (flag == 1) {
				third = first + second;

				cout << third << endl;
			}
			else
				cout << "Enter matrix choice 1!" << endl;
			break;
		}
		case 5: {
			if (flag == 1) {
				third = first * second;

				cout << third << endl;
			}
			else
				cout << "Enter matrix choice 1!" << endl;
			break;
		}
		case 6: {
			string ed, src, dest;
			cout << "Input: \n1) endcode or decode\n2) source\n3) destination" << endl;
			cin >> ed >> src >> dest;

			char* paths = new char[20];
			char* pathd = new char[20];
			strcpy(paths, src.c_str());
			strcpy(pathd, dest.c_str());

			// Компрессия:
			if (ed == "e" || src == "E")
			{
				BFILE *output;
				FILE *input;

				// открытие входного файла для чтения
				input = fopen(paths, "rb");

				// открытие выходного файла для записи
				output = OpenOutputBFile(pathd);
				if (output == NULL)
					fatal_error("Ошибка при открытии %s для вывода\n", pathd);
				printf("\nКомпрессия %s в %s\n", paths, pathd);

				// вызов процедуры компрессии
				CompressFile(input, output);

				// закрытие файлов
				CloseOutputBFile(output);
				fclose(input);

				printf("\nCompression complete.");

				// вывод коэффициента сжатия
				print_ratios(paths, pathd);
			}
			// Декомпрессия:
			else if (ed == "d" || ed == "D")
			{
				BFILE *input;
				FILE *output;

				// открытие входного файла для чтения
				input = OpenInputBFile(paths);
				if (input == NULL)
					fatal_error("Error on open %s for read\n", paths);

				// открытие выходного файла для записи
				output = fopen(pathd, "wb");
				if (output == NULL)
					fatal_error("Error on open %s for write\n",pathd);

				printf("\nDecompression %s into %s\n", paths, pathd);

				// вызов процедуры декомпрессии
				ExpandFile(input, output);

				// закрытие файлов
				CloseInputBFile(input);
				fclose(output);

				printf("\nDecompression complete.");
			}
			break;
		}
		case 0: {
			exit(1);
		}
		}
	}

	return 0;
}