#include "Fraction.h"


Fraction::Fraction() {
	numerator = 0;
	denominator = 1;
	
}

Fraction::Fraction(int num, int denom) {
	numerator = num;
	denominator = denom;
	Reduce();
}

int Fraction::gcd(int a, int b) { // Алгорит Евклида (поиск НОД)
	if (a == 0) {
		return 1;
	}
	if (a == b) {
		return a;
	}
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	return gcd(a, b - a);
}

void Fraction::Reduce() { // сокращение дроби 

	int NOD = gcd(abs(numerator), abs(denominator));

	numerator /= NOD;
	denominator /= NOD;

	if (denominator < 0 && numerator < 0) {
		denominator = abs(denominator);
		numerator = abs(numerator);
	}
	else if (denominator < 0 && numerator > 0) {
		denominator = abs(denominator);
		numerator = numerator * (-1);
	}
}

Fraction Fraction::operator+(const Fraction& rhs) {
	return {numerator * rhs.denominator + rhs.numerator * denominator, denominator * rhs.denominator};
}

Fraction Fraction::operator-(const Fraction& rhs) {
	Fraction result;
	result.numerator = numerator * rhs.denominator - rhs.numerator * denominator;
	result.denominator = denominator * rhs.denominator;

	if (result.numerator == 0) {
		return result;
	}
	else
		result.Reduce();

	return result;
}

Fraction Fraction::operator*(const Fraction& rhs) {
	Fraction result;
	result.numerator = numerator * rhs.numerator;
	result.denominator = denominator * rhs.denominator;

	if (result.numerator == 0) {
		return result;
	}
	else
		result.Reduce();

	return result;
}

Fraction Fraction::operator/(const Fraction& rhs) {
	Fraction result;
	result.numerator = numerator * rhs.denominator;
	result.denominator = denominator * rhs.numerator;

	if (result.numerator == 0) {
		return result;
	}
	else
		result.Reduce();

	return result;
}

Fraction Fraction::operator=(const Fraction& rhs) {
	Fraction result;
	
		result.numerator = rhs.numerator;
		result.denominator = rhs.denominator;
		result.Reduce();
	
		return result;

}