#include <iostream>
#include <queue>
#include <list>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        /*
         The function call operator () can be overloaded for objects
         of class type. When you overload ( ), you are not creating 
         a new way to call a function.
         Rather, you are creating an operator function that can be 
         passed an arbitrary number of parameters.
         priority_queue優先判定為!cmp，所以「由大排到小」需「反向」定義
         實現「最小值優先」
         */
        return a > b;
    }
};

void test_stl_priority_queue()
{
    // priority_queue<int> pq;
    priority_queue<int, vector<int>, cmp> pq;
    pq.push(8);
    pq.push(10);
    pq.push(6);
    pq.push(5);
    while (!pq.empty()){
        auto now = pq.top();
        pq.pop();
        cout << now << endl;
    }
}


#define pii pair<int,int>
#define F first
#define S second
 
void test_stl_priority_queue2()
{
    priority_queue <pii> pq;
    pq.push({4, 5});
    pq.push({5, 3});
    pq.push({4, 8});
    pq.push({2, 7});
    pq.push({3, 2});
 
    while (!pq.empty()){
        auto now = pq.top();
        pq.pop();
        cout << now.F << " " << now.S << endl;
    }
}