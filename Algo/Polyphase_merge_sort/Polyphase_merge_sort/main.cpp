#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "userInteraction.h"
#include "readAndSortVec.h"
#include "readAndSortFil.h"

void readFile(long ramSize) {

	fstream input;
	//if (input.open ("input.txt");
	vector <string> work;
	string work_t;
	long currentSize = 0;

	int counter = 0;

	double progress = 0;

	while (input >> work_t) {
		cout << progress++ << '\r';//" characters have been read"<<'\r';

		if (check(ramSize, currentSize, work_t)) {
			work.push_back(work_t);
			currentSize += work_t.size();
		}
		else {
			sortVect(work, 0, work.size());

			tempFilesOp(work, counter);

			work.clear();
			work.push_back(work_t);
			currentSize = work_t.size();
		}
	}

	sortVect(work, 0, work.size());
	tempFilesOp(work, counter);

	rewriteToOut(counter);

	return;
}

int main()
{
	info();
	long ramSize = ramMem();
	readFile(ramSize);

	return 0;
}
