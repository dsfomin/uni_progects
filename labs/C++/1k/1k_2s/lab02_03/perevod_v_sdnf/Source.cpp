//Два списки, що зберігають структуру з полями «коефіцієнт» та «степінь» впорядковані за
//другим полем та кодують два поліноми однієї змінної.Створити список, що кодує добуток цих двох
//поліномів

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

	cout << "Пример ввода полинома: 5, -2; 7, -4; 1, 4; 0, -8;" << endl << endl;
	cout << "Доступные команды: \n1) Умножение двух полиномов \n2) Добавление двух полиномов \n3) Остаток деления на число " << endl;
	cin >> operation;
	system("cls");
	if (operation == "1") {
		cout << "Введите первый полином: " << endl;
		cin >> first;
		cout << first << endl;
		cout << "Введите второй полином: " << endl;
		cin >> second;
		cout << second << endl;
		/*List<Polinom> third = first * second;
		cout << "Результат умножения: " << third << endl;*/

		
	}
	else if (operation == "2") {
		cout << "Введите первый полином: " << endl;
		cin >> first;
		cout << "Введите второй полином: " << endl;
		cin >> second;
		List<Polinom> third /*= first + second*/;
		cout << "Результат добавления: " << third << endl;
	}
	//else if (operation == "3") {
	//	int divider;
	//	cout << "Введите полином: " << endl;
	//	/*cin >> first;*/
	//	cout << "Введите делитель" << endl;
	//	cin >> divider;
	//	/*List<Polinom> result_list = first.division(divider);*/
	//	/*cout << "Результат деления: " << result_list << endl;*/
	//}
	else {
		cout << "Command not found!" << endl;
		exit(1);
	}
	system("pause");
	return 0;
}