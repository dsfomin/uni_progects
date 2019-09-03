/*
String13. Дана строка. Подсчитать количество содержащихся в ней цифр.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string s;
	cout << "Your string: ";
	getline(cin, s);
	int counter = 0;
	for (int i = 0; s[i] != '\0'; i++)
		if (s[i] > 47 && s[i] < 58)
			counter++;
	cout << "Count of digits in string is: " << counter << endl;
	system("pause");
	return 0;
}