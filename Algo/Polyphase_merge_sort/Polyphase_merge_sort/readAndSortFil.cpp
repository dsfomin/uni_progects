#include <iostream>
#include <fstream>
#include <vector>
#include <string>

#include "readAndSortFil.h"
#include "readAndSortVec.h"

void outF(vector<string> &a, fstream &b) {
	for (unsigned int i = 0; i < a.size(); i++)
		b << a[i] << " ";
	return;
}

void mergeFileAndVec(vector<string> &wh, fstream &in, fstream &out) {
	string temp;
	in >> temp;
	if (in.good()) {
		for (unsigned int i = 0; i < wh.size(); i++) {
			while (!in.eof() && !compareWords(wh[i], temp)) {
				out << temp << " ";
				in >> temp;
			}
			out << wh[i] << " ";
		}

		while (!in.eof()) {
			out << temp << " ";
			in >> temp;
		}
		return;
	}
	else {
		while (!in.eof()) {
			out << temp << " ";
			in >> temp;
		}
		return;
	}

}

void mergeFiles(fstream &in1, fstream &in2, fstream &out) {
	string temp1;
	string temp2;
	in1 >> temp1;
	in2 >> temp2;
	if (in1.good() && in2.good()) {
		while (!in1.eof() && !in2.eof()) {
			if (compareWords(temp1, temp2)) {
				out << temp1 << " ";
				in1 >> temp1;
			}
			else {
				out << temp2 << " ";
				in2 >> temp2;
			}
		}

		while (!in1.eof()) {
			out << temp1 << " ";
			in1 >> temp1;
		}
		while (!in2.eof()) {
			out << temp2 << " ";
			in2 >> temp2;
		}
	}
	else {
		cout << "Something wrong with the files" << endl;
		return;
	}

}

void tempFilesOp(vector<string> &work, int &counter) {

	switch (counter) {
	case 0: {
		fstream t1;
		t1.open("temp1.txt", ios::out);
		outF(work, t1);
		t1.close();
		counter++;
		break;

	}
	case 1: {
		fstream t1;
		fstream t2;
		t1.open("temp1.txt", ios::in);
		t2.open("temp2.txt", ios::out);
		mergeFileAndVec(work, t1, t2);
		counter++;
		t1.close();
		break;
	}
	case 2: {
		fstream t1;
		fstream t2;
		t1.open("temp1.txt", ios::out);
		t2.open("temp2.txt", ios::in);

		mergeFileAndVec(work, t2, t1);
		counter = 1;

		t1.close();
		t2.close();
		break;
	}

	}
}

void rewriteToOut(int c) {
	fstream out;
	fstream in;
	out.open("out.txt", ios::out);
	switch (c) {
	case 1: {
		in.open("temp1.txt", ios::in);
		break;
	}
	case 2: {
		in.open("temp2.txt", ios::in);
		break;
	}

	}
	string temp;
	while (!in.eof()) {
		in >> temp;
		out << temp << " ";
	}
	return;
}
