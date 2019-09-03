#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct NOTEBOOK
{
	char model[21];
	struct size
	{
		float x;
		float y;
		float z;
	};
	float w;
	int price;
};

void take_inf_txt(ifstream& input)
{
	
}



int main()
{
	ifstream input("input.txt");
	ofstream output("output.txt");
	take_inf_txt(input);
	system("pause");
	return 0;
}