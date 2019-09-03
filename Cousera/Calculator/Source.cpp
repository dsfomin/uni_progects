#include <iostream>
#include <exception>
#include <sstream>

using namespace std;

class Rational {
public:
	Rational() {
		num = 0;
		den = 1;
	}

	Rational(int numerator, int denominator) {
		if (denominator == 0)
			throw invalid_argument("Invalid argument");
		if (denominator < 0) {
			if (numerator < 0) {
				denominator = abs(denominator);
				numerator = abs(numerator);
			}
			else {
				denominator = abs(denominator);
				numerator = -numerator;
			}
		}
		if (numerator == 0) {
			denominator = 1;
		}
		int nod = Nod(abs(numerator), abs(denominator));
		num = numerator / nod;
		den = denominator / nod;
	}

	int Numerator() const {
		return num;
	}

	int Denominator() const {
		return den;
	}

private:
	int num;
	int den;

	int Nod(int a, int b) {
		while (a > 0 && b > 0) {
			if (a > b) {
				a %= b;
			}
			else {
				b %= a;
			}
		}
		return a + b;
	}
};

Rational operator/(const Rational& rhs, const Rational& lhs) {
	if (lhs.Numerator() == 0) {
		throw domain_error("Division by zero");
	}
	Rational res(rhs.Numerator()*lhs.Denominator(),
		rhs.Denominator()*lhs.Numerator());
	return res;
}

Rational operator+(const Rational& rhs, const Rational& lhs) {
	Rational res(rhs.Numerator()*lhs.Denominator() + lhs.Numerator()*rhs.Denominator(),
		rhs.Denominator()*lhs.Denominator());
	return res;
}

Rational operator-(const Rational& rhs, const Rational& lhs) {
	Rational res(rhs.Numerator()*lhs.Denominator() - lhs.Numerator()*rhs.Denominator(),
		rhs.Denominator()*lhs.Denominator());
	return res;
}

bool operator==(const Rational& rhs, const Rational& lhs) {
	if (rhs.Numerator() == lhs.Numerator() && rhs.Denominator() == lhs.Denominator())
		return true;
	return false;
}

Rational operator*(const Rational& rhs, const Rational& lhs) {
	Rational res(rhs.Numerator()*lhs.Numerator(),
		rhs.Denominator()*lhs.Denominator());
	return res;
}

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

bool operator<(const Rational& rhs, const Rational& lhs) {
	return rhs.Numerator()*lhs.Denominator() <
		rhs.Denominator()*lhs.Numerator();
}

int main() {
	try {
		int rhs_n, rhs_d, lhs_n, lhs_d;
		char operation;

		cin >> rhs_n;
		cin.ignore(1);
		cin >> rhs_d;
		cin.ignore(1);
		cin >> operation;
		cin.ignore(1); 
		cin >> lhs_n;
		cin.ignore(1); 
		cin >> lhs_d;

		Rational r1(rhs_n, rhs_d);
		Rational r2(lhs_n, lhs_d);

		if (operation == '*')
			cout << r1 * r2 << endl;
		else if (operation == '/')
			cout << r1 / r2 << endl;
		else if (operation == '+')
			cout << r1 + r2 << endl;
		else if (operation == '-')
			cout << r1 - r2 << endl;
	}
	catch (invalid_argument& e) {
		cout << e.what() << endl;
	}
	catch (domain_error& e) {
		cout << e.what() << endl;
	}
	system("pause");
	return 0;
}
