#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

const char* PATH = "user.txt";
const char* CPATH = "counter.txt";

#pragma pack(push, 1)
class User {               //Инфа по человеку
public:
	User() {};
	User(string login, string pass, int permission, int id) {
		diagnos = "";
		this->login = login;
		this->pass = pass;
		this->permission = permission;
		this->id = id;
	}
	string GetLogin() {
		return login;
	}
	string GetPass() {
		return pass;
	}
	string GetDiagnos() {
		return diagnos;
	}
	int GetPer() {
		return permission;
	}
	int GetID() {
		return id;
	}
private:
	string login;
	string pass;
	string diagnos;
	int permission;
	int id;
};
#pragma pack (pop)

#pragma pack (push, 1)
class Node {                //Проверка на валидность
public:
	Node() {};
	Node(User info, bool del) {
		this->info = info;
		this->del = del;
	}
	bool GetDel(){
		return del;
	}
	User GetInfo(){
		return info;
	}
private:
	User info;
	bool del;
};
#pragma pack (pop)
c

int CurID(fstream& file) {
	file.open(CPATH);

	int ch = 0;

	if (file) {
		file >> ch;
	}

	file.close();

	file.open(CPATH);

	if (file)
		file << ch;

	file.close();

	return ch;
}

bool Check(string login, string password) {
	ifstream file;
	file.open(PATH, ios::in);

	Node node;

	file.read((char*)&node, sizeof(node));

	while (!file.eof()) {
		if (node.GetInfo().GetLogin() == login && node.GetInfo().GetPass() == password && node.GetDel() == 0) {
			return true;
		}
		file.read((char*)&node, sizeof(node));
	}

	//Node node[100];

	//if (!file.eof())
	//	file.read((char*)node, sizeof(node));

	//for (auto item : node) {
	//		if (item.GetInfo().GetLogin() == login && item.GetInfo().GetPass() == password && item.GetDel() == 0) {
	//		file.close();
	//		return true;
	//	}
	//}

	return false;
}

int Permission(fstream& file, string login) {
	file.open(PATH, ios::in | ios::out & ios::binary);
	int per;

	Node node;

	while (!file.eof()) {
		file.read((char*)&node, sizeof(node));
		if (node.GetInfo().GetLogin() == login)
			per = node.GetInfo().GetPer();
	}

	file.close();

	return per;
}

int main() {
	setlocale(0, "rus");
	bool hello;
	string login, password, diagnos;
	int permission, id;
	bool del;
	int zero = 0;

	fstream counter;
	fstream file;

	counter.open(CPATH);

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

	cout << "ЗДРАСТВУЙТЕ!\nРЕГЕСТРАЦИЯ (0) ИЛИ ВХОД (1)" << endl;
	cin >> hello;

	if (hello == 0) {
		cout << "__РЕГЕСТРАЦИЯ__" << endl;
		cout << "Введите логин, пароль" << endl;
		cin >> login >> password;
		cout << "Кто вы? Врач (0), Пациент (1) или Гость (2)?" << endl;
		cin >> permission;

		id = CheckID(counter); // Начинается с 1

		del = 0;

		User user(login, password, permission, id);

		Node node(user, del);

		file.open(PATH, ios::app);

		file.write((char*)&node, sizeof(node));
		hello = 1;

		file.close();
	}
	if (hello == 1) {

		cout << "__ВХОД__" << endl;
		cout << "Для выхода в любой момент нажмите - q!" << endl;

		while (true) {
			cout << "Введите пароль и логин" << endl;
			cin >> login >> password;

			if (Check(login, password)) {
				int cur_permission = Permission(file, login);
				if (cur_permission == 0) {
					string operation;
					cout << "Вы __ВРАЧ__\nДоступные команды:\n1) ADD_PATIENT (LOGIN AND PASSWORD)\n2) DEL_PATIENT (LOGIN)\n3) UPDATE (LOGIN AND DIAGNOSIS)\n4) FIND (LOGIN)" << endl;
					cout << "Команда: ";
					cin >> operation;
					if (operation == "ADD_PATIENT") {
						cin >> login >> password;

					}
					else if (operation == "DEL_PATIENT") {
						cin >> login;

					}
					else if (operation == "UPDATE") {
						cin >> login >> diagnos;
					}
					else if (operation == "FIND") {
						cin >> login;
					}
					else {
						cout << "Команда не найдена" << endl;
					}
				}
				else if (cur_permission == 1) {
					string operation;
					cout << "Вы __ПАЦИЕНТ__\nДоступные команды:\n1) CHECK_DIGNOSIS (LOGIN)\n2) CHECK_APPOINTMENT (LOGIN)" << endl;
					cout << "Команда: ";
					cin >> operation;
					if (operation == "CHECK_DIGNOSIS") {

					}
					else if (operation == "CHECK_APPOINTMENT") {


					}
					else {
						cout << "Команда не найдена" << endl;
					}
				}
				else if (cur_permission == 2) {
					string operation;
					cout << "Вы __ГОСТЬ__\nДоступные команды:\n1) CHECK_PATIENT_ID (LOGIN)\n2) CHECK_DIAGNOSIS (LOGIN)" << endl;
					cout << "Команда: ";
					cin >> operation;
					if (operation == "CHECK_DIGNOSIS") {
						cin >> login;

					}
					else if (operation == "CHECK_PATIENT_ID") {
						cin >> login;

					}
					else {
						cout << "Команда не найдена!" << endl;
					}
				}
			}
			else {
				cout << "Неправильный логин или пароль! Повторите попытку" << endl;
			}
		}
	}

	//ofstream fo(PATH, ios::binary, ofstream::ate);		//Записываем массив O в файл, бинарный режим
	//fo.write((char*)O, sizeof(O));
	//fo.close();


	//ifstream fr(PATH, ios::binary);		//Читаем файл и переносим значения в массив R
	//fr.read((char*)R, sizeof(R));
	//fr.close();

	////Обходим массив R
	//for (unsigned i = 0; i < SIZE; i++) {
	//	cout << R[i].x << ';' << R[i].y << '\n';
	//}

	

	system("pause");
	return 0;
}