#include <iostream>
#include <string>
#include <map>
#include <set>
#include <sstream>
#include <stdlib.h>
#include <iomanip>

using namespace std;

string TakePart(string& str) {
	string res;
	int i = 0;

	if (str[i] == 32) {
		while (str[i] == 32) {
			str.erase(0, 1);
		}
	}
	if (str[i] >= 33 && str[i] <= 126) {
		while (str[i] >= 33 && str[i] <= 126)  {
			res += str[i];
			str.erase(0, 1);
		}
	}
	return res;
}

int TakePart_int(string& str) {

	string part;
	int res, i = 0;

	if (str[i] == '-' && (str[i + 1] >= 48 && str[i + 1] <= 57)) {
		part += str[i];
		str.erase(i, 1);
		while (str[i] >= 48 && str[i] <= 57) {
			part += str[i];
			str.erase(i, 1);
		}
		if (str[i] == '-')
			str.erase(i, 1);

		res = atoi(part.c_str());

		return res;
	}

	while (str[i] >= 48 && str[i] <= 57) {
		part += str[i];
		str.erase(i, 1);
	}

	if (str[i] == '-')
		str.erase(i, 1);

	res = atoi(part.c_str());

	return res;
}

bool CheckFormatDate(string& date) {
	string str = date;
	string str1 = date;

	bool correct = true;

	if (str1[0] == '-') {
		str1.erase(0, 1);
	}
	while (str1[0] >= 48 && str1[0] <= 57) {
		str1.erase(0, 1);
	}

	if (str1[0] == '-' && str1[1] == '-')
	{
		str1.erase(0, 2);
	}
	else if (str1[0] == '-')
		str1.erase(0, 1);
	else
		correct = false;

	while (str1[0] >= 48 && str1[0] <= 57) {
		str1.erase(0, 1);
	}

	if (str1[0] == '-' && str1[1] == '-')
	{
		str1.erase(0, 2);
	}
	else if (str1[0] == '-')
		str1.erase(0, 1);
	else
		correct = false;

	while (str1[0] >= 48 && str1[0] <= 57) {
		str1.erase(0, 1);
	}

	if (!str1.empty())
		correct = false;

	for (size_t i = 0; i < str.size(); i++) {
		if (!(str[str.size() - 1] >= 48 && str[str.size() - 1] <= 57)) {
			cout << "Wrong date format: " << date << endl;
				system("pause");
				return 0;
		}
		if (str[0] == '-' && str[1] == '-') {
			cout << "Wrong date format: " << date << endl;
			system("pause");
			return 0;
		}
		if (str[i] == '-' && str[i + 1] == '-' && str[i + 2] == '-') {
			cout << "Wrong date format: " << date << endl;
			system("pause");
			return 0;
		}
		if (!((str[i] >= 48 && str[i] <= 57) || str[i] == '-')) {
			cout << "Wrong date format: " << date << endl;
			system("pause");
			return 0;
		}
		if (!correct) {
			cout << "Wrong date format: " << date << endl;
			system("pause");
			return 0;
		}
	}
	return 1;
}

bool CheckValidDate(string& date) {
	string str = date, year, month, day;

	if (str[0] == '-') {
		year += str[0];
		str.erase(0, 1);
	}
	while (str[0] >= 48 && str[0] <= 57) {
		year += str[0];
		str.erase(0, 1);
	}

	if (str[0] == '-' && str[1] == '-')
	{
		month += str[0];
		str.erase(0, 2);
	}
	else if (str[0] == '-')
		str.erase(0, 1);

	while (str[0] >= 48 && str[0] <= 57) {
		month += str[0];
		str.erase(0, 1);
	}

	if (str[0] == '-' && str[1] == '-')
	{
		day += str[0];
		str.erase(0, 2);
	}
	else if (str[0] == '-')
		str.erase(0, 1);

	while (str[0] >= 48 && str[0] <= 57) {
		day += str[0];
		str.erase(0, 1);
	}

	int y = atoi(year.c_str());
	int m = atoi(month.c_str());
	int d = atoi(day.c_str());

	if (m < 1 || m > 12) {
		cout << "Month value is invalid: " << m << endl;
		system("pause");
		return 0;
	}
	else if (d < 1 || d > 31) {
		cout << "Day value is invalid: " << d << endl;
		system("pause");
		return 0;
	}
	return 1;
}

class Date {
public:
	Date(string date) {
		year = TakePart_int(date);
		month = TakePart_int(date);
		day = TakePart_int(date);
	}
	int GetYear() const {
		return year;
	}
	int GetMonth() const {
		return month;
	}
	int GetDay() const {
		return day;
	}
private:
	int year = 1;
	int month = 1;
	int day = 1;
};

bool operator<(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear())
		if (lhs.GetMonth() == rhs.GetMonth())
			return lhs.GetDay() < rhs.GetDay();
		else
			return lhs.GetMonth() < rhs.GetMonth();
	else
		return lhs.GetYear() < rhs.GetYear();

}

bool operator==(const Date& lhs, const Date& rhs) {
	if (lhs.GetYear() == rhs.GetYear() &&
		lhs.GetMonth() == rhs.GetMonth() &&
		lhs.GetDay() == rhs.GetDay())
		return 1;
	return 0;
}

ostream& operator<<(ostream& stream, const Date& date) {
	stream << setw(4) << setfill('0') << date.GetYear() << '-'
		<< setw(2) << setfill('0') << date.GetMonth() << '-'
		<< setw(2) << setfill('0') << date.GetDay();
	return stream;
}

class Database {
public:
	void AddEvent(const Date& date, const string& event) {
		dates[date].insert(event);
	}
	bool DeleteEvent(const Date& date, const string& event) {
		if (dates[date].count(event) > 0) {
			dates[date].erase(event);
			return 1;
		}
		else
			return 0;
	}
	int  DeleteDate(const Date& date) {
		int n = dates[date].size();

		dates.erase(date);

		return n;
	}
	void Find(const Date& date) const {
		for (const auto item : dates) {
			if (item.first == date) {
				for (auto m : item.second) {
					cout << m << endl;
				}
			}
		}
	}
	void Print() const {
		for (const auto item : dates) {
			for (auto m : item.second) {
				cout << item.first << " " << m << endl;
			}
		}
	}
private:
	int date;
	map<Date, set<string>> dates;
};

int main() {
	Database db;

	string command, operation, date, event;
	while (getline(cin, command)) {
		if (command.empty())
			continue;
		string operation = TakePart(command);
		if (operation != "Add" &&
			operation != "Del" &&
			operation != "Find" &&
			operation != "Print") {
			cout << "Unknown command: " << operation << endl;
			system("pause");
			return 0;
		}
		string date = TakePart(command);
		if (!date.empty()) {
			if (!CheckFormatDate(date)) {
				system("pause");
				return 0;
			}
			if (!CheckValidDate(date)) {
				system("pause");
				return 0;
			}
		}
		string event = TakePart(command);
		if (operation == "Add") {
			if (date.empty()) {
				cout << "Wrong date format: " << date << endl;
				system("pause");
				return 0;
			}
			Date date1(date);
			db.AddEvent(date1, event);
		}
		else if (operation == "Del") {
			Date date2(date);
			if (event.empty()) {
				cout << "Deleted " << db.DeleteDate(date2) << " events" << endl;
			}
			else if (!event.empty()) {
				if (db.DeleteEvent(date2, event)) {
					cout << "Deleted successfully" << endl;
				}
				else
					cout << "Event not found" << endl;
			}
		}
		else if (operation == "Find") {
			Date date3(date);
			db.Find(date3);
		}
		else if (operation == "Print") {
			db.Print();
		}
	}

	system("pause");
	return 0;
}