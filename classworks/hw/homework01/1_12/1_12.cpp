
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, P;

	setlocale(LC_CTYPE, "rus");
	cout << "������� ����� 1 ������: " << endl;
	cin >> a;
	cout << "������� ����� 2 ������: " << endl;
	cin >> b;

	if (a > 0 && b > 0)
	{
		c = sqrt(pow(a, 2) + pow(b, 2));
		P = a + b + c;
		cout << "���������� �����: " << c << endl;
		cout << "�������� �����: " << P << endl;
	}
	else
		cout << "�� ����� ������������ ��������" << endl;
	system("PAUSE");
}