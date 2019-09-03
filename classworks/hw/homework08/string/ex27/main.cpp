/*
String27. ���� ����� ������������� ����� N1 � N2 � ������ S1 � S2. ��������
�� ���� ����� ����� ������, ���������� ������ N1 �������� ������ S1 �
��������� N2 �������� ������ S2 (� ��������� �������).
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	int n1, n2;
	string s1, s2, s3, s4;

	cout << "Your first string: " << endl;
	getline(cin, s1);
	cout << "Your second string: " << endl;
	getline(cin, s2);
	cout << "Count of symbols, which you want to take from begin s1: " << endl;
	cin >> n1;
	cout << "Count of symbols, which you want to take from end s2: " << endl;
	cin >> n2;


	for (int i = 0; i < n1; i++)
		s3 += s1[i];
	for (int i = s2.length() - 1; i > n2 + 1; i--)
		s4 += s2[i];
	reverse(s4.begin(), s4.end());
	s3 += s4;
	cout << "Your new string, which take first n1 symbols from s1 and last n2 symbols from s2: " << s3 << endl;
	system("pause");
	return 0;
}