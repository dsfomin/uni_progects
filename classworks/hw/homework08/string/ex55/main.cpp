/*
String55. Дана строка-предложение на русском языке. Вывести самое длинное
слово в предложении. Если таких слов несколько, то вывести первое из
них. Словом считать набор символов, не содержащий пробелов, знаков
препинания и ограниченный пробелами, знаками препинания или нача-
лом/концом строки.
*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int c = 0, pos = 0, prev = 0;
	string s;
	getline(cin, s);
	for (int i = 0; i < s.length(); i++)
	{
		if (!(s[i] >= 65 && s[i] <= 122))
		{
			prev = c;
			c = 0;
			continue;
		}
		if ((s[i] >= 65 && s[i] <= 122) || s[i] != '\0')
		{
			c++;
			if (c  > prev)
				pos = i;
		}
	}
	string res;
	for (int i = pos; s[i] >= 65 && s[i] <= 122; i--)
		res += s[i];
	reverse(res.begin(), res.end());
	cout << res << endl;
	system("pause");
	return 0;
}