#include <iostream>
#include <string>

using namespace std;

bool CheckIfStringPalindrom(string s1)
{
	int n = s1.length();
	for (int i = 0; i < n / 2; ++i)
	{
		if (s1[i] != s1[n - i - 1])
		{
			return false;
		}
	}
	return true;
}

string MakePalindromFromString(string& s1)
{
	string add;
	string add_add;
	for (int i = s1.length() - 1; i >= 0; i--)
		add.push_back(s1[i]);
	while (add != "")
	{
		string s3 = s1;
		if (CheckIfStringPalindrom(s3 += add))
		{
			add_add = add;
		}
		add.erase(0, 1);;
	}
	s1 += add_add;
	return s1;
}

int main(void)
{
	string s1;
	cout << "String: ";
	getline(cin, s1);
	if (CheckIfStringPalindrom(s1))
		cout << "String is already palindrom: ";
	else
	{
		cout << "Your palindrom is: ";
		MakePalindromFromString(s1);
	}
	cout << s1 << endl;
	system("pause");
	return 0;
}