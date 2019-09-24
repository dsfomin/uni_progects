#include <string>
#include <iostream>
#include <vector>

#include "readAndSortVec.h"

void sw(string &a, string &b) {
	string temp = a;
	a = b;
	b = temp;
	return;
}

bool check(long ramSize, long currentSize, string &temp) {
	return (currentSize + temp.size() <= ramSize) ? true : false;
}

bool compareWords(string &a, string &b) {
	//checks if a<b returns true else false
	for (int i = 0; i < a.size() && i < b.size(); i++) {
		if ((int)a[i] < (int)b[i]) {
			return true;
		}
		else if ((int)a[i] > (int)b[i]) {
			return false;
		}
		else {
			if (i + 1 == a.size() || i + 1 == b.size()) {
				return (a.size() <= b.size()) ? true : false;
			}
			else
				continue;
		}
	}
}

void mergeVect(vector<string> &wh, int bg, int en, int it) {
	it++;

	while (bg <= it - 1 && it <= en) {
		if (!(compareWords(wh[bg], wh[it]))) {
			wh.insert(wh.begin() + bg, wh[it]);
			wh.erase(wh.begin() + it + 1);
			it++;
		}
		bg++;
	}

	return;
}

void sortVect(vector<string> &wh, int bg, int en) {
	int it = (bg + en) / 2;

	if (en - bg > 1) {
		sortVect(wh, bg, it);
		sortVect(wh, it + 1, en);
	}
	else {
		if (!(compareWords(wh[bg], wh[en]))) {
			sw(wh[bg], wh[en]);
		}
		return;
	}

	mergeVect(wh, bg, en, it);

	return;
}

void out(vector<string> a) {
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";

	return;
}
