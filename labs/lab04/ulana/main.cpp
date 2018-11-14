#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

int main()
{
	setlocale(0, "rus");
	srand((unsigned)time(NULL));
	int **matr, ROWS, COLS, count, i, j, rowBeg, rowEnd, colBeg, colEnd;
	// ����������� � ������������ ������� �������
	cout << "������� ���������� ����� �������: ";
	cin >> ROWS;
	cout << "������� ���������� �������� �������: ";
	cin >> COLS;
	// �������� ������ ��� ������������ �������
	matr = (int **)malloc(ROWS * sizeof(int *));
	for (i = 0; i < ROWS; i++)
		matr[i] = (int *)malloc(COLS * sizeof(int));
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
	for (i = 0; i < ROWS; i++)
		free(matr[i]);
	free(matr);
	system("pause");
	return 0;
}