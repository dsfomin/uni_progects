#pragma once
#include "Time.h"

class Date {
public:
	Date() {};
	Date (int year, int month, int day, Time time) { // Конструктор
		this->year = year;
		this->month = month;
		this->day = day;
		this->time = time;
	}
	int GetYear() {return this->year;}
	int GetMonth() {return this->month;}
	int GetDay() { return this->day;}
	Time GetTime() { return this->time;}
	Date operator+(Date toAdd);
	Date operator-(Date toMin);
	Date findDay();
private:
	int year;
	int month;
	int day;
	Time time;
};