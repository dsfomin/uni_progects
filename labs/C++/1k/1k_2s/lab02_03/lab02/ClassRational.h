#ifndef CLASS_RATIONAL_H
#define CLASS_RATIONAL_H

#include <exception>
#include <sstream>
#include "HeaderList.h"


class Rational {
public:
	Rational() {
		num = 0;
		den = 1;
	}

	Rational(int numerator, int denominator) {
		if (denominator == 0)
			//throw invalid_argument("Invalid argument");
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
		//throw domain_error("Division by zero");
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

bool operator<(const Rational& rhs, const Rational& lhs) {
	return rhs.Numerator()*lhs.Denominator() <
		rhs.Denominator()*lhs.Numerator();
}

#endif