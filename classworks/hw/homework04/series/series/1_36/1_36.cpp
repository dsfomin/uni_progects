/*
Series36. ���� ����� ����� K, � ����� K ������� ��������� ����� �����. ��-
���� ����� �������� �� ����� ���� ���������, ��������� ��� ����������
�������� ����� 0. ����� ���������� �������, �������� ������� ��������-
��.
*/

#include <iostream>

using namespace std;

int main()
{
	int k, l = 0;

	cout << "k = " << endl;
	cin >> k;

	while (k != 0)
	{
		int i = 0, j = 0, r = 1, r1 = 0;
		while (r != 0)
		{
			cout << "Num =";
			cin >> r;
			if (r > r1)
			{
				r1 = r;
				i++;
			}
			j++;
		}
		if (j == ++i)
			l++;
		k--;
	}
	cout << "N = " << l << endl;
	system("pause");
	return 0;
}