#ifndef GOD_H
#define GOD_H

#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include "gtest.h"
using namespace std;

void print_test_result(bool result, const char* func) 
{
    if (result == false) {
        cout << func << " FAILED" << endl;
    } else {
        cout << func<< " PASSED" << endl;
    }

}

#endif