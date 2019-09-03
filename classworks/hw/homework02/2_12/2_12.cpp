#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int N;
	double Pi = 3.14;
	float R, S, L, D, Z;

	setlocale(0, "rus");
	cout << "¬ведите номер и значение: " << endl;
	cin >> N >> Z;


	if (Z > 0)
	{
		switch (N)
		{
		case 1:
			R = Z;
			cout << "R = " << R << endl;
			cout << "D = " << 2 * R << endl;
			cout << "L = " << 2 * Pi * R << endl;
			cout << "S = " << Pi * pow(R, 2) << endl;
			break;
		case 2:
			D = Z;
			cout << "R = " << D / 2 << endl;
			cout << "D = " << D << endl;
			cout << "L = " << 2 * Pi * D / 2 << endl;
			cout << "S = " << Pi * pow(D / 2, 2) << endl;
			break;
		case 3:
			L = Z;
			cout << "R = " << L / 2 / Pi << endl;
			cout << "D = " << L / Pi << endl;
			cout << "L = " << L << endl;
			cout << "S = " << pow(L, 2) / 4 / Pi << endl;
			break;
		case 4:
			S = Z;
			cout << "R = " << sqrt(S / Pi) << endl;
			cout << "D = " << sqrt(4 * S / Pi) << endl;
			cout << "L = " << sqrt(4 * S * Pi) << endl;
			cout << "S = " << S << endl;
			break;
		default:
			cout << "Wrong operator" << endl;
		}
	}
	else
		cout << "Wrong operator" << endl;
	system("pause");
}