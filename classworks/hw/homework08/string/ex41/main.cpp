/*
String41. ���� ������, ��������� �� ������� ����, ����������� ��������� (��-
��� ��� �����������). ����� ���������� ���� � ������.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	int counter = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
		if (i != 0 && s[i] == ' ' && s[i - 1] != ' ')
			counter++;
	cout << counter + 1 << endl;
	system("pause");
	return 0;
}