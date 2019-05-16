// Дано список.Занести в нього перші N раціональних чисел, використовуючи діагональний
// метод Кантора.Реалізувати функції : пошук числа у списку, видалення заданого числа зі списку, сума
// всіх елементів у списку, додавання наступного числа згідно діагональним методом Кантора.

#include <iostream>
#include <exception>
#include <sstream>

#include "HeaderList.h"
#include "ClassRational.h"

using namespace std;

ostream& operator<<(ostream& stream, const Rational& rational) {
	stream << rational.Numerator() << "/" << rational.Denominator();
	return stream;
}

istream& operator>>(istream& stream, Rational& rational) {
	string str;
	stream >> str;

	if (str.empty()) {
		return stream;
	}

	stringstream ss(str);
	int n, d;
	ss >> n;
	ss.ignore(1);
	ss >> d;
	rational = { n, d };
	return stream;
}

bool CheckNonExist(List<Rational>& list, int i, int j) {
	Rational rational(i, j);
	for (int i = 0; i < list.GetSize(); i++)
		if (rational == list[i])
			return false;
	return true;
}

void PushFirstNRationalNumbersToList(List<Rational>& list, int N) {
	for (int i = 1, j = 1, n = 0; n < N;) {
		if (CheckNonExist(list, i, j))
			list.push_back(Rational(i, j));
		else
			n--;
		if (i % 2 == 1 && j == 1)
			i++;
		else if (i == 1 && j % 2 == 0)
			j++;
		else if ((i + j) % 2 == 1) {
			i--;
			j++;
		}
		else if ((i + j) % 2 == 0) {
			i++;
			j--;
		}
		n++;
	}
}

int main() {
	setlocale(0, "rus");

	List<Rational> list;

	int N;
	cout << "Первые N рациональных чисел: " << endl;
	cin >> N;

	PushFirstNRationalNumbersToList(list, N);

	cout << endl << "Вывод первых N чисел: " << endl << endl;

	for (int i = 0; i < list.GetSize(); i++)
		cout << i + 1 << ": " << list[i] << endl;

	system("pause>nul");
	return 0;
}