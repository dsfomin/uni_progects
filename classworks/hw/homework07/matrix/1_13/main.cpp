/*
Matrix13. Дана квадратная матрица A порядка M. Начиная с элемента A1,1, вы-
вести ее элементы следующим образом («уголками»): все элементы первой
строки; элементы последнего столбца, кроме первого (уже выведенного)
элемента; оставшиеся элементы второй строки; оставшиеся элементы
предпоследнего столбца и т. д.; последним выводится элемент AM,1.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int **new_matrix(int height, int width)
{
	int **mx = new int *[height];
	for (int i = 0; i < height; i++)
		mx[i] = new int[width];
	return mx;
}

void fill_matrix(int **mx, int height, int width)
{
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
			mx[i][j] = rand() % 50 + 1;
}

void cout_matr_s(int **mx, int height, int width)
{
	int i, j;
	for (i = 0; i < width; i++)
	{
		for (j = 0; j < height; j++)
			cout << setw(3) << mx[i][j];
		cout << endl;
	}
}

void cout_matr(int **mx, int m)
{
	int k = m;
	int j = 0, i = 0;
	while (i != m || j != 1)
	{
		for (j = 0, i = m - k; j < k; j++)
			cout << setw(3) << mx[i][j];
		for (j = k - 1, i = m - k + 1; i < m; i++)
			cout << setw(3) << mx[i][j];
		k--;
	}
	cout << setw(3) << mx[m - 1][0];
}

void delete_matr(int **mx, int height)
{
	for (int i = 0; i < height; i++)
	{
		delete[] mx[i];
	}
	delete[]mx;
}

int main()
{
	int m;
	cout << "Vvedite razmer" << endl;
	cin >> m;
	int **matr = new_matrix(m, m);
	fill_matrix(matr, m, m);
	cout_matr_s(matr, m, m);
	cout_matr(matr, m);
	delete_matr(matr, m);
	system("pause");
	return 0;
}