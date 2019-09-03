#pragma once


class Time {
public:
	Time() {};
	Time (int h, int m, int s) {
		this->hour = h;
		this->minute = m;
		this->second = second;
	}
	int GetHour() { return this->hour; }
	int GetMinute() { return this->minute; }
	int GetSecond() { return this->second;}
	Time operator+(Time toAdd);
	Time operator-(Time toMin);
private:
	int hour;
	int minute;
	int second;
};