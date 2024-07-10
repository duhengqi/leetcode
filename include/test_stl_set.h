#include <iostream>
#include <set>

using namespace std;

void test_stl_set()
{
    set<int> testSet;
    testSet.insert(3);
    auto iter = testSet.insert(3);
    if (iter.second == false) {
        cout << "insert failed" << endl;
    }

}