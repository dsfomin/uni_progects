#include <iostream>

using namespace std;

int main()
{
	float x, f;

	setlocale(0, "rus");
	cout << "Введите значение х: " << endl;
	cin >> x;

	if (x > 0)
		f = 2 * sin(x);
	else
		f = 6 - x;
	cout << "Значение функции f(x) = " << f << endl;
	system("pause");
}