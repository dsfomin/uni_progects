/*
Array27. ��� ������ ��������� ����� ����� ������� N. ���������, ����������
�� � ��� ������������� � ������������� �����. ���� ����������, �� ��-
����� 0, ���� ���, �� ������� ���������� ����� ������� ��������, ����-
������� ��������������.
*/

#include <iostream>

using namespace std;

int main()
{
	int N, temp = 0;
	cout << "N = ";
	cin >> N;

	int* arr = new int[N];

	for (int i = 0; i < N; i++)
	{
		cout << "N_arr = ";
		cin >> arr[i];
	}

	for (int i = 0; i < N; i += 2)
	{
		if (arr[i] > 0)
		{
			temp++;
			if (arr[i + 1] < 0 && i + 1 < N)
				temp++;
		}
		else if (arr[0] < 0)
		{
			if (arr[i] < 0)
			{
				temp++;
				if (arr[i + 1] > 0 && i + 1 < N)
					temp++;
			}
		}
	}

	if (temp == N)
		cout << "0" << endl;
	else
		cout << temp << endl;

	delete[] arr;
	system("pause");
	return 0;
}