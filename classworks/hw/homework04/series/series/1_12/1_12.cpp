/*
Series12.ƒан набор ненулевых целых чисел; признак его завершени€ Ч чис-
ло 0. ¬ывести количество чисел в наборе.
*/

#include <iostream>

using namespace std;

int main()
{
	int i = 0, R = 1;

	while (R != 0)
	{
		cout << "R = " << endl;
		cin >> R;
		i++;
	}
	cout << "N = " << i << endl;
	system("pause");
}