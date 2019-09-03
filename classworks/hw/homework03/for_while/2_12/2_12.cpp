
#include <iostream>

using namespace std;

int main()
{
	setlocale(0, "rus");
	int N, S, k;
	cout << "N = " << endl;
	cin >> N;
	k = 0;
	S = 0;
	if (N > 1)
	{
		while (S <= N)
		{
			k++;
			S += k;
		}
		S -= k;
		k--;
		cout << "K = " << k << endl;
		cout << "S = " << S << endl;
	}
	else
		cout << "ERROR" << endl;
	system("pause");
}