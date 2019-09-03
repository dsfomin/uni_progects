#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<double> Opus(const vector<int>& v)
{
	vector<double> res;
	double x, y, x12, x23, x31, y12, y23, y31, z1, z2, z3, zx, zy, z, r;

	x12 = v[0] - v[2];
	x23 = v[2] - v[4];
	x31 = v[4] - v[0];
	y12 = v[1] - v[3];
	y23 = v[3] - v[5];
	y31 = v[5] - v[1];
	z1 = pow(v[0], 2) + pow(v[1], 2);
	z2 = pow(v[2], 2) + pow(v[3], 2);
	z3 = pow(v[4], 2) + pow(v[5], 2);
	zx = y12 * z3 + y23 * z1 + y31 * z2;
	zy = x12 * z3 + x23 * z1 + x31 * z3;
	z = x12 * y31 - y12 * x31;
	x = -zx / (2 * z);
	y = zy / (2 * z);
	r = sqrt(pow((v[0] - x), 2) + (pow((v[1] - y), 2)));
	res.push_back(x);
	res.push_back(y);
	res.push_back(r);
	return res;
}

vector<double> Vpus(const vector<int>& v)
{
	vector<double> res;
	double x, y, r, l23, l13, l12;
	l12 = sqrt(pow(v[0] - v[2], 2) + pow(v[1] - v[3], 2));
	l23 = sqrt(pow(v[2] - v[4], 2) + pow(v[3] - v[5], 2));
	l13 = sqrt(pow(v[0] - v[4], 2) + pow(v[1] - v[5], 2));
	y = ((l23 * v[1] + l13 * v[3] + l12 * v[5]) / (l23 + l13 + l12));
	x = ((l23 * v[0] + l13 * v[2] + l12 * v[4]) / (l23 + l13 + l12));
	r = (v[0] * v[5] + v[4] * y - v[5] * x - v[0] * y - v[1] * v[4] + v[1] * x) / (sqrt(pow(v[4] - v[0], 2) + pow(v[5] - v[1], 2)));
	res.push_back(x);
	res.push_back(y);
	res.push_back(r);
	return res;
}

bool Proverka_syc(const vector<int>& v)
{
	double a, b, c;

	a = sqrt(pow(v[0] - v[2], 2) + pow(v[1] - v[3], 2));
	b = sqrt(pow(v[2] - v[4], 2) + pow(v[3] - v[5], 2));
	c = sqrt(pow(v[0] - v[4], 2) + pow(v[1] - v[5], 2));

	if ((a >= b + c) || (b >= a + c) || (c >= a + b))
		return false;
	else
		return true;
}

int main()
{
	setlocale(0, "rus");
	vector<int> v(6);
	for (int& i : v)
	{
		cin >> i;
	}
	if (Proverka_syc(v))
	{
		vector<double> vv = Opus(v);
		cout.precision(2);
		cout << "Координаты описаной окружности: x = " << vv[0] << " y = " << vv[1] << endl;
		cout << "Радиус описаной окружности равен: " << vv[2] << endl;
		vector<double> vvv = Vpus(v);
		cout << "Координаты вписаной окружности: x = " << vvv[0] << " y = " << vvv[1] << endl;
		cout << "Радиус вписаной окружности равен: " << vvv[2] << endl;
	}
	else
		cout << "Такой триугольник не существует" << endl;
	system("pause");
	return 0;
}
