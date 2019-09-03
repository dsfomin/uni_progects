#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	setlocale(0, "rus");
	cout << "Введите значение числа a: " << endl;
	cin >> a;
	cout << "Введите значение числа b: " << endl;
	cin >> b;
	cout << "Введите значение числа c: " << endl;
	cin >> c;

	if ((a != b) && (b != c) && (c != a))
	{
		if (c < b && c < a)
			cout << "Найменшее число c и оно равно: " << c << endl;
		else if (a < b && a < c)
			cout << "Найменшее число a и оно равно: " << a << endl;
		else if (b < a && b < c)
			cout << "Найменшее число b и оно равно: " << b << endl;
	}
	else if (a == b || b == c || c == a)
	{
		if (b > c)
			cout << "Найменшее число c и оно равно: " << c << endl;
		else if (c > a)
			cout << "Найменшее число a и оно равно: " << a << endl;
		else if (a > b)
			cout << "Найменшее число b и оно равно: " << b << endl;
		else if (a == b && b == c)
			cout << "Числа равны" << endl;
	}
	system("pause");
}