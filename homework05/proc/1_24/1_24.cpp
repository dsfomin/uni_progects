/*
������� ������� Even(K) ����������� ����, ������������ True, ��-
�� ����� �������� K �������� ������, � False � ��������� ������. � ��
������� ����� ���������� ������ ����� � ������ �� 10 ����� �����.
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