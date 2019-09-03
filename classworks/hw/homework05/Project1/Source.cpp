#include <iostream>

using namespace std;

int	count_of_elem(int *arr, int a, int b)
{
	int i = 0, n = 0;
	while (arr[i] != a)
		i++;
	i++;
	while (arr[i] != b)
	{
		i++;
		n++;
	}
	n += 2;
	return n;
}

int	sum_after_max(int *arr,	int n)
{
	int max = 0, i = 0, sum = 0, f;
	for (; i < n; i++)
		if (arr[i] > max)
			max = i;
	i = max;
	for (; i < n; i++)
		sum += arr[i];
	return sum;
}

int main()
{
	int N, a, b, r, sum;
	cout << "N = " << endl;
	cin >> N;
	cout << "A = " << endl;
	cin >> a;
	cout << "B = " << endl;
	cin >> b;

	int *arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cout << "element of arr = ";
		cin >> arr[i];
	}
	r = count_of_elem(arr, a, b);
	cout << "1) count of elems in diapozon [a, b] = " << r << endl;
	sum = sum_after_max(arr, N);
	cout << "2) sum of elems after max elem =" << sum << endl;
	system("pause");
	return 0;
}