#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream input("input.txt");
	double num, sum = 0;
	int k = 0;
	cout.precision(2);
	if (input)
	{
		while (input >> num)
		{
			if (num >= 0)
			{
				sum += num;
				k++;
			}
		}
		cout << sum / k << endl;
	}
	else
		cout << "Error" << endl;
	system("pause");
	return 0;
}