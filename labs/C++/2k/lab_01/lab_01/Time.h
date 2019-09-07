#pragma once

class Time {
public:
	Time() {};
	Time (int h, int m, int s) {
		if (TimeIsCorrect(h, m, s) == 1) {
			this->hour = h;
			this->minute = m;
			this->second = s;
		}
		else
			throw ("Incorrect Time Format!");
	}
	int GetHour() { return this->hour; }
	int GetMinute() { return this->minute; }
	int GetSecond() { return this->second;}
	Time operator+(Time toAdd);
	Time operator-(Time toMin);
	Time operator<(Time toCompare);
	Time operator>(Time toCompare);
	Time operator==(Time toCompare); 
	bool TimeIsCorrect(int h, int m, int s);
private:
	int hour;
	int minute;
	int second;
};