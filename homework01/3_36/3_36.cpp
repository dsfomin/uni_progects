#include <iostream>

using namespace std;

int main()
{
	int x1, x2, y1, y2;

	setlocale(LC_CTYPE, "rus");
	cout << "Введите координаты x1 (местоположение ладьи): " << endl;
	cin >> x1;
	cout << "Введите координаты y1 (местоположение ладьи): " << endl;
	cin >> y1;
	cout << "Введите координаты x2 (проверка): " << endl;
	cin >> x2;
	cout << "Введите координаты y2 (проверка): " << endl;
	cin >> y2;
	if ((x1 < 9 && x1 > 0) && (y1 < 9 && y1 > 0) && (x2 < 9 && x2 > 0) && (y2 < 9 && y2 > 0))
	{
		if ((x1 == x2) || (y1 == y2))
			cout << "Ладья за один ход может перейти с одного поля на другое." << endl;
		else
			cout << "Ладья за один ход не может перейти с одного поля на другое." << endl;
	}
	else
		cout << "Вы вышли за границы диапазона" << endl;
	system("pause");
	return 0;
}