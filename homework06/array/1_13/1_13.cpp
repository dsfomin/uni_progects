/*
Array13. ��� ������ A ������� N (N � �������� �����). ������� ��� ��������
� ��������� �������� � ������� �������� �������: AN, AN�2, AN�4, ..., A1.
�������� �������� �� ������������.
*/

#include <iostream>

using namespace std;

int main()
{
	int N;
	cout << "N = ";
	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cout << "N = ";
		cin >> arr[i];
	}

	for (int i = N - 1; i >= 0; i -= 2)
		cout << "N(" << i << ") = " << arr[i] << endl;
	delete[] arr;
	system("pause");
	return 0;
}