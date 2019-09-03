#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>

using namespace std;

const char* PATH = "users.dat";
const char* CPATH = "counter.dat";

struct User {               //Инфа по человеку
	char login[64] = "";
	char pass[64] = "";
	char diagnos[128] = "";
	int permission = 0;
	int id = 0;
};

bool Check(const vector<User>& users, char login[64], char password[64])
{
	for (auto item : users)
		if (strcmp(item.login, login) == 0 && strcmp(item.pass, password) == 0)
			return true;
	return false;
}

int Permission(const vector<User>& users, char login[64]) {
	for (auto item : users)
		if (strcmp(item.login, login) == 0)
			return item.permission;
}

int CheckID(fstream& file) {
	file.open(CPATH);

	int ch = 0;

	if (file) {
		file >> ch;
		ch++;
	}

	file.close();

	file.open(CPATH);

	if (file)
		file << ch;

	file.close();
	return ch;
}

void writeAllUsers(vector<User>& vUser)
{
	ofstream fout(PATH, ofstream::binary);
	for (int i = 0; i < vUser.size(); i++)
	{
		fout.write((char*)&vUser.at(i), sizeof(User));
	}
	fout.close();
}

void readAllUsers(vector<User>& vUser)
{
	User user;
	ifstream fin(PATH);
	while (fin.read((char*)&user, sizeof(User)))
		if (user.id != 0)
			vUser.push_back(user);
	fin.close();
}

ostream& operator<<(ostream& stream, vector<User>& users) {
	for (const User item : users) {
		stream << item.login << " "
			<< item.pass << " "
			<< item.diagnos << " "
			<< item.permission << " "
			<< item.id << endl;
	}
	return stream;
}

void AddPatient(vector<User>& users, char *login, char *password) {
	User user;
	fstream counter;

	strcpy_s(user.login, login);
	strcpy_s(user.pass, password);

	user.id = CheckID(counter);
	user.permission = 1;
	users.push_back(user);

	cout << "Добавлен новый пациент!" << endl;
}

void AllPatients(vector<User>& users) {
	for (const User item : users)
		if (item.permission == 1)
			cout << "Login: " << item.login << " ID: " << item.id << endl;
}

void DelPatient(vector<User>& users, char *login) {
	int i = 0;
	bool valid = false;
	for (const User item : users) {
		if (strcmp(item.login, login) == 0) {
			users.erase(users.begin() + i);
			valid = true;
			cout << "Пациент " << item.login << " успешно удален" << endl;
		}
		i++;
	}
	if (valid == false)
		cout << "Пациента с таким логином нет!" << endl;
}

void SetDiagnos(vector<User>& users, char *login, char *diagnos) {
	bool valid = false;
	char extra[64];
	int i = 0, n;
	for (User item : users) {
		if (strcmp(item.login, login) == 0) {
			n = i;
			strcpy_s(extra, diagnos);
			valid = true;
			cout << "Диагноз успешно определен" << endl;
		}
		i++;
	}
	
	while (isspace(extra[0])) {
		memmove(&extra[0], &extra[1], strlen(extra));
	}

	strcpy_s(users[n].diagnos, extra);
	if (valid == false)
		cout << "Пациента с таким логином нет!" << endl;
}

void Find(vector<User>& users, char *login) {
	bool valid = false;
	for (const User item : users) {
		if (strcmp(item.login, login) == 0) {
			valid = true;
			cout << "Login: " << item.login << " ID: " << item.id << endl;
		}
	}
	if (valid == false)
		cout << "Пациента с таким логином нет!" << endl;
}

void CheckDiagnos(const vector<User>& users, char *login) {
	bool valid = false;
	for (const User item : users) {
		if (strcmp(item.login, login) == 0) {
			valid = true;
			if (strcmp(item.diagnos, "") != 0) {
				cout << item.diagnos << endl;
			}
			else {
				cout << "Диагноза еще нет!" << endl;
			}
		}
	}
	if (valid == false)
		cout << "Пациента с таким логином нет!" << endl;
}

int main() {
	setlocale(0, "rus");
	bool hello;
	char login[64], password[64], diagnos[64];
	/*User *users = new User;*/
	vector<User> users;
	int zero = 0;

	fstream counter(CPATH);

	if (counter.is_open()) {
		if (counter.good()) {
			counter.seekg(0, ios::end);
			if (counter.tellg() == 0) {
				counter << zero;
			}
		}
		else {
			cout << "File counter isn't good!" << endl;
		}
	}
	else {
		cout << "File counter isn't opened!" << endl;
	}

	counter.close();

	readAllUsers(users);

	cout << "ЗДРАСТВУЙТЕ!\nРЕГЕСТРАЦИЯ (0) ИЛИ ВХОД (1)" << endl;
	cin >> hello;

	if (hello == 0) {
		User user;
		cout << "__РЕГЕСТРАЦИЯ__" << endl;
		cout << "Введите логин, пароль" << endl;
		cin >> user.login >> user.pass;
		cout << "Кто вы? Врач (0), Пациент (1) или Гость (2)?" << endl;
		cin >> user.permission;

		user.id = CheckID(counter); // Начинается с 1

		users.push_back(user);

		hello = 1;
	}
	if (hello == 1) {

		cout << "__ВХОД__" << endl;
		cout << "Для выхода и сохранения нажмите в любой момент - q!" << endl;
		cout << users;

		while (true) {
			cout << "Введите логин и пароль" << endl;
			cin >> login;

			if (strcmp(login, "q!") == 0) {
				writeAllUsers(users);
				system("pause");
				return 0;
			}

			cin >> password;

			if (Check(users, login, password)) {
				int cur_permission = Permission(users, login);
				if (cur_permission == 0) {
					string operation;
					cout << "Вы __ВРАЧ__\nДоступные команды:\n1) ADD_PATIENT (LOGIN AND PASSWORD)\n2) DEL_PATIENT (LOGIN)\n3) SET_DIAGNOS (LOGIN AND DIAGNOS)\n4) FIND (LOGIN)\n5) ALL_PATIENTS" << endl;
					cout << "Для выхода и сохранения нажмите в любой момент - q!" << endl;
					while (true) {

						cout << "Команда: ";
						cin >> operation;
						if (operation == "ALL_PATIENTS") {
							AllPatients(users);
						}
						else if (operation == "ADD_PATIENT") {
							cin >> login >> password;
							AddPatient(users, login, password);
						}
						else if (operation == "DEL_PATIENT") {
							cin >> login;
							DelPatient(users, login);
						}
						else if (operation == "SET_DIAGNOS") {
							cin >> login;
							cin.getline(diagnos, 63);
							SetDiagnos(users, login, diagnos);
						}
						else if (operation == "FIND") {
							cin >> login;
							Find(users, login);
						}
						else if (operation == "q!") {
							writeAllUsers(users);
							system("pause");
							return 0;
						}
						else {
							cout << "Команда не найдена" << endl;
						}
					}
				}
				else if (cur_permission == 1) {
					string operation;
					cout << "Вы __ПАЦИЕНТ__\nДоступные команды:\n1) CHECK_DIAGNOS (LOGIN)" << endl;
					cout << "Для выхода и сохранения нажмите в любой момент - q!" << endl;
					while (true) {
						cout << "Команда: ";
						cin >> operation;
						if (operation == "CHECK_DIAGNOS") {
							cin >> login;
							CheckDiagnos(users, login);
						}
						else if (operation == "q!") {
							writeAllUsers(users);
							system("pause");
							return 0;
						}
						else {
							cout << "Команда не найдена" << endl;
						}
					}
				}
				else if (cur_permission == 2) {
					string operation;
					cout << "Вы __ГОСТЬ__\nДоступные команды:\n1) CHECK_PATIENT_ID (LOGIN)\n2) CHECK_DIAGNOS (LOGIN)" << endl;
					cout << "Для выхода и сохранения нажмите в любой момент - q!" << endl;
					while (true) {
						cout << "Команда: ";
						cin >> operation;
						if (operation == "CHECK_DIAGNOS") {
							cin >> login;
							CheckDiagnos(users, login);
						}
						else if (operation == "CHECK_PATIENT_ID") {
							cin >> login;
							Find(users, login);
						}
						else if (operation == "q!") {
							writeAllUsers(users);
							system("pause");
							return 0;
						}
						else {
							cout << "Команда не найдена!" << endl;
						}
					}
				}
			}
			else {
				cout << "Неправильный логин или пароль! Повторите попытку" << endl;
			}
		}
	}

	system("pause");
	return 0;
}