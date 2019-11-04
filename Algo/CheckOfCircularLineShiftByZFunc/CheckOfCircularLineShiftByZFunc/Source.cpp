#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template<class T>
vector<int> z_function(const T& str)
{
	int n = str.size();
	vector<int> answer(n, 0);
	int l, r;
	l = 0;
	r = 1;
	for (int i = 1; i < n; ++i)
	{
		if (i < r)
		{
			answer[i] = min(r - i, answer[i - l]);
		}
		while ((i + answer[i] < n) && (str[answer[i]] == str[i + answer[i]]))
		{
			++answer[i];
		}
		if (i + answer[i] > r)
		{
			l = i;
			r = i + answer[i];
		}
	}
	return answer;
}

template<class T>
vector<int> search_kmp(const T& pattern, const T& text, const T& marker = T("#"))
{
	vector<int> zf = z_function(pattern + marker + text);
	int ps = pattern.size();
	int ts = text.size();
	vector<int> answer;
	answer.reserve(ts);
	for (int i = 0; i + ps - 1 < text.size(); ++i)
	{
		if (zf[i + ps + 1] == ps)
		{
			answer.push_back(i);
		}
	}
	return answer;
}

template<class T>
bool CheckByZ_Function(const T& str_beg, const T& str_cyc, const T& marker = T("#"))
{
	if (str_beg.empty() && str_cyc.empty()) return true;
	if (str_beg.size() != str_cyc.size()) return false;
	string str = str_beg + marker + str_cyc + str_cyc;
	int n = str.size();
	vector<int> answer(n, 0);
	int l, r;
	l = 0;
	r = 1;
	for (int i = str_beg.size() + 1; i < n; ++i)
	{
		if (i < r)
		{
			answer[i] = min(r - i, answer[i - l]);
		}
		while ((i + answer[i] < n) && (str[answer[i]] == str[i + answer[i]]))
		{
			++answer[i];
		}
		if (answer[i] == str_beg.size()) return true;
		if (i + answer[i] > r)
		{
			l = i;
			r = i + answer[i];
		}
	}
	return false;
}

int main()
{
	string str1, str2;
	cin >> str1;
	cin >> str2;
	string str(str2 + str2);
	vector<int> mas = search_kmp(str1, str);
	cout << CheckByZ_Function(str1, str2) << endl;
	cout << mas[0] << endl << endl;

	cout << CheckByZ_Function(string("abc"), string("cab")) << endl;
	cout << CheckByZ_Function(string("abcdef"), string("defabc")) << endl;
	cout << CheckByZ_Function(string("lulllluu"), string("luululll")) << endl;
	cout << CheckByZ_Function(string("ryyyyttou"), string("yyyttoury")) << endl;
	cout << CheckByZ_Function(string("dr"), string("rd")) << endl;
	cout << CheckByZ_Function(string("hiih"), string("hiih")) << endl;
	cout << CheckByZ_Function(string("artor"), string("torar")) << endl;
	cout << CheckByZ_Function(string("a"), string("a")) << endl;
	cout << CheckByZ_Function(string(""), string("")) << endl;

	system("pause>nul");
	return 0;
}