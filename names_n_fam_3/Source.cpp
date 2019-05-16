#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

string FindNameByYear(const map<int, string>& names, int year) {
	string name;

	for (const auto& item : names) {
		if (item.first <= year) {
			name = item.second;
		}
		else {
			break;
		}
	}

	return name;
}

string FindVectorNamesByYear(const map<int, string>& names, int year) {
	vector<string> v_names;
	string name;

	for (const auto& item : names) {
		if (item.first <= year) {
			v_names.push_back(item.second);
		}
		else
			break;
	}

	if (v_names.size() > 0) {

		v_names.erase(unique(v_names.begin(), v_names.end()), v_names.end());

		if (v_names.size() == 1)
			name += v_names[0];
		else {
			name += v_names.back();
			name += " (";

			for (int i = (v_names.size() - 2); i >= 0; i--) {
				name += v_names[i];
				name += ", ";
			}

			if (name.size() > 0) {
				name.erase(name.end() - 1);
				name.erase(name.end() - 1);
				name += ")";
			}
		}
	}
	return name;
}


class Person {
public:
	Person() {}
	Person(const string& first_name, const string& last_name, int birth_year) {
		birthyear = birth_year;
		first_names[birth_year] = first_name;
		last_names[birth_year] = last_name;
	}
	~Person() {
		cout << "End/n";
	}
	void ChangeFirstName(int year, const string& first_name) {
		if (year >= birthyear)
			first_names[year] = first_name;
	}
	void ChangeLastName(int year, const string& last_name) {
		if (year >= birthyear)
			last_names[year] = last_name;
	}
	string GetFullName(int year) const {
		if (year >= birthyear) {
			const string first_name = FindNameByYear(first_names, year);
			const string last_name = FindNameByYear(last_names, year);

			if (first_name.empty() && last_name.empty()) {
				return "Incognito";
			}
			else if (first_name.empty()) {
				return last_name + " with unknown first name";
			}
			else if (last_name.empty()) {
				return first_name + " with unknown last name";
			}
			else {
				return first_name + " " + last_name;
			}
		}
		else
			return "No person";
	}
	string GetFullNameWithHistory(int year) const {
		if (year >= birthyear) {
			string first_name = FindVectorNamesByYear(first_names, year);
			string last_name = FindVectorNamesByYear(last_names, year);

			if (first_name.empty() && last_name.empty()) {
				return "Incognito";
			}
			else if (first_name.empty()) {
				return last_name + " with unknown first name";
			}
			else if (last_name.empty()) {
				return first_name + " with unknown last name";
			}
			else {
				return first_name + " " + last_name;
			}
		}
		else
			return "No person";
	}
private:
	map<int, string> first_names;
	map<int, string> last_names;
	int birthyear;
};

int main() {
	Person person("Polina", "Sergeeva", 1960);
	for (int year : {1959, 1960}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	person.ChangeFirstName(1965, "Appolinaria");
	person.ChangeLastName(1967, "Ivanova");
	for (int year : {1965, 1967}) {
		cout << person.GetFullNameWithHistory(year) << endl;
	}

	system("pause");
	return 0;
}
