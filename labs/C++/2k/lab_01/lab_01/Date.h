#pragma once
#include "Time.h"

enum dayWeek { MONDAY = 1, TUESDAY, WEDNESDEY, THUSDAT, FRIDAY, SATURDAY, SUNDAY };

class Date {
public:
	Date() {};
	Date (int year, int month, int day, Time time) { // Конструктор
		if (DateIsCorrect(year, month, day) == 1) {
			this->year = year;
			this->month = month;
			this->day = day;
			this->time = time;
			this->WeekDay = FindWeekDay(year, month, day);
		}
		else
			throw ("Incorrect Date Format!");
	}
	int GetYear() {return this->year;}
	int GetMonth() {return this->month;}
	int GetDay() { return this->day;}
	Time GetTime() { return this->time;}
	Date operator+(Date toAdd);
	Date operator-(Date toMin);
	Date operator<(Date toCompare);
	Date operator>(Date toCompare);
	Date operator=(Date toCompare);
	string findDay() { return EnumToString(this->WeekDay); }
	dayWeek FindWeekDay(int year, int month, int day);
	bool DateIsCorrect(int y, int m, int d);
	string EnumToString(dayWeek d);
private:
	dayWeek WeekDay;
	int year;
	int month;
	int day;
	Time time;
};