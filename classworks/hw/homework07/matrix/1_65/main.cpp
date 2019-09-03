/* Matrix_65.cpp: Дана матрица размера M × N. Удалить ее первый столбец, содержащий
только положительные элементы.Если требуемых столбцов нет, то
вывести матрицу без изменений.*/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip> 

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
		{
			mass[i][j] = rand() % 10 - 5;
			cout << setw(4) << mass[i][j];
		}
		cout << endl;
	}


	cout << "Массив: " << endl;
	bool flag = false;
	for (int i = 0; i < N; i++)
	{
		if (mass[i][0] < 0)
		{
			flag = true;
		}

	}

	if (flag == true)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 1; j < M; j++)
			{
				cout << setw(4) << mass[i][j];
			}
			cout << " " << endl;
		}
	}
	else for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cout << setw(4) << mass[i][j];
		}
		cout << " " << endl;
	}
	system("pause");
	return 0;
}

