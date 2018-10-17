/*
Array13. ƒан массив A размера N (N Ч нечетное число). ¬ывести его элементы
с нечетными номерами в пор€дке убывани€ номеров: AN, ANЦ2, ANЦ4, ..., A1.
”словный оператор не использовать.
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cout << "N = ";
	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cout << "N = ";
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i -= 2)
		cout << "N(" << i << ") = " << arr[i] << endl;
	delete[] arr;
	system("pause");
	return 0;
}