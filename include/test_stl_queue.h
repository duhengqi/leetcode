#include <iostream>
#include <queue>

using namespace std;

struct test_priority_queue_cmp {
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
    //默认优先级队列 大的在顶部，pop是取出最大值
    // priority_queue<int> pq; 

    //修改cmp，小的在顶部，pop是取出最小值
    priority_queue<int, vector<int>, test_priority_queue_cmp> pq;
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