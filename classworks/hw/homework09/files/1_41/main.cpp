/*
File41. ��� ���� ����� �����. �������� � ��� ������ ������������� ����� ��
��� ����.
*/


#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	int num;
	if (input)
	{
		while (input >> num)
		{
			if (num >= 0)
				output << 0 << 0 << 0 << ' ';
			else
				output << num << ' ';
		}
	}
	rename("input.txt", "output.text");
	system("pause");
	return 0;
}