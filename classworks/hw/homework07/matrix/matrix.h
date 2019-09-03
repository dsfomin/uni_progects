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