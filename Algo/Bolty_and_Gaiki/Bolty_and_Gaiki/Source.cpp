#include <iostream>
#include <algorithm>
#include <ctime>
#include <chrono>

using namespace std;
using namespace chrono;


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void CoutArray(int64_t* m, int64_t n) {
	for (int i = 0; i < n; i++) {
		cout << m[i] << " ";
	}
}

void GenerateArrayFrom1toN(int64_t* mas, int64_t N) {
	for (int i = 0; i < N; i++) {
		mas[i] = i;
	}
}

void ShuffleValuesOfArray(int64_t* mas, int64_t N) {
	for (int i = 0; i < N; ++i) {

		swap(mas[i], mas[std::rand() % N]);
	}
}

int partition(int64_t* arr, int64_t low, int64_t high, int pivot)
{
	int i = low;
	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot) {
			swap(arr[i], arr[j]);
			i++;
		}
		else if (arr[j] == pivot) {
			swap(arr[j], arr[high]);
			j--;
		}
	}
	swap(arr[i], arr[high]);

	return i;
}

void SortNutsAndBolts(int64_t* nuts, int64_t* bolts, int low, int64_t high) {
	if (low < high)
	{
		// Choose last character of bolts array for nuts partition. 
		int pivot = partition(nuts, low, high, bolts[high]);

		// Now using the partition of nuts choose that for bolts 
		// partition. 
		partition(bolts, low, high, nuts[pivot]);

		SortNutsAndBolts(nuts, bolts, low, pivot - 1);
		SortNutsAndBolts(nuts, bolts, pivot + 1, high);
	}
}

int main() {
	// n bolt and gaiki

	setlocale(0, "rus");

	srand(time(0));

	int64_t N;
	cout << "Введите количество пар гаек и болтов" << endl;
	cin >> N;

	int64_t *gaiki = new int64_t[N];
	int64_t *bolty = new int64_t[N];

	GenerateArrayFrom1toN(gaiki, N);

	//cout << "Gaiki: " << endl;
	//CoutArray(gaiki, N);
	//cout << endl;

	GenerateArrayFrom1toN(bolty, N);

	/*cout << "Bolty: " << endl;
	CoutArray(bolty, N);
	cout << endl;*/

	ShuffleValuesOfArray(gaiki, N);
	//random_shuffle(gaiki, gaiki + N);

	/*cout << "Gaiki: " << endl;
	CoutArray(gaiki, N);
	cout << endl;*/

	ShuffleValuesOfArray(bolty, N);
	//random_shuffle(bolty, bolty + N);

	/*cout << "Bolty: " << endl;
	CoutArray(bolty, N);
	cout << endl;*/

	clock_t start = clock();

	SortNutsAndBolts(bolty, gaiki, 0, N - 1);

	clock_t end = clock();

	cout << "Taktov1: " << (end - start) << endl;

	system("pause>nul");
	return 0;
}