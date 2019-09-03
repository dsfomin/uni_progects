
#include <iostream>
#include <cmath>

using namespace std;

unsigned long factorial(unsigned long number)
{
	if (number <= 1)
		return 1;
	else
		return number * factorial(number - 1);
}

int main()
{
	setlocale(0, "rus");
	double X, Z = 1;
	int N;
	cout << "������� n ���������: " << endl;
	cin >> N;
	cout << "������� �������� X: " << endl;
	cin >> X;
	for (; N != 0;)
	{
		Z = Z + (pow(-1, N) * pow(X, 2 * N) / factorial(2 * N));
		N--;
	}
	cout << "�������� = " << Z << endl;
	system("pause");
}