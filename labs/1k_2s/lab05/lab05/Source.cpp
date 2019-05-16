#include <iostream>
#include <string>
#include "Graph.h"
#include <fstream>

using namespace std;

void CoutPath(List<List<int>> exp) {
	for (int i = 0; i < exp.GetSize(); i++) {
		List<int> tmp = exp[i];
		cout << i << " - ";
		for (int j = 0; j < tmp.GetSize(); j++) {
			cout << exp[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	setlocale(LC_ALL, "");
	Graph input;
	/*cin >> input;*/
	ifstream file("input.txt");
	file >> input;
	cout << input;
	input.TwoVerticesInOne(1, 6);
	cout << input;

	system("pause");
	return 0;
}