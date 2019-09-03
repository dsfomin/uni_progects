#include <iostream>

using namespace std;

int main()
{
	int k;
	setlocale(LC_CTYPE, "rus");
	cout << "Введите номер дня года: " << endl;
	cin >> k;

	if (k > 0 || k < 366)
	{
		while (k > 6)
		{
			k -= 7;
		}
		cout << "Номер дня недели: " << k << endl;
	}
	else
		cout << "Вы вышли за границы диапазона" << endl;

	system("pause");
	return 0;
}