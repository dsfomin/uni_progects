#include <iostream>

using namespace std;

int main()
{
	int k;
	setlocale(LC_CTYPE, "rus");
	cout << "������� ����� ��� ����: " << endl;
	cin >> k;

	if (k > 0 || k < 366)
	{
		while (k > 6)
		{
			k -= 7;
		}
		cout << "����� ��� ������: " << k << endl;
	}
	else
		cout << "�� ����� �� ������� ���������" << endl;

	system("pause");
	return 0;
}