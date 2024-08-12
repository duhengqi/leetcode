#ifndef _TEST_CPP_CMATH_H_
#define _TEST_CPP_CMATH_H_
#include <iostream>
#include <vector>
#include <string>
#include "cmath"
#include "gtest.h"

using namespace std;

class TestCPPCmath {
public:
    void testPow(){
        int num0 = pow(5, 2);
        cout << num0 << endl;
        double num1 = pow(0.5, 2);
        cout << num1 << endl;
    }
};

#endif /*_TEST_CPP_CMATH_H_*/
