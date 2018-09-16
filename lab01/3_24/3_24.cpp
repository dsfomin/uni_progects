
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int a, d, b, c;

	setlocale(LC_CTYPE, "rus");
	cout << "Введите значение коэффициента a: " << endl;
	cin >> a;
	cout << "Введите значение коэффициента b: " << endl;
	cin >> b;
	cout << "Введите значение коэффициента c: " << endl;
	cin >> c;

	if (a != 0)
	{
		d = pow(b, 2) - 4 * a * c;
		if (d < 0)
			cout << "Уравнение не имеет вещественных корней." << endl;
		else
			cout << "Квадратное уравнение A·x2+ B·x + C = 0 имеет вещественные корни." << endl;
	}
	else
		cout << "Это не квадратное уравнение" << endl;
	system("pause");
	return 0;
}