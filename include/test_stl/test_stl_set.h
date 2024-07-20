#ifndef _TEST_STL_SET_H_
#define _TEST_STL_SET_H_

#include <iostream>
#include <set>

using namespace std;

class test_stl_set {
public:
    void test_stl_set_init()
    {
        set<int> testSet;
        testSet.insert(3);
        auto iter = testSet.insert(3);
        if (iter.second == false) {
            cout << "insert failed" << endl;
        }

    }
};

#endif /*_TEST_STL_SET_H_*/
