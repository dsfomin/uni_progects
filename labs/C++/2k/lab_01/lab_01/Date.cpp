
#include <string>
#include "Date.h"


bool is_leap(int year)
{
	if (year % 4)
		return false;
	else if (year % 100)
		return true;
	return !(year % 400);
}

dayWeek Date::FindWeekDay(int year, int month, int day) {
	int a = (14 - month) / 12;
	int y = year - a;
	int m = month + 12 * a - 2;
	int res = (7000 + (day + y + y / 4 - y / 100 + y / 400 + (31 * m) / 12)) % 7;
	switch (res) {
	case 0:
		return dayWeek(7);
	case 1:
		return dayWeek(1);
	case 2:
		return dayWeek(2);
	case 3:
		return dayWeek(3);
	case 4:
		return dayWeek(4);
	case 5:
		return dayWeek(5);
	case 6:
		return dayWeek(6);
	default:
		break;
	}
}

Date Date::operator+(Date toAdd) {
	return Date();
}

Date Date::operator-(Date toMin) {
	return Date();
}

Date Date::operator<(Date toCompare)
{
	return Date();
}

Date Date::operator>(Date toCompare)
{
	return Date();
}

Date Date::operator=(Date toCompare)
{
	return Date();
}

bool Date::DateIsCorrect(int y, int m, int d)
{
	if (d < 0 || m < 0 || m > 12) return false;
	if (m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12 && d > 31) return false;
	if (m == 4 || m == 6 || m == 11 || m == 9 && d > 30) return false;
	if (m == 2 && is_leap(y) && d > 29) return false;
	else if (m == 2 && d > 28) return false;

	return true;
}

string Date::EnumToString(dayWeek d)
{


	return string();
}


