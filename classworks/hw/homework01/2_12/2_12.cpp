
#include <iostream>

using namespace std;

int main()
{
	int n, k, d, f;
	setlocale(LC_CTYPE, "rus");
	cout << "������� ����������� ����������� �����:  " << endl;
	cin >> n;

	k = n % 10;
	d = n % 100 / 10;
	f = n / 100;
	if (n < 100 || n > 999)
		cout << "����� �� �����������";
	else
		cout << "�������� �����: " << k << d << f << endl;

	system("pause");
	return 0;
}