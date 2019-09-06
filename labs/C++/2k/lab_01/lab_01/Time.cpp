#include "Time.h"
#include <sstream>

using namespace std;

Time Time::operator+(Time toAdd) {
	int th, tm, ts;

	ts = toAdd.second + this->GetSecond();
	tm = toAdd.minute + this->GetMinute();
	th = toAdd.hour + this->GetHour();

	if (ts > 59) { tm++; ts %= 60; }
	if (tm > 59) { th++; tm %= 60; }
	if (th > 23) { th %= 24; }

	return Time(th, tm, ts);
}

Time Time::operator-(Time toMin) {
	Time res;


	return Time();
}

Time Time::operator<(Time toCompare)
{

	return Time();
}

Time Time::operator>(Time toCompare)
{
	return Time();
}

Time Time::operator=(Time toCompare)
{
	return Time();
}

bool Time::TimeIsCorrect(int h, int m, int s)
{
	if (h < 0 || h > 23) return false;
	if (m < 0 || m > 59) return false;
	if (s < 0 || s > 59) return false;

	return true;
}

