#pragma once
#include "Date.h"

bool is_leap(int year)
{
	if (year % 4)
		return false;
	else if (year % 100)
		return true;
	return !(year % 400);
}

int countOfDaysInMonth(int y, int m) {
	if (m == 1 || m == 3 || m == 5 || m == 12 || m == 10 || m == 8 || m == 7) return 31;
	else if (m == 4 || m == 6 || m == 9 || m == 11) return 30;
	else if (m == 2) return is_leap(y) ? 29 : 28;
	return -1;
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
	int ty, tm, td;
	Time t;
	tm = this->GetMonth() + toAdd.GetMonth();
	td = this->GetDay() + toAdd.GetDay();
	ty = this->GetYear() + toAdd.GetYear();
	if (tm > 12) {
		tm %= 12;
		ty++;
	}
	while (countOfDaysInMonth(ty, tm) < td) {
		td -= countOfDaysInMonth(ty, tm);
		tm++;
	}
	if (tm > 12) {
		tm %= 12;
		ty++;
	}

	/*if (this->GetTime() == Time( 0, 0, 0 ) && toAdd.GetTime() == Time( 0, 0, 0 )) t = Time(0,0,0);
	else {
		if (this->GetTime.GetDay() + toAdd.GetTime.GetDay() < 60 && this->GetTime.GetMonth() + toAdd.GetTime.GetMonth() < 60) return;
	}*/
	return Date(ty, tm, td);
}

Date Date::operator-(Date toMin) {
	return Date();
}

bool Date::operator<(Date toCompare)
{
	if (this->GetYear() != toCompare.GetYear())
		return this->GetYear() < toCompare.GetYear();
	else if (this->GetMonth() != toCompare.GetMonth())
		return this->GetMonth() < toCompare.GetMonth();
	else
		return this->GetDay() < toCompare.GetDay();
}

bool Date::operator>(Date toCompare) {
	if (this->GetYear() != toCompare.GetYear())
		return this->GetYear() > toCompare.GetYear();
	else if (this->GetMonth() != toCompare.GetMonth())
		return this->GetMonth() > toCompare.GetMonth();
	/*else if (this->GetTime() != this->GetTime())
		return (this->GetTime() > toCompare.GetTime());*/
	return this->GetDay() > toCompare.GetDay();
}

bool Date::operator==(Date toCompare)
{
	return ((this->GetDay() == toCompare.GetDay()) && (this->GetMonth() == toCompare.GetMonth()) && (this->GetMonth() == toCompare.GetMonth()));
}

string Date::enToString(dayWeek d)
{
	switch (d) {
	case MONDAY:
		return string("MONDAY");
	case TUESDAY:
		return string("TUESDAY");
	case WEDNESDAY:
		return string("WEDNESDAY");
	case THUSDAY:
		return string("THUSDAY");
	case FRIDAY:
		return string("FRIDAY");
	case SATURDAY:
		return string("SATURDAY");
	case SUNDAY:
		return string("SUNDAY");
	default:
		return string("UNKNOWN");
	}return string();
}

bool Date::DateIsCorrect(int y, int m, int d)
{
	if (d < 0 || m < 0 || m > 12) return false;
	if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12) && d > 31) return false;
	if ((m == 4 || m == 6 || m == 11 || m == 9) && d > 30) return false;
	if (m == 2 && is_leap(y) && d > 29) return false;
	else if (m == 2 && d > 28) return false;

	return true;
}


