
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int s1, v1, v2, s2, t;

	setlocale(LC_CTYPE, "rus");
	cout << "������� �������� s1 � ������: " << endl;;
	cin >> s1;
	cout << "������� �������� v1 � �/� : " << endl;;
	cin >> v1;
	cout << "������� �������� v2 � �/� : " << endl;;
	cin >> v2;
	cout << "������� �������� t � �������� : " << endl;;
	cin >> t;

	s2 = s1 + (t * (v1 + v2));

	cout << "s2 = " << s2 << " ������(-�)" << endl;
	system("PAUSE");
}