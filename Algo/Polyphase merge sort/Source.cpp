#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <memory>

using namespace std;

fstream file_A("A.txt", ios::out | ios::in);
fstream file_B("B.txt", ios::out | ios::in);
fstream file_C("C.txt", ios::out | ios::in);
fstream file_D("D.txt", ios::out | ios::in);

void insertionSort(vector<int> arr, int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

void CreateRuns(int& S) {
	vector<int> mas;
	string file;
	cout << "¬ведите файл который надо отсортировать: " << endl;
	cin >> file;
	fstream Input(file, ios::out | ios::in);
	fstream CurrentFile("A.txt", ios::out | ios::in | ios::app);
	if (Input.is_open()) {
		int n = 0;
		while (Input >> n) {
			if (mas.size() != S) {
				mas.push_back(n);
			}
			else {
				insertionSort(mas, mas.size());
				if (CurrentFile.is_open()) {
					for (int i : mas) {
						CurrentFile << i << " ";
					}
				}
				mas.clear();
				if (addressof(CurrentFile) == addressof(file_A)) {
					CurrentFile.close();
					CurrentFile.open("B.txt", ios::out | ios::in | ios::app);
				}
				else {
					CurrentFile.close();
					CurrentFile.open("A.txt", ios::out | ios::in | ios::app);
				}
			}

		}
	}
}

void PolyPhaseMerge(int& S) {

}

int main() {
	fstream Input("input.txt", ios::out | ios::in);
	fstream CurrentFile;

	int S = 0; // размер создаваемых отрезков
	cout << "¬ведите допустимый размер выдел€емой пам€ти" << endl;
	cin >> S;


	CreateRuns(S);
	PolyPhaseMerge(S);


	system("pause>nul");
	return 0;
}