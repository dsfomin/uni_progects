#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <time.h>

using namespace std;

#define d 256

void computeLPSArray(char* pat, int M, int* lps)
{
	int len = 0;

	lps[0] = 0; 

	int i = 1;
	while (i < M) {
		if (pat[i] == pat[len]) {
			len++;
			lps[i] = len;
			i++;
		}
		else{
 
			if (len != 0) {
				len = lps[len - 1];

			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

void KMPSearch(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	int *lps = new int[M];
	
	computeLPSArray(pat, M, lps);

	int i = 0; 
	int j = 0; 
	while (i < N) {
		if (pat[j] == txt[i]) {
			j++;
			i++;
		}

		if (j == M) {
			cout << "Pattern found at index " << i - j << endl;
			j = lps[j - 1];
		}

		else if (i < N && pat[j] != txt[i]) {
			
			if (j != 0)
				j = lps[j - 1];
			else
				i = i + 1;
		}
	}
}

void search_Rabin_Karp(char pat[], char txt[], int q)
{
	int M = strlen(pat);
	int N = strlen(txt);
	int i, j;
	int p = 0; 
	int t = 0;  
	int h = 1;
 
	for (i = 0; i < M - 1; i++)
		h = (h * d) % q;
  
	for (i = 0; i < M; i++)
	{
		p = (d * p + pat[i]) % q;
		t = (d * t + txt[i]) % q;
	}

	for (i = 0; i <= N - M; i++)
	{
		if (p == t)
		{
			for (j = 0; j < M; j++)
			{
				if (txt[i + j] != pat[j])
					break;
			}

			if (j == M)
				cout << "Pattern found at index " << i << endl;
		}
 
		if (i < N - M)
		{
			t = (d*(t - txt[i] * h) + txt[i + M]) % q;
 
			if (t < 0)
				t = (t + q);
		}
	}
}

void search_Naive(char* pat, char* txt)
{
	int M = strlen(pat);
	int N = strlen(txt);

	for (int i = 0; i <= N - M; i++) {
		int j;

		for (j = 0; j < M; j++)
			if (txt[i + j] != pat[j])
				break;

		if (j == M)
			cout << "Pattern found at index "
			<< i << endl;
	}
}

void badCharHeuristic(string str, int size, int badchar[d])
{
	int i;
  
	for (i = 0; i < d; i++)
		badchar[i] = -1;

	for (i = 0; i < size; i++)
		badchar[(int)str[i]] = i;
}

void search_Boyer_Moore(string txt, string pat)
{
	int m = pat.size();
	int n = txt.size();

	int badchar[d];

	badCharHeuristic(pat, m, badchar);

	int s = 0;
	while (s <= (n - m))
	{
		int j = m - 1;

		while (j >= 0 && pat[j] == txt[s + j])
			j--;
		if (j < 0)
		{
			cout << "Pattern found at index " << s << endl;
			s += (s + m < n) ? m - badchar[txt[s + m]] : 1;
		}
		else
			s += max(1, j - badchar[txt[s + j]]);
	}
}

int main() {
	char txt[] = "AABAACAADAABAABA";
	char pat[] = "AABA";
	string txt1 = txt;
	string pat1 = pat;

	clock_t start = clock();
	KMPSearch(pat, txt);
	clock_t end = clock();
	double seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << seconds << " s" << endl;

	start = clock();
	search_Boyer_Moore(txt1, pat1);
	 end = clock();
	 seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << seconds << " s" << endl;

	 start = clock();
	search_Naive(pat, txt);
	 end = clock();
	 seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << seconds << " s" << endl;

	 start = clock();
	search_Rabin_Karp(pat, txt, 101);
	 end = clock();
	 seconds = (double)(end - start) / CLOCKS_PER_SEC;
	cout << seconds << " s" << endl;
	
	
	
	
	system("pause>nul");
	return 0;
}