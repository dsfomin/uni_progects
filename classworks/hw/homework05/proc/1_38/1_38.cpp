/*
������� ������� Power2(A, N) ������������� ����, ��������� ����-
���� AN (A � ������������, N � ����� ��������) �� ��������� �����-
���:
A0 = 1;
AN = A�A�...�A (N ������������), ���� N > 0;
AN = 1/(A�A�...�A) (|N| ������������), ���� N < 0.
� ������� ���� ������� ����� AK, AL, AM, ���� ���� ����� A, K, L, M.
*/

#include <iostream>
#include <cmath>

using namespace std;

float Power2(int A, int N)
{
	if (N > 0 || N < 0)
		return (pow(A, N));
	else
		return 1;
}

int main(void)
{
	int A, K, L, M;
	cout << "A = " << endl;
	cin >> A;
	cout << "K = " << endl;
	cin >> K;
	cout << "L = " << endl;
	cin >> L;
	cout << "M = " << endl;
	cin >> M;

	cout << "AK = " << Power2(A, K) << endl;
	cout << "AL = " << Power2(A, L) << endl;
	cout << "AM = " << Power2(A, M) << endl;
	system("pause");
	return 0;
}
