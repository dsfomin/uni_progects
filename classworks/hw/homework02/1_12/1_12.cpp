#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	setlocale(0, "rus");
	cout << "������� �������� ����� a: " << endl;
	cin >> a;
	cout << "������� �������� ����� b: " << endl;
	cin >> b;
	cout << "������� �������� ����� c: " << endl;
	cin >> c;

	if ((a != b) && (b != c) && (c != a))
	{
		if (c < b && c < a)
			cout << "��������� ����� c � ��� �����: " << c << endl;
		else if (a < b && a < c)
			cout << "��������� ����� a � ��� �����: " << a << endl;
		else if (b < a && b < c)
			cout << "��������� ����� b � ��� �����: " << b << endl;
	}
	else if (a == b || b == c || c == a)
	{
		if (b > c)
			cout << "��������� ����� c � ��� �����: " << c << endl;
		else if (c > a)
			cout << "��������� ����� a � ��� �����: " << a << endl;
		else if (a > b)
			cout << "��������� ����� b � ��� �����: " << b << endl;
		else if (a == b && b == c)
			cout << "����� �����" << endl;
	}
	system("pause");
}