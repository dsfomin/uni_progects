#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

int main() {
	vector<char> elements;
	vector<map<char, char>> sorted_elements;
	fstream file("1.txt");
	char element;
	if (file) {
		while (file >> element) {
			elements.push_back(element);
		}
	}

	for (int i = 0; i < elements.size(); i++) {
		if (elements[i] == elements[i++]) {
			sorted_elements.
		}
	}

	file.close();
	return 0;
	system("pause>nul");
}