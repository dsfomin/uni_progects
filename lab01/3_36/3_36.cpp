#include <iostream>

using namespace std;

int main()
{
	int x1, x2, y1, y2;

	setlocale(LC_CTYPE, "rus");
	cout << "������� ���������� x1 (�������������� �����): " << endl;
	cin >> x1;
	cout << "������� ���������� y1 (�������������� �����): " << endl;
	cin >> y1;
	cout << "������� ���������� x2 (��������): " << endl;
	cin >> x2;
	cout << "������� ���������� y2 (��������): " << endl;
	cin >> y2;
	if ((x1 < 9 && x1 > 0) && (y1 < 9 && y1 > 0) && (x2 < 9 && x2 > 0) && (y2 < 9 && y2 > 0))
	{
		if ((x1 == x2) || (y1 == y2))
			cout << "����� �� ���� ��� ����� ������� � ������ ���� �� ������." << endl;
		else
			cout << "����� �� ���� ��� �� ����� ������� � ������ ���� �� ������." << endl;
	}
	else
		cout << "�� ����� �� ������� ���������" << endl;
	system("pause");
	return 0;
}