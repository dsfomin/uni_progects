#include <iostream>
#include <sstream>
#include <string>
#include <exception>
#include <vector>
#include <iomanip>
#include "Date.h"
#include "Lists.h"
#include "Sorts.h"
#include "Time.h"

using namespace std;

ostream& operator<<(ostream & stream, Time time) {
	stream << setfill('0') << setw(2) << time.GetHour() << ":" << setw(2) << time.GetMinute() << ":" << setw(2) << time.GetSecond();
	return stream;
}
ostream& operator<<(ostream & stream, Date& date) {
	stream << setfill('0') << setw(2) << date.GetDay() << "." << setw(2) << date.GetMonth() << "." << setw(4) << date.GetYear() << " " << date.GetTime() << ", " << date.findDay();
	return stream;
}

int main() {
	try {

		// Variables

		Time time1(11, 50, 31);
		Time time2(12, 40, 50);
		Date date1(1999, 12, 31);
		Date date2(2012, 1, 31);
		Date date3(2008, 8, 28);
		//LinkedList<Date> lk_list;
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

		////Sorts

		////quickSort(listd, 0, listd.size() - 1);
		////mergeSort(listd, 0, listd.size() - 1);
		////insertionSort(listd, listd.size() - 1);

		//for (Date d : listd) {
		//	cout << d << endl;
		//}

	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
		system("pause>nul");
	}
	system("pause>nul");
	return 0;
}