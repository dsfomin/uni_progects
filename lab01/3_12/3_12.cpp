#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	setlocale(LC_CTYPE, "rus");
	cout << "Введите значение переменой a: " << endl;;
	cin >> a;
	cout << "Введите значение переменой b: " << endl;;
	cin >> b;
	cout << "Введите значение переменой c: " << endl;;
	cin >> c;

	if (a > 0 && b > 0 && c > 0)
		cout << "Каждое из чисел a, b, c положительное.\n";
	else
		cout << "Утверждение ложное" << endl;
	system("pause");
	return 0;
}