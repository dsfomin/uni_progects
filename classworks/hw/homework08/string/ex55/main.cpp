/*
String55. ���� ������-����������� �� ������� �����. ������� ����� �������
����� � �����������. ���� ����� ���� ���������, �� ������� ������ ��
���. ������ ������� ����� ��������, �� ���������� ��������, ������
���������� � ������������ ���������, ������� ���������� ��� ����-
���/������ ������.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int c = 0, pos = 0, prev = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (!(s[i] >= 65 && s[i] <= 122))
		{
			prev = c;
			c = 0;
			continue;
		}
		if ((s[i] >= 65 && s[i] <= 122) || s[i] != '\0')
		{
			c++;
			if (c  > prev)
				pos = i;
		}
	}
	string res;
	for (int i = pos; s[i] >= 65 && s[i] <= 122; i--)
		res += s[i];
	reverse(res.begin(), res.end());
	cout << res << endl;
	system("pause");
	return 0;
}