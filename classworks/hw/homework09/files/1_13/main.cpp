/*
File13. ��� ���� ����� �����. ������� ��� ����� �����, ������ �� �������
�������� ������������� ����� �� ��������� ����� (� �������� �������),
� ������ � ������������� (����� � �������� �������). ���� ����������-
��� ��� ������������� ����� � �������� ����� �����������, �� �������-
�������� �������������� ���� �������� ������.
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream plus("plus.txt");
	ofstream minus("minus.txt");
	int num;
	if (input)
	{
		while (input >> num)
		{
			if (num >= 0)
				plus << num << ' ';
			else
				minus << num << ' ';
		}
	}
	system("pause");
	return 0;
}