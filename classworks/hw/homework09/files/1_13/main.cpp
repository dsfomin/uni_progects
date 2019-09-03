/*
File13. Дан файл целых чисел. Создать два новых файла, первый из которых
содержит положительные числа из исходного файла (в обратном порядке),
а второй — отрицательные (также в обратном порядке). Если положитель-
ные или отрицательные числа в исходном файле отсутствуют, то соответ-
ствующий результирующий файл оставить пустым.
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