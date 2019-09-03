/*
Series36. Дано целое число K, а также K наборов ненулевых целых чисел. Ка-
ждый набор содержит не менее двух элементов, признаком его завершения
является число 0. Найти количество наборов, элементы которых возраста-
ют.
*/

#include <iostream>

using namespace std;

int main()
{
	int k, l = 0;

	cout << "k = " << endl;
	cin >> k;

	while (k != 0)
	{
		int i = 0, j = 0, r = 1, r1 = 0;
		while (r != 0)
		{
			cout << "Num =";
			cin >> r;
			if (r > r1)
			{
				r1 = r;
				i++;
			}
			j++;
		}
		if (j == ++i)
			l++;
		k--;
	}
	cout << "N = " << l << endl;
	system("pause");
	return 0;
}