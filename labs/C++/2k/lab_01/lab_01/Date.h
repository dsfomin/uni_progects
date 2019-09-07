#pragma once
#include "Time.h"
#include <string>

using namespace std;

enum dayWeek { MONDAY = 1, TUESDAY, WEDNESDAY, THUSDAY, FRIDAY, SATURDAY, SUNDAY };

class Date {
public:
	Date() {};
	Date (int year, int month, int day, Time time = Time(0,0,0)) { // Конструктор
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
	bool operator<(Date toCompare);
	bool operator>(Date toCompare);
	bool operator==(Date toCompare);
	string enToString(dayWeek d);
	string findDay() { return string(enToString(WeekDay)); }
	dayWeek FindWeekDay(int year, int month, int day);
	bool DateIsCorrect(int y, int m, int d);
private:
	dayWeek WeekDay;
	int year;
	int month;
	int day;
	Time time;
};