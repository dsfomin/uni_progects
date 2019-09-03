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
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
			cout << setw(3) << mx[i][j];
		cout << endl;
	}
}

void search_biggest_in_the_row(int **mx, int height, int width)
{
	int i = 0, j = 0, pos = 0, r = 1;
	for (i = 0; i < height; i++)
	{
		int mem = 0;
		for (j = 0; j < width; j++)
		{
			if (mx[i][j] > mem)
			{
				mem = mx[i][j];
				pos = j;
			}
		}
		cout << "Naibbol'chee v ryady " << r << " stoit na posizii " << pos + 1 << " i ravno " << mem << endl;
		r++;
	}
}

int main()
{
	int m, n;
	cout << "Vvedite razmer m x n:" << endl;
	cin >> m >> n;
	int **matr = new_matrix(m, n);
	fill_matrix(matr, m, n);
	cout_matr_s(matr, m, n);
	search_biggest_in_the_row(matr, m, n);
	system("pause");
	return 0;
}