/*
File27. Дан файл целых чисел с элементами A1, A2, ..., AN (N — количество эле-
ментов в файле). Заменить исходное расположение его элементов на сле-
дующее:
A1, AN, A2, AN–1, A3, ... .
*/


#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	vector<int> nums, res;
	int num;
	if (input)
	{
		while (input >> num)
		{
			nums.push_back(num);
		}
		if (nums.size() % 2 != 0)
		{
			for (int i = 0; i < nums.size() / 2; i++)
			{
				res.push_back(nums[i]);
				res.push_back(nums[nums.size() - i - 1]);
			}
			res.push_back(nums[nums.size() / 2]);
		}
		else
		{
			for (int i = 0; i < nums.size() / 2; i++)
			{
				res.push_back(nums[i]);
				res.push_back(nums[nums.size() - i - 1]);
			}
		}
	}
	for (int item : res)
	{
		output << item << ' ';
	}
	system("pause");
	return 0;
}