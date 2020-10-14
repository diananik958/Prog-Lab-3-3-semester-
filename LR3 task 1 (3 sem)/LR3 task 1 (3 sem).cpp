// LR3 task 1 (3 sem).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
//#include "Fraction.h"
#include "Fraction.h"
#include "TestFraimwork.h"

void AssertEqual(const Fraction& t, const Fraction& u, const string& hint) {
    if (t != u) {
        ostringstream os;
        os << "Assertion failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << "\n hint: " << hint;
        }
        throw runtime_error(os.str());
    }
}

void AssertCompare(const bool& t, const bool& u, const string& hint) {

    if (t != u) {
        ostringstream os;
        os << "Assertion comparison failed: " << t << " != " << u;
        if (!hint.empty()) {
            os << "\n hint: " << hint;
        }
        throw runtime_error(os.str());
    }
  
}


void TestFramework::RunTestMath(const string& hint) {
    try {
        TestMathOperations();
    }
    catch (exception& e) {
        ++fail_test;
        cerr << hint << " fail: " << e.what() << endl;
    }
    catch (...) {
        ++fail_test;
        cerr << "Unknown exception caught" << endl;
    }
}

void TestFramework::RunTestLogic(const string& hint) {
    try {
        TestLogicOperations();
    }
    catch (exception& e) {
        ++fail_test;
        cerr << hint << " fail: " << e.what() << endl;
    }
    catch (...) {
        ++fail_test;
        cerr << "Unknown exception caught" << endl;
    }
}


void TestMathOperations() {

    AssertEqual(Fraction(3, 5) + Fraction(2, 5), Fraction(10, 5), "3/5 + 2/5 = 5/5");  //ERROR
    AssertEqual(Fraction(3, 5) - Fraction(2, 5), Fraction(1, 5), "3/5 - 2/5 = 1/5");
    AssertEqual(Fraction(3, 5) * Fraction(2, 5), Fraction(6, 25), "3/5 * 2/5 = 6/25");
    AssertEqual(Fraction(3, 5) / Fraction(2, 5), Fraction(15, 10), "3/5 / 2/5 = 15/10");

}

void TestLogicOperations() {
   AssertCompare(Fraction(1, 5) > Fraction(2, 5), true, "1/5 > 2/5 false"); //ERROR
   AssertCompare(Fraction(1, 5) < Fraction(2, 5), true, "1/5 < 2/5 true");
   AssertCompare(Fraction(1, 5) <= Fraction(2, 5), true, "1/5 <= 2/5 true");
   AssertCompare(Fraction(1, 5) >= Fraction(2, 5), false, "1/5 >= 2/5 false");
}




int main()
{
	Fraction fraction1;
	Fraction fraction2;

	cout << "Enter first fraction: ";
	cin >> fraction1;
	cout << "Enter second fraction: ";
	cin >> fraction2;

	// cout << fraction1 << endl;
	// cout << fraction2 << endl;

	cout << "\nAddition of fractions: " << fraction1 + fraction2;

	cout << "\nSubstraction of fractions: " << fraction1 - fraction2;

	cout << "\nMultiplication of fractions: " << fraction1 * fraction2;

	cout << "\nDivision of fractions: " << fraction1 / fraction2;

	cout << "\n First fraction is bigger than second (0 - false, 1 - true): " << (fraction1 > fraction2);
//	cout << "\n Second fraction is bigger than first (0 - false, 1 - true): " << (fraction2 > fraction1);

	cout << "\n First fraction is smaller than second (0 - false, 1 - true): " << (fraction1 < fraction2);
//	cout << "\n Second fraction is smaller than first (0 - false, 1 - true): " << (fraction2 < fraction1);

	cout << "\n First fraction is bigger than second or equales it (0 - false, 1 - true): " << (fraction1 >= fraction2);
//	cout << "\n Second fraction is bigger than first or equales it (0 - false, 1 - true): " << (fraction2 > fraction1);

	cout << "\n First fraction is smaller than second or equales it(0 - false, 1 - true): " << (fraction1 <= fraction2);
//	cout << "\n Second fraction is smaller than first or equales it(0 - false, 1 - true): " << (fraction2 < fraction1);

	cout << "\n Equating first fraction to second fraction, now first fraction equals: " << (fraction1 = fraction2);
    

	TestFramework testfrmwrk;
	testfrmwrk.RunTestMath("\n\nTest of Mathematic Operations");
    testfrmwrk.RunTestLogic("\nTest of Logical Operations");
}