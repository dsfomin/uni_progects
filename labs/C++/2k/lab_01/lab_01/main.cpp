#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <vector>
#include <iomanip>
#include "Time.h"
#include "Date.h"
#include "Sorts.h"
#include "Lists.h"
#include "MassList.h"

using namespace std;

ostream& operator<<(ostream & stream, Time time) {
	stream << setfill('0') << setw(2) << time.GetHour() << ":" << setw(2) << time.GetMinute() << ":" << setw(2) << time.GetSecond();
	return stream;
}
ostream& operator<<(ostream & stream, Date& date) {
	stream << setfill('0') << setw(2) << date.GetDay() << "." << setw(2) << date.GetMonth() << "." << setw(4) << date.GetYear() << " " << date.GetTime() << ", " << date.findDay();
	return stream;
}

void insertionSort(LinkedList<Date> l, int n)
{
	int i, j;
	Date key;
	for (i = 1; i < n; i++)
	{
		key = l[i];
		j = i - 1;


		while (j >= 0 && l[j] > key)
		{
			l.removeAt(j + 1);
			l.insert(l[j], j + 1);
			j = j - 1;
		}
		l.removeAt(j + 1);
		l.insert(key, j + 1);
	}
}


int main() {
	try {

		// Variables

		Time time1(11, 50, 31);
		Time time2(12, 40, 50);
		Date date1(1999, 12, 31);
		Date date2(2012, 1, 31);
		Date date3(2008, 8, 28);
		LinkedList<Date> lk_list;

		//MassList<Date> ms_list;

		vector<Date> listd;

		Time time3 = time1 + time2;
		Date date4 = date1 + date2;

		cout << date1 << endl;
		cout << time1 << " + " << time2 << " = " << time3 << endl;
		cout << date1 << " + " << date2 << " = " << date4 << endl;
		cout << date4.findDay() << endl;

		listd.push_back(date1);
		listd.push_back(date2);
		listd.push_back(date3);
		listd.push_back(date4);

		for (Date d : listd) {
			cout << d << endl;
		}

		cout << endl;
		
		lk_list.push_back(date1);
		lk_list.push_back(date2);
		lk_list.push_back(date3);
		lk_list.push_back(date4);
		lk_list.pop_back();
		

		for (int i = 0; i < lk_list.GetSize(); i++) {
			cout << lk_list[i] << endl;
		}

		cout << endl;

		//Sorts

		/*quickSort(listd, 0, listd.size() - 1);
		mergeSort(listd, 0, listd.size() - 1);*/
		insertionSort(listd, listd.size() - 1);

		for (Date d : listd) {
			cout << d << endl;
		}

		cout << endl;

		insertionSort(lk_list, lk_list.GetSize());

		for (int i = 0; i < lk_list.GetSize(); i++) {
			cout << lk_list[i] << endl;
		}

	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
		system("pause>nul");
	}
	system("pause>nul");
	return 0;
}