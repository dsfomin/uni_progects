/*
String69. Дана строка, содержащая латинские буквы и круглые скобки. Если
скобки расставлены правильно (то есть каждой открывающей соответству-
ет одна закрывающая), то вывести число 0. В противном случае вывести
или номер позиции, в которой расположена первая ошибочная закрываю-
щая скобка, или, если закрывающих скобок не хватает, число –1.
*/

#include <iostream>
#include <string>

using namespace std;

int str_strlen(const char *s)
{
	int i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return i;
}

int main()
{
	int i = 0, c1 = 0, c2 = 0, pos = 0;
	char s[100];
	cin.getline(s, 100);
	for (int i = 0; i < str_strlen(s); i++)
	{
		if (s[i] == '(')
			c1++;
		if (s[i] == ')')
		{
			c2++;
			pos = i;
		}
	}
	if (c1 == c2)
		cout << 0;
	else if (c1 > c2)
		cout << -1;
	else if (c2 > c1)
		cout << pos << endl;
	system("pause");
	return 0;
}
