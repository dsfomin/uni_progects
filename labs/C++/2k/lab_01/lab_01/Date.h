#ifndef DATE_H
#define DATE_H

#pragma once
#include "Time.h"
#include <string>

using namespace std;

enum dayWeek { MONDAY = 1, TUESDAY, WEDNESDAY, THUSDAY, FRIDAY, SATURDAY, SUNDAY }; // Дни недели

// Класс Даты
class Date {
public:
	// Конструктор по умолчанию
	Date() {};

	// Конструктор
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

	// Получить год из даты
	int GetYear() {return this->year;}

	// Получить месяц из даты
	int GetMonth() {return this->month;}

	// Получить день из даты
	int GetDay() { return this->day;}

	// Получить время из даты
	Time GetTime() { return this->time;}

	// Оператор сложения двух дат
	Date operator+(Date toAdd);

	// Оператор вычитания двух дат
	Date operator-(Date toMin);

	// Оператор сравнения меньше для двух дат
	bool operator<(Date toCompare);

	// Оператор сравнения больше для двух дат
	bool operator>(Date toCompare);

	// Оператор сравнения тождества для двух дат
	bool operator==(Date toCompare);

	// День недели в строковом представлении
	string enToString(dayWeek d);

	// Найти день недели (str)
	string findDay() { return string(enToString(WeekDay)); }

	// Найти день недели (enum dayWeek)
	dayWeek FindWeekDay(int year, int month, int day);

	// Проверка на валидность даты
	bool DateIsCorrect(int y, int m, int d);

private:
	// День недели
	dayWeek WeekDay;

	// Год
	int year;

	// Месяц
	int month;

	// День
	int day;

	// Время
	Time time;
};

#endif // !