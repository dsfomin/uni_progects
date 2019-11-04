#include <iostream> 
#include <string>
#include <vector>
#include <chrono>

using namespace std;

int SymbolNumDegree = 8;
long long int HashBase = 9213693951;

ostream & operator<<(ostream & c, vector<pair<int, int>> x)
{
	for (size_t i = 0; i < x.size(); ++i)
		c << x[i].first << "-" << x[i].second << " ";
	cout << endl;
	return c;
}

template <typename T>
int hash_(T *x, int sz)
{
	int s = x[0];
	for (int i = 1; i < sz; ++i)
	{
		s <<= SymbolNumDegree;
		s += x[i];
		s %= HashBase;

		while (s < 0)
			s += HashBase;
	}
	while (s < 0)
		s += HashBase;
	return s;
}

vector<pair<int, int>> searchRabinKarp2D(int ** haystack, int h1, int w1, int ** needle, int h2, int w2)
{
	vector<pair<int, int>> res;

	int h = 1;

	for (int i = 0; i < w2 - 1; ++i)
		h = (h << SymbolNumDegree) % HashBase;

	int *needleHash = new int[h2];

	for (int i = 0; i < h2; ++i)
	{
		needleHash[i] = hash_(needle[i], w2);
		while (needleHash[i] < 0)
			needleHash[i] += HashBase;
	}
	int hp = hash_(needleHash, h2);
	if (hp < 0)
		hp += HashBase;

	int** tmpHash = new int*[w1 - w2 + 1];
	for (int i = 0; i <= w1 - w2; ++i)
		tmpHash[i] = new int[h1];

	//CALC PRIMARY HASH
	for (int i = 0; i < h1; ++i)
	{
		tmpHash[0][i] = hash_(haystack[i], w2);
		while (tmpHash[0][i] < 0)
			tmpHash[0][i] += HashBase;
		for (int j = 1; j <= w1 - w2; ++j)
		{
			tmpHash[j][i] = (((tmpHash[j - 1][i] - haystack[i][j - 1] * h) << SymbolNumDegree) + haystack[i][j + w2 - 1]) % HashBase;
			while (tmpHash[j][i] < 0)
				tmpHash[j][i] += HashBase;
		}
	}

	//CALC SECONDARY HASH AND CHECK FOR EQUALITY
	for (int i = 0; i <= w1 - w2; ++i)
	{
		int cur = hash_(tmpHash[i], h2);
		while (cur < 0)
			cur += HashBase;
		if (cur == hp)
			res.push_back(pair<int, int>({ 0, i }));
		for (int j = 1; j <= h1 - h2; ++j)
		{
			cur = (((cur - tmpHash[i][j - 1] * h) << SymbolNumDegree) + tmpHash[i][j + h2 - 1]) % HashBase;
			while (cur < 0)
				cur += HashBase;
			if (cur == hp)
				res.push_back(pair<int, int>({ j, i }));
		}
	}

	delete[] needleHash;
	for (int i = 0; i <= w1 - w2; ++i)
		delete[] tmpHash[i];
	delete[] tmpHash;
	return res;
}

int main() {
	int **haystack = nullptr, **needle = nullptr;
	int hWidth, hHeight, nWidth, nHeight;

	bool sam = 1;

	if (!sam) {
		srand(clock());
		cout << "Enter height and width of text : ";
		cin >> hHeight;
		cin >> hWidth;
		cout << "Enter height and width of pattern : ";
		cin >> nHeight;
		cin >> nWidth;
		haystack = new int*[hHeight];
		needle = new int*[nHeight];

		cout << "TEXT IS : ";

		for (int i = 0; i < hHeight; ++i)
		{
			haystack[i] = new int[hWidth];
			for (int j = 0; j < hWidth; ++j)
			{
				haystack[i][j] = (int)rand() % 10;
				cout << haystack[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		if (nHeight*nWidth <= 700)
		{
			cout << "PATTERN IS : ";

			for (int i = 0; i < nHeight; ++i)
			{
				needle[i] = new int[nWidth];
				for (int j = 0; j < nWidth; ++j)
				{
					needle[i][j] = (int)rand() % 10;
					cout << needle[i][j] << " ";
				}
				cout << endl;
			}
		}
		cout << endl;
	}
	else {
		cout << "Enter height and width : " << endl;
		cin >> hHeight >> hWidth;
		cout << "ENTER TEXT : ";
		haystack = new int*[hHeight];
		for (int i = 0; i < hHeight; ++i)
		{
			haystack[i] = new int[hWidth];
			for (int j = 0; j < hWidth; ++j) {
				int tmp = 0;
				cin >> tmp;
				haystack[i][j] = tmp;
			}
		}
		cout << "Enter height and width of pattern : ";
		cin >> nHeight >> nWidth;
		cout << "ENTER PATTERN  : ";
		needle = new int*[nHeight];
		for (int i = 0; i < nHeight; ++i)
		{
			needle[i] = new int[nWidth];
			for (int j = 0; j < nWidth; ++j) {
				int tmp = 0;
				cin >> tmp;
				needle[i][j] = tmp;
			}
		}
	}

	vector<pair<int, int>> res;

	time_t t = clock();
	res = searchRabinKarp2D(haystack, hHeight, hWidth, needle, nHeight, nWidth);
	t = clock() - t;
	cout << "Rabin Karp search worked " << t << " clocks." << endl;
	cout << "RESULT <row-column> (begin from 0) : " << res << endl;
	cout << endl;

	for (int i = 0; i < hHeight; ++i)
		delete[] haystack[i];
	delete[] haystack;
	for (int i = 0; i < nHeight; ++i)
		delete[] needle[i];
	delete[] needle;

	system("pause>nul");
	return 0;
}