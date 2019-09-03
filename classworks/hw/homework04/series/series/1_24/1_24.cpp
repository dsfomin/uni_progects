/*
Series24.Дано целое число N и набор из N целых чисел, содержащий по край -
ней мере два нуля.Вывести сумму чисел из данного набора, расположен -
ных между последними двумя нулями(если последние нули идут подряд,
то вывести 0).
*/

#include <iostream>

using namespace std;

int main(void)
{
	int n;
	cout << "N:" << endl;
	cin >> n;
	int i, f, sum = 0, tempsum = 0;
	for (i = 1; i <= n; ++i) {
		cout << "Num = ";
		cin >> f;
		tempsum += f;
		if (f == 0) {
			sum = tempsum;
			tempsum = 0;
		}
	}
	cout << "sum = " << sum << endl;
	system("pause");
	return 0;
}

