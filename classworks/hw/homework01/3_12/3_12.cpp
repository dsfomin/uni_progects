#include <iostream>

using namespace std;

int main()
{
	int a, b, c;

	setlocale(LC_CTYPE, "rus");
	cout << "������� �������� ��������� a: " << endl;;
	cin >> a;
	cout << "������� �������� ��������� b: " << endl;;
	cin >> b;
	cout << "������� �������� ��������� c: " << endl;;
	cin >> c;

	if (a > 0 && b > 0 && c > 0)
		cout << "������ �� ����� a, b, c �������������.\n";
	else
		cout << "����������� ������" << endl;
	system("pause");
	return 0;
}