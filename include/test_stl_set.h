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

void test_stl_set()
{
    set<int> testSet;
    testSet.insert(3);
    auto iter = testSet.insert(3);
    if (iter.second == false) {
        cout << "insert failed" << endl;
    }

}