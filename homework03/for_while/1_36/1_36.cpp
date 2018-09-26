
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	setlocale(0, "rus");
	int N, K;
	double S = 0, Z = 0;
	cout << "¬ведите N сомножителей: " << endl;
	cin >> N;
	cout << "¬ведите степень возведени€ K: " << endl;
	cin >> K;
	for (; N > 0;)
	{
		Z = pow(N, K);
		S += Z;
		N--;
	}
	cout << "—умма N елементов = " << S << endl;
	system("pause");
}