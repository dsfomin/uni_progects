#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>

using namespace std;

int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	string text;
	if (input)
	{
		if (getline(input, text))
		{
			while (getline(input, text))
			{
				output << text << endl;
			}
		}
	}
	char oldname[] = "output.txt";
	char newname[] = "input.txt";
	input.close();
	remove("input.txt");
	rename(oldname, newname);
	system("pause");
	return 0;
}