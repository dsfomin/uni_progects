/*
Описать функцию IsLeapYear(Y) логического типа, которая возвращает
True, если год Y (целое положительное число) является високосным, и
False в противном случае. Вывести значение функции IsLeapYear для пяти
данных значений параметра Y. Високосным считается год, делящийся на 4,
за исключением тех годов, которые делятся на 100 и не делятся на 400.
*/

#include <iostream>

using namespace std;

int IsLeapYear(int Y)
{
	if (Y % 4 == 0)
	{
		if ((Y % 100 == 0) && (Y % 400 != 0))
			return 0;
		else
			return 1;
	}
	else
		return 0;
}

int main(void)
{
	int y;
	for (int i = 0; i < 5; i++)
	{
		cout << "year number =" << endl;
		cin >> y;
		if (IsLeapYear(y))
			cout << "y = " << y << " - vusokosnyi" << endl;
		else
			cout << "y = " << y << " - ne vusokosnyi" << endl;
	}
	system("pause");
	return 0;
}
