#pragma once
#include <ostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Fraction.h"
using namespace std;

void AssertEqual(const Fraction& t, const Fraction& u, const string& hint = {});
void AssertCompare(const bool& t, const bool& u, const string& hint = {});

class TestFramework {
private:
    int fail_test = 0;
public:
  
   void RunTestMath(const string& hint);
   void RunTestLogic(const string& hint);
 
    ~TestFramework() {
        cerr << fail_test << " is down" << endl;
    }
};

void TestMathOperations();
void TestLogicOperations();


