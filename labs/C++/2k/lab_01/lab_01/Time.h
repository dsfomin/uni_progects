#ifndef TIME_H
#define TIME_H

#pragma once

// Класс времени
class Time {
public:
	// Конструктор по умолчанию
	Time() {};

	// Конструктор
	Time (int h, int m, int s) {
		if (TimeIsCorrect(h, m, s) == 1) {
			this->hour = h;
			this->minute = m;
			this->second = s;
		}
		else
			throw ("Incorrect Time Format!");
	}

	// Получить час
	int GetHour() { return this->hour; }

	// Получить минуту
	int GetMinute() { return this->minute; }

	// Получить секунду
	int GetSecond() { return this->second;}

	// Оператор сложения двух времен
	Time operator+(Time toAdd);

	// Оператор вычитания двух времен
	Time operator-(Time toMin);

	// Оператор сравнения меньше двух времен
	Time operator<(Time toCompare);

	// Оператор сравнения больше двух времен
	Time operator>(Time toCompare);

	// Оператор сравнения тождества двух времен
	Time operator==(Time toCompare); 

	// Проверка на валидность времени
	bool TimeIsCorrect(int h, int m, int s);
private:
	// Час
	int hour;

	// Минута
	int minute;

	// Секунда
	int second;
};

#endif