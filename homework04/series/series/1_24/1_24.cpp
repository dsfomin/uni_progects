/*
Series24.���� ����� ����� N � ����� �� N ����� �����, ���������� �� ���� -
��� ���� ��� ����.������� ����� ����� �� ������� ������, ���������� -
��� ����� ���������� ����� ������(���� ��������� ���� ���� ������,
�� ������� 0).
*/

#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cout << "N:" << endl;
	cin >> n;
	int i, f, sum = 0, tempsum = 0;
	for (i = 1; i <= n; ++i) {
		cout << "Num = ";
		cin >> f;
		tempsum += f;
		if (f == 0) {
			sum = tempsum;
			tempsum = 0;
		}
	}
	cout << "sum = " << sum << endl;
	system("pause");
	return 0;
}

