#include <iostream>

using namespace std;

int main()
{
	float x, f;

	setlocale(0, "rus");
	cout << "������� �������� �: " << endl;
	cin >> x;

	if (x > 0)
		f = 2 * sin(x);
	else
		f = 6 - x;
	cout << "�������� ������� f(x) = " << f << endl;
	system("pause");
}