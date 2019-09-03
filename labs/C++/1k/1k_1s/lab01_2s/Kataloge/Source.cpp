#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <experimental/filesystem>

using namespace std;
namespace fs = experimental::filesystem;

const char* PATH = "DataBase/";
const char* CPATH = "counter.dat";

struct Diagnos {
	char doctor[64] = "";
	char diagnos[128] = "";
};

struct User {              //Инфа по человеку
	char login[64] = "";
	char pass[64] = "";
	int permission = 0;
	int id = 0;
	char diagnos[128] = "";
	/*vector<Diagnos> diagnoses;*/
};

char* CurPath(int ID);
char * int2char(int iNumber);
void ReadUserF(User& user, experimental::filesystem::v1::path PATH);

bool Check(char login[64], char password[64])
{

	for (const auto & entry : fs::directory_iterator("DataBase")) {
		User user;
		auto path = entry.path();
		ReadUserF(user, path);
		if (strcmp(user.login, login) == 0 && strcmp(user.pass, password) == 0)
			return true;
	}
	return false;
}

int PermissionF(char login[64]) {
	for (const auto & entry : fs::directory_iterator("DataBase")) {
		User user;
		auto path = entry.path();
		ReadUserF(user, path);
		if (strcmp(user.login, login) == 0)
			return user.permission;
	}
	return 0;
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

void WriteUser(User user, char* PATH)
{
	ofstream fout(PATH, ofstream::binary);

	fout.write((char*)&user, sizeof(User));

	fout.close();
}

void WriteUserF(User user, experimental::filesystem::v1::path PATH)
{
	ofstream fout(PATH, ofstream::binary);

	fout.write((char*)&user, sizeof(User));

	fout.close();
}

void ReadUserF(User& user, experimental::filesystem::v1::path PATH)
{
	ifstream fin(PATH);

	fin.read((char*)&user, sizeof(User));

	fin.close();
}

void ReadUser(User user, char* PATH)
{
	ifstream fin(PATH);

	fin.read((char*)&user, sizeof(User));

	fin.close();
}

char* CurPath(int ID) {
	char CURPATH[64];
	char id[64];
	fstream counter(CPATH);
	strcpy_s(id, int2char(ID));
	strcpy_s(CURPATH, "DataBase/");
	strcat_s(CURPATH, sizeof(CURPATH), id);
	strcat_s(CURPATH, sizeof(CURPATH), ".dat\0");
	return CURPATH;
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

void AddPatientF(char *login, char *password) {
	User user;
	fstream counter;
	char CURPATH[64];

	strcpy_s(user.login, login);
	strcpy_s(user.pass, password);


	int ID = CheckID(counter); // Начинается с 1
	user.id = ID;
	user.permission = 1;

	strcpy_s(CURPATH, CurPath(user.id));

	WriteUser(user, CURPATH);

	cout << "Добавлен новый пациент!" << endl;
}

void AllPatients() {
	for (const auto & entry : fs::directory_iterator("DataBase")) {
		User user;
		auto path = entry.path();
		ReadUserF(user, path);
		if (user.permission == 1)
			cout << "Login: " << user.login << " ID: " << user.id << endl;
	}
}

void DelPatient(char *login) {
	int i = 0;
	bool valid = false;
	for (const auto & entry : fs::directory_iterator("DataBase")) {
		User user;
		auto path = entry.path();
		ReadUserF(user, path);
		if (strcmp(user.login, login) == 0) {
			remove(entry.path());
			valid = true;
			cout << "Пациент " << user.login << " успешно удален" << endl;
		}
	}
	if (valid == false)
		cout << "Пациента с таким логином нет!" << endl;
}

void SetDiagnos(char *login, char *diagnos) {
	bool valid = false;
	char extra[64];
	User user;
	fs::path CurrentPath;
	const std::experimental::filesystem::v1::path string;
	for (const auto & entry : fs::directory_iterator("DataBase")) {;
		ReadUserF(user, entry.path());
		if (strcmp(user.login, login) == 0) {
			strcpy_s(extra, sizeof(extra), diagnos);
			valid = true;
			cout << "Диагноз успешно определен" << endl;
			CurrentPath = entry.path();
		}
	}
	if (isspace(extra[0])) {
		while (isspace(extra[0])) {
			memmove(&extra[0], &extra[1], strlen(extra));
		}
	}
	strcpy_s(user.diagnos , sizeof(user.diagnos), extra);

	WriteUserF(user, CurrentPath);
	if (valid == false)
		cout << "Пациента с таким логином нет!" << endl;
}

void Find(char *login) {
	bool valid = false;
	for (const auto & entry : fs::directory_iterator("DataBase")) {
		User user;
		auto path = entry.path();
		ReadUserF(user, path);
		if (strcmp(user.login, login) == 0) {
			valid = true;
			cout << "Login: " << user.login << " ID: " << user.id << endl;
		}
	}
	if (valid == false)
		cout << "Пациента с таким логином нет!" << endl;
}

void CheckDiagnos(char *login) {
	bool valid = false;
	for (const auto & entry : fs::directory_iterator("DataBase")) {
		User user;
		auto path = entry.path();
		ReadUserF(user, path);
		if (strcmp(user.login, login) == 0) {
			valid = true;
			if (strcmp(user.diagnos, "") != 0) {
				cout << user.diagnos << endl;
				continue;
			}
			else {
				cout << "Диагноза еще нет!" << endl;
				continue;
			}
		}
	}
	if (valid == false)
		cout << "Пациента с таким логином нет!" << endl;
}

char * int2char(int iNumber) {
	int iNumbersCount = 0;
	int iTmpNum = iNumber;
	while (iTmpNum) {
		iTmpNum /= 10;
		iNumbersCount++;
	}
	char *buffer = new char[iNumbersCount + 1];
	for (int i = iNumbersCount - 1; i >= 0; i--) {
		buffer[i] = (char)((iNumber % 10) | 48);
		iNumber /= 10;
	}
	buffer[iNumbersCount] = '\0';
	return buffer;

}

int Menu(int permission) {
	int cur_permission = permission;
	char login[64], password[64], diagnos[64];

	if (permission == 0) {
		string operation = "";
		while (operation != "q!") {
			cout << "Вы __ВРАЧ__\nДоступные команды:\n1) ADD_PATIENT (LOGIN AND PASSWORD)\n2) DEL_PATIENT (LOGIN)\n3) SET_DIAGNOS (LOGIN AND DIAGNOS)\n4) FIND (LOGIN)\n5) ALL_PATIENTS" << endl;
			cout << "Для выхода и сохранения нажмите в любой момент - q!" << endl;
			cout << "Команда: ";
			cin >> operation;
			if (operation == "ALL_PATIENTS") {
				AllPatients();
				system("pause>nul");
				system("cls");
				Menu(cur_permission);
			}
			else if (operation == "ADD_PATIENT") {
				cin >> login >> password;
				AddPatientF(login, password);
				system("pause>nul");
				system("cls");
				Menu(cur_permission);
			}
			else if (operation == "DEL_PATIENT") {
				cin >> login;
				DelPatient(login);
				system("pause>nul");
				system("cls");
				Menu(cur_permission);
			}
			else if (operation == "SET_DIAGNOS") {
				cin >> login;
				cin.getline(diagnos, 63);
				SetDiagnos(login, diagnos);
				system("pause>nul");
				system("cls");
				Menu(cur_permission);
			}
			else if (operation == "FIND") {
				cin >> login;
				Find(login);
				system("pause>nul");
				system("cls");
				Menu(cur_permission);
			}
			else if (operation == "q!") {
				system("pause>nul");
				system("cls");
				return 0;
			}
			else {
				cout << "Команда не найдена" << endl;
				system("pause>nul");
				system("cls");
			}

		}
	}
	else if (permission == 1) {
		string operation;
		while (operation != "q!") {
			cout << "Вы __ПАЦИЕНТ__\nДоступные команды:\n1) CHECK_DIAGNOS (LOGIN)" << endl;
			cout << "Для выхода и сохранения нажмите в любой момент - q!" << endl;

			cout << "Команда: ";
			cin >> operation;
			if (operation == "CHECK_DIAGNOS") {
				cin >> login;
				CheckDiagnos(login);
				system("pause>nul");
				system("cls");
				Menu(cur_permission);
			}
			else if (operation == "q!") {
				system("pause>nul");
				system("cls");
				return 0;
			}
			else {
				cout << "Команда не найдена" << endl;
			}
		}
	}
	else if (permission == 2) {
		string operation;
		while (operation != "q!") {
			cout << "Вы __ГОСТЬ__\nДоступные команды:\n1) CHECK_PATIENT_ID (LOGIN)\n2) CHECK_DIAGNOS (LOGIN)" << endl;
			cout << "Для выхода и сохранения нажмите в любой момент - q!" << endl;

			cout << "Команда: ";
			cin >> operation;
			if (operation == "CHECK_DIAGNOS") {
				cin >> login;
				CheckDiagnos(login);
				system("pause>nul");
				system("cls");
				Menu(cur_permission);
			}
			else if (operation == "CHECK_PATIENT_ID") {
				cin >> login;
				Find(login);
				system("pause>nul");
				system("cls");
				Menu(cur_permission);
			}
			else if (operation == "q!") {
				system("pause>nul");
				system("cls");
				return 0;
			}
			else {
				cout << "Команда не найдена!" << endl;
			}
		}
	}
}

int main() {
	setlocale(0, "rus");
	bool hello;
	char login[64], password[64], diagnos[64];
	int zero = 0;
	string operation;
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

	cout << "ЗДРАСТВУЙТЕ!\nРЕГИСТРАЦИЯ (0) ИЛИ ВХОД (1)" << endl;
	cin >> hello;
	system("cls");

	if (hello == 0) {
		User user;
		cout << "__РЕГИСТРАЦИЯ__" << endl;
		cout << "Введите логин, пароль" << endl;
		cin >> user.login >> user.pass;
		cout << "Кто вы? Врач (0), Пациент (1) или Гость (2)?" << endl;
		cin >> user.permission;

		char CURPATH[64];
		int ID = CheckID(counter); // Начинается с 1
		user.id = ID;

		strcpy_s(CURPATH, CurPath(user.id));
		//user.id = CheckID(counter); // Начинается с 1
		//strcpy_s(id, int2char(user.id));
		//strcpy_s(CURPATH, "DataBase\\");
		//strcat(CURPATH, id);
		//strcat(CURPATH, ".dat");
		WriteUser(user, CURPATH);

		hello = 1;
		system("cls");
	}
	if (hello == 1) {

		cout << "__ВХОД__" << endl;
		cout << "Для выхода и сохранения нажмите в любой момент - q!" << endl;

		while (login != "q!") {
			cout << "Введите логин и пароль" << endl;
			cin >> login;

			if (strcmp(login, "q!") == 0) {
				system("pause>nul");
				system("cls");
				return 0;
			}

			cin >> password;

			if (Check(login, password)) {
				int cur_permission = PermissionF(login);
				system("cls");
				Menu(cur_permission);
			}

			else {
				cout << "Неправильный логин или пароль! Повторите попытку" << endl;
			}
		}
		system("pause>nul");
		return 0;
	}
}