
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, b, c, P;

	setlocale(LC_CTYPE, "rus");
	cout << "Введите длину 1 катета: " << endl;
	cin >> a;
	cout << "Введите длину 2 катета: " << endl;
	cin >> b;

	if (a > 0 && b > 0)
	{
		c = sqrt(pow(a, 2) + pow(b, 2));
		P = a + b + c;
		cout << "Гипотенуза равна: " << c << endl;
		cout << "Периметр равен: " << P << endl;
	}
	else
		cout << "Вы ввели неправильные значения" << endl;
	system("PAUSE");
}