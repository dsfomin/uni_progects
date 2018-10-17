/*
Array41. Дан массив размера N. Найти два соседних элемента, сумма которых
максимальна, и вывести эти элементы в порядке возрастания их индексов.
*/

#include <iostream>

using namespace std;

int main()
{
	int N, max = 0, max_position;
	cout << "N = ";
	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cout << "N = ";
		cin >> arr[i];
	}

	for (int i = 0; i < N; i++)
	{
		if (arr[i] + arr[i + 1] > max)
		{
			max = arr[i] + arr[i + 1];
			max_position = i;
		}
	}

	if (arr[max_position] > arr[max_position + 1])
		cout << arr[max_position + 1] << " " << arr[max_position] << endl;
	else
		cout << arr[max_position] << " " << arr[max_position + 1] << endl;

	delete[] arr;
	system("pause");
	return 0;
}