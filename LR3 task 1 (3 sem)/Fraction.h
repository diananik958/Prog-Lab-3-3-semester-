#pragma once
#include <iostream>
#include <algorithm>

using namespace std;

class Fraction {
private:
	

public:
	int numerator;
	int denominator;
	Fraction();
	Fraction(int num, int denom);
	int gcd(int a, int b);
	void Reduce();

	friend istream& operator >> (istream& is, Fraction& frac) {
		is >> frac.numerator;
		is.ignore();
		is >> frac.denominator;
		try {
			if (frac.denominator == 0)
				throw exception("We cought an exception: Can not devide by 0!");
		}
		catch (exception& exception) {
			frac.denominator = 1;
			cout << exception.what();
		}

		frac.Reduce();
		return is;
	}

	friend ostream& operator << (ostream& os, const Fraction& frac) {
		os << frac.numerator;
		os << "/";
		os << frac.denominator;
		os << endl;

		return os;
	}

	Fraction operator+(const Fraction& rhs);
	Fraction operator-(const Fraction& rhs);
	Fraction operator*(const Fraction& rhs);
	Fraction operator/(const Fraction& rhs);
	Fraction operator=(const Fraction& rhs);

	friend bool operator>(const Fraction& lhs, const Fraction& rhs) {
		int num1;
		int num2;
		num1 = lhs.numerator * rhs.denominator;
		num2 = rhs.numerator * lhs.denominator;

		if (num1 > num2)
			return true;
		else return false;
	}

	friend bool operator<(const Fraction& lhs, const Fraction& rhs) {
		int num1;
		int num2;
		num1 = lhs.numerator * rhs.denominator;
		num2 = rhs.numerator * lhs.denominator;

		if (num1 < num2)
			return true;
		else return false;
	}

	friend bool operator<=(const Fraction& lhs, const Fraction& rhs) {
		int num1;
		int num2;
		num1 = lhs.numerator * rhs.denominator;
		num2 = rhs.numerator * lhs.denominator;

		if (num1 <= num2)
			return true;
		else
			return true;
	}

	friend bool operator>=(const Fraction& lhs, const Fraction& rhs) {
		int num1;
		int num2;
		num1 = lhs.numerator * rhs.denominator;
		num2 = rhs.numerator * lhs.denominator;

		if (num1 >= num2)
			return true;
		else return false;
	}

	friend bool operator!=(const Fraction& lhs, const Fraction& rhs) {
		return(lhs.numerator * rhs.denominator != rhs.numerator * lhs.denominator);
	}

};