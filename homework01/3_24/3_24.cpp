
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, d, b, c;

	setlocale(LC_CTYPE, "rus");
	cout << "������� �������� ������������ a: " << endl;
	cin >> a;
	cout << "������� �������� ������������ b: " << endl;
	cin >> b;
	cout << "������� �������� ������������ c: " << endl;
	cin >> c;

	if (a != 0)
	{
		d = pow(b, 2) - 4 * a * c;
		if (d < 0)
			cout << "��������� �� ����� ������������ ������." << endl;
		else
			cout << "���������� ��������� A�x2+ B�x + C = 0 ����� ������������ �����." << endl;
	}
	else
		cout << "��� �� ���������� ���������" << endl;
	system("pause");
	return 0;
}