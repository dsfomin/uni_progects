
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(0, "rus");
	int N, K;
	double S = 0, Z = 0;
	cout << "������� N ������������: " << endl;
	cin >> N;
	cout << "������� ������� ���������� K: " << endl;
	cin >> K;
	for (; N > 0;)
	{
		Z = pow(N, K);
		S += Z;
		N--;
	}
	cout << "����� N ��������� = " << S << endl;
	system("pause");
}