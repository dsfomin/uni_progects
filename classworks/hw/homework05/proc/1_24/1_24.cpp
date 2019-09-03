/*
Описать функцию Even(K) логического типа, возвращающую True, ес-
ли целый параметр K является четным, и False в противном случае. С ее
помощью найти количество четных чисел в наборе из 10 целых чисел.
*/

#include <iostream>

using namespace std;

int Even(int k)
{
	if (k % 2 == 0)
		return 1;
	else
		return 0;
}

int main(void)
{
	int N = 10, K, n = 0;
	for (int i = 0; i < N; i++)
	{
		cout << "N =";
		cin >> K;
		if (Even(K))
			n++;
	}
	cout << "parnyh = " << n << endl;
	system("pause");
	return 0;
}