#ifndef _TEST_STL_QUEUE_H_
#define _TEST_STL_QUEUE_H_

#include <iostream>
#include <queue>
#include <list>

using namespace std;
class test_stl_queue {
public:
    void test_stl_queue_init()
    {
        /* 手动指定 queue 容器适配器底层采用的基础容器类型可以选择 deque 和 list。*/
        queue<int, list<int>> values;


    // 存储的元素类型以及底层采用的基础容器类型相同的queue来初始化另一个 queue 容器适配器
        deque<int> values1{1,2,3};
        queue<int> my_queue0(values1);
        queue<int> my_queue1(my_queue0);
        queue<int> my_queue2= my_queue1;


    /* my_queue 底层采用的是deque容器，和values类型一致，且存储的也都是int类型元素 */ 
        deque<int> values0{1,2,3};
        queue<int> my_queue(values0);
        my_queue.push(7);
        my_queue.emplace(8);
        cout << "size of my_queue: " << my_queue.size() << endl;
        cout << "last of my_queue: " << my_queue.back() << endl;
        while (!my_queue.empty())
        {
            cout << my_queue.front() << endl;
            my_queue.pop();
        }

    }
};

#endif /*_TEST_STL_QUEUE_H_*/
