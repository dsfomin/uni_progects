#include <iostream>
#include <string>
#include <exception>
#include <list>
#include <cassert>
#include "Date.h"
#include "Lists.h"
#include "Sorts.h"
#include "Time.h"
#include <sstream>

using namespace std;

ostream& operator<<(ostream & stream, Time & time) {
	if (time.GetHour() < 10) stream << "0" << time.GetHour();
	else stream << time.GetHour();
	stream << ":";
	if (time.GetMinute() < 10) stream << "0" << time.GetMinute();
	else stream << time.GetMinute();
	stream << ":";
	if (time.GetSecond() < 10) stream << "0" << time.GetSecond();
	else stream << time.GetSecond();

	return stream;
}

int main() {
	try {

		// Variables

		Time time1(11, 50, 31);
		Time time2(12, 40, 50);
		Date date1(2001, 12, 5, time1);
		/*Date date2(2002, 11, 3, time1);
		Date date3(2008, 8, 23, time1);*/
		//LinkedList<Date> lk_list;
		//MassList<Date> ms_list;
		//list<Date> list;

		// Initializations

		//list.push_back(date1);
		//list.push_back(date2);
		//list.push_back(date3);

		// Check of lists
		// Asserts

		Time time3 = time1 + time2;
		/*Date date4 = date1 + date2;*/

		cout << time1 << " + " << time2 << " = " << time3 << endl;
		cout << date1.findDay() << endl;


			
	}
	catch (exception& e) {
		cout << "Error: " << e.what() << endl;
		system("pause>nul");
	}
	system("pause>nul");
	return 0;
}