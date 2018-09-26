
#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "rus");
	double S = 1;
	int N;
	cout << "Введите n сомножителей: " << endl;
	cin >> N;
	for (double k = 1.1; N > 0; k = k + 0.1)
	{
		S *= k;
		N--;
	}
	cout << "Произведение n сомножеств = " << S << endl;
	system("pause");
}