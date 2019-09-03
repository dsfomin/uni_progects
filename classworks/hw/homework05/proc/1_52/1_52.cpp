/*
������� ������� IsLeapYear(Y) ����������� ����, ������� ����������
True, ���� ��� Y (����� ������������� �����) �������� ����������, �
False � ��������� ������. ������� �������� ������� IsLeapYear ��� ����
������ �������� ��������� Y. ���������� ��������� ���, ��������� �� 4,
�� ����������� ��� �����, ������� ������� �� 100 � �� ������� �� 400.
*/

#include <iostream>

using namespace std;

int IsLeapYear(int Y)
{
	if (Y % 4 == 0)
	{
		if ((Y % 100 == 0) && (Y % 400 != 0))
			return 0;
		else
			return 1;
	}
	else
		return 0;
}

int main(void)
{
	int y;
	for (int i = 0; i < 5; i++)
	{
		cout << "year number =" << endl;
		cin >> y;
		if (IsLeapYear(y))
			cout << "y = " << y << " - vusokosnyi" << endl;
		else
			cout << "y = " << y << " - ne vusokosnyi" << endl;
	}
	system("pause");
	return 0;
}
