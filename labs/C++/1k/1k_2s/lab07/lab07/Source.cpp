#include "LibOfSorts.h"
#include "Graph.h"
#include "List.h"
#include <fstream>

using namespace std;

ostream& operator<<(ostream& stream, List<int> l) {
	for (int i = 0; i < l.GetSize(); i++) {
		stream << l[i] << " ";
	}
	return stream;
}

int main()
{
	setlocale(LC_ALL, "");
	Graph input;
	ifstream file("input.txt");

	List<int> res1;
	file >> input;

	cout << "������� �������� ����� �������������� �� �-���� ����� ����� (InsertionSort): " << endl << "1) ";
	res1 = insertionSort(input);
	cout << res1 << endl;

	cout << "������� �������� ����� �������������� �� ������ ���� ����� ����� (BubbleSort):" << endl << "2) ";
	res1 = bubbleSort(input);
	cout << res1 << endl;

	cout << "����� �������� ����� �������������� �� ����� (QuickSort): " << endl << "4)" << endl;
	quickSort(input.graph, 0, input.graph.GetSize() - 1);
	cout << input;
	system("pause");
	return 0;
}