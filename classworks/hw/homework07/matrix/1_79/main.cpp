/* Matrix_79.cpp: Дана матрица размера M × N. Упорядочить ее столбцы так, чтобы
их максимальные элементы образовывали возрастающую последовательность.*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip> 

using namespace std;


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int N, M, i, j, max;
	cout << "Введите количество строк: ";
	cin >> N;
	cout << "Введите количество столбцов: ";
	cin >> M;
	int **mass = new int *[N];
	for (int i = 0; i < N; i++)
		mass[i] = new int[M];

	int *mass1 = new int[M];
	int *mass2 = new int[M];

	int **mass3 = new int *[N];
	for (int i = 0; i < N; i++)
		mass3[i] = new int[M];

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			mass[i][j] = rand() % 10;
			cout << mass[i][j] << " ";
		}
		cout << endl;
	}

	cout << "Массив: " << endl;

	int StNmin, StNmax;
	for (j = 0; j < M; j++)
	{
		max = -1;
		for (i = 0; i < N; i++)


			if (max < mass[i][j])
			{
				max = mass[i][j];
			}
		mass1[j] = max;
		mass2[j] = j;
	}



	for (int j = 1; j < M; j++)
	{
		for (int r = 0; r < M - j; r++)
		{
			if (mass1[r] > mass1[r + 1])
			{
				// Обмен местами
				int temp = mass1[r];
				mass1[r] = mass1[r + 1];
				mass1[r + 1] = temp;

				temp = mass2[r];
				mass2[r] = mass2[r + 1];
				mass2[r + 1] = temp;
			}
		}
	}

	for (int j = 0; j < M; j++)
	{
		for (int i = 0; i < N; i++)
		{
			mass3[i][j] = mass[i][mass2[j]];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << mass3[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return(0);
}