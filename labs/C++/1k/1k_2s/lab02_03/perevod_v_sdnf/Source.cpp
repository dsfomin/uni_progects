//��� ������, �� ��������� ��������� � ������ ����������� �� �������� ����������� ��
//������ ����� �� ������� ��� ������� ���� �����.�������� ������, �� ���� ������� ��� ����
//�������

#include <iostream>
#include <exception>
#include <sstream>


#include "Header.h"
#include "Source.h"

using namespace std;

class Polinom {
public:
	Polinom() {};
	Polinom(int koef, int pow) {
		this->koef = koef;
		this->pow = pow;
	}
	int koef;
	int pow;
};

ostream& operator<<(ostream& stream, const Polinom& polinom) {
	stream << polinom.koef << "x^" << polinom.pow;
	return stream;
}

istream& operator>>(istream& stream, Polinom& polinom)
{
	stream >> polinom.koef;
	stream.ignore(2);
	stream >> polinom.pow;
	return stream;
}

istream& operator>>(istream& stream, List<Polinom>& list) {
	Polinom polinom;
	while (stream >> polinom) {
		list.push_back(polinom);
		stream.ignore(2);
	}
	return stream;
}

ostream& operator<<(ostream& stream, List<Polinom>& list) {
	for (int i = 0; i < list.GetSize() - 1; i++) {
		stream << list[i] << " + ";
	}
	stream << list[list.GetSize() - 1];
	return stream;
}

//List<Polinom> operator*(List<Polinom>& first, List<Polinom>& second) {
//
//}

//List<Polinom> operator+(List<Polinom>& first, List<Polinom>& second) {
//
//}

int main() {
	setlocale(0, "rus");
	Polinom pol;
	List<Polinom> first;
	List<Polinom> second;
	string operation;

	cout << "������ ����� ��������: 5, -2; 7, -4; 1, 4; 0, -8;" << endl << endl;
	cout << "��������� �������: \n1) ��������� ���� ��������� \n2) ���������� ���� ��������� \n3) ������� ������� �� ����� " << endl;
	cin >> operation;
	system("cls");
	if (operation == "1") {
		cout << "������� ������ �������: " << endl;
		cin >> first;
		cout << first << endl;
		cout << "������� ������ �������: " << endl;
		cin >> second;
		cout << second << endl;
		/*List<Polinom> third = first * second;
		cout << "��������� ���������: " << third << endl;*/

		
	}
	else if (operation == "2") {
		cout << "������� ������ �������: " << endl;
		cin >> first;
		cout << "������� ������ �������: " << endl;
		cin >> second;
		List<Polinom> third /*= first + second*/;
		cout << "��������� ����������: " << third << endl;
	}
	//else if (operation == "3") {
	//	int divider;
	//	cout << "������� �������: " << endl;
	//	/*cin >> first;*/
	//	cout << "������� ��������" << endl;
	//	cin >> divider;
	//	/*List<Polinom> result_list = first.division(divider);*/
	//	/*cout << "��������� �������: " << result_list << endl;*/
	//}
	else {
		cout << "Command not found!" << endl;
		exit(1);
	}
	system("pause");
	return 0;
}