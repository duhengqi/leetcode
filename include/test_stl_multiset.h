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

using namespace std;

void test_stl_multiset()
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