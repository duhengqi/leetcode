#ifndef _TEST_STL_MULTISET_H_
#define _TEST_STL_MULTISET_H_

#include <iostream>
#include <set>

using namespace std;

class test_stl_multiset {
public:
    void test_stl_multiset_init()
    {
        multiset<int> testSet;
        testSet.insert(10);
        auto iter = testSet.begin();

        testSet.insert(8);
        testSet.insert(9);
        testSet.insert(3);
        testSet.insert(11);
        // iter++;
    
        // multiset is orderly. from small to large default
        for (iter = testSet.begin(); iter != testSet.end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;

        iter = testSet.insert(100);
        testSet.insert(100);
        cout << *iter << endl;
        iter--;
        cout << *iter << endl;
    }
};

#endif /*_TEST_STL_MULTISET_H_*/
