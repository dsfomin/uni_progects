
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, ex;

	setlocale(LC_CTYPE, "rus");
	cout << "Введите значение переменой a: " << endl;;
	cin >> a;
	cout << "Введите значение переменой b: " << endl;;
	cin >> b;
	cout << "Введите значение переменой c: " << endl;;
	cin >> c;

	ex = a;
	a = b;
	b = c;
	c = ex;

	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "с = " << c << endl;
	system("PAUSE");
}