#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "RUS");

	int a, temp, b;

	cout << "������� �����: " << endl;
	cin >> a;

	while (a > 0)
	{
		temp = a;
		b = 0;

		while (temp != 0)
		{
			b = b * 10 + temp % 10;
			temp /= 10;
			if (a == b)
				cout << "������ ��������� - " << a << endl;
		}
		a--;
	}
	system("pause");
}