
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, ex;

	setlocale(LC_CTYPE, "rus");
	cout << "������� �������� ��������� a: " << endl;;
	cin >> a;
	cout << "������� �������� ��������� b: " << endl;;
	cin >> b;
	cout << "������� �������� ��������� c: " << endl;;
	cin >> c;

	ex = a;
	a = b;
	b = c;
	c = ex;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "� = " << c << endl;
	system("PAUSE");
}