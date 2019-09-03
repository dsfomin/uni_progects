#include <iostream>
#include <fstream>

using namespace std;

struct Word {
	char word[256];
};

struct Text {
	Word w[256];
	int size = 0;
};

ostream& operator << (ostream& stream, Word& word) {
	for (int i = 0; i < size(word.word); i++) {
		cout << word.word[i];
	}

}

ostream& operator << (ostream& stream, Text& text) {
	for (int i = 0; i < text.size; i++) {
		cout << text.w[i] << ' ';
	}
}

bool ReadNext(fstream& file, Text& text) {
	char letter;
	bool is = false;
	while (file >> letter) {
		if (letter != ' ') {
			text.w->word[text.size] += letter;
			is = true;
		}
	}
	if (is) {
		return 1;
	}
	return 0;
}

int main() {
	setlocale(0, "rus");
	fstream file("input.txt");

	Text txt;

	if (file) {
		while (ReadNext(file, txt)) {
		}
	}

	сout << "0) Начальный текст: " << txt << endl;
 	cout << "1) Количество слов: " << txt.size << endl;
	Text SortedByNy = SortN(txt);
	cout << "2) Частота " << SortedByNy << endl;
	Text SortedByABC = SortABC(txt);
	cout << "" << SortedByABC << endl;

	file.close();
	system("pause>nul");
	return 0;
}