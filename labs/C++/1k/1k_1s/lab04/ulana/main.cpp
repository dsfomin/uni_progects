#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	setlocale(0, "rus");
	int ROWS, COLS, count, i, j, rowBeg, rowEnd, colBeg, colEnd;
	// ����������� � ������������ ������� �������
	cout << "������� ���������� ����� �������: ";
	cin >> ROWS;
	cout << "������� ���������� �������� �������: ";
	cin >> COLS;
	// �������� ������ ��� ������������ �������
	int **matr = new int*[ROWS];
	for (i = 0; i < ROWS; i++)
		matr[i] = new int[COLS];
	cout << endl << "��� ������� :  " << ROWS <<"  x  "<< COLS << endl << endl;
	// �������������� ������� ���������� ���������� � ��������� 1 - 50
	for (i = 0; i < ROWS; i++)
		for (j = 0; j < COLS; j++)
			matr[i][j] = rand() % 50 + 1;
	// ����� �������
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
			cout << setw(3) << matr[i][j];
		cout << endl;
	}
	// ����� �������� ������� �� �������
	cout << endl << " B���� �������� �� �������: ";
	rowBeg = 0;
	rowEnd = ROWS - 1;
	colBeg = 0;
	colEnd = COLS - 1;
	count = ROWS * COLS;
	while (count)
	{
		for (i = colBeg; i <= colEnd && count; i++, count--)
			cout << setw(3) << matr[rowBeg][i];
		rowBeg++;
		for (i = rowBeg; i <= rowEnd && count; i++, count--)
			cout << setw(3) << matr[i][colEnd];
		colEnd--;
		for (i = colEnd; i >= colBeg && count; i--, count--)
			cout << setw(3) << matr[rowEnd][i];
		rowEnd--;
		for (i = rowEnd; i >= rowBeg && count; i--, count--)
			cout << setw(3) << matr[i][colBeg];
		colBeg++;
	}
	cout << endl;
	// ����������� ������
	for (int i = 0; i < ROWS; ++i) {
		delete[] matr[i];
	}
	delete [] matr;
	system("pause");
	return 0;
}