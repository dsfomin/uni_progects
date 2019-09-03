/* Matrix_41.cpp: Дана матрица размера M × N. Поменять местами строки, содержащие
минимальный и максимальный элементы матрицы.*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int N, M, i, j, min = 100, max = 0, k;
	cout << "Введите количество строк: ";
	cin >> N;
	cout << "Введите количество столбцов: ";
	cin >> M;
	int **mass = new int *[N];
	for (int i = 0; i < N; i++)
		mass[i] = new int[M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			mass[i][j] = rand() % 10;
	}

	cout << "Массив: " << endl;
	int StrNmin, StrNmax;
	for (int i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			cout << mass[i][j] << " ";
			if (min > mass[i][j])
			{
				min = mass[i][j];
				StrNmin = i;
			}

			if (max < mass[i][j])
			{
				max = mass[i][j];
				StrNmax = i;
			}

		}
		cout << endl;
	}
	cout << endl;

	if (StrNmin != StrNmax)
	{
		for (int i = 0; i < M; i++)
		{
			k = mass[StrNmin][i];
			mass[StrNmin][i] = mass[StrNmax][i];
			mass[StrNmax][i] = k;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
			cout << mass[i][j] << " ";
		cout << endl;
	}
	cout << endl;
	system("pause");
	return 0;
}
