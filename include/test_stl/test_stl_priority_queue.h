#ifndef _TEST_STL_PRIORITY_QUEUE_H_
#define _TEST_STL_PRIORITY_QUEUE_H_

#include <iostream>
#include <queue>
#include <array>
#include <string>

using namespace std;
/**
 * template <typename T,                      //指定存储元素的具体类型；
 *         typename Container=vector<T>,  // 指定底层使用的基础容器，默认使用vector
 *         typename Compare=less<T> >     // 指定容器中评定元素优先级所遵循的排序规则，默认less<T> 从大到小
 * class priority_queue{
 *     //......
 * }
*/
/**
 * 例题：239 最大滑动窗口 dual_pointers_239_maxSlidingWindow.h
*/

class test_stl_priority_queue {
public:
    void test_stl_priority_queue_init()
    {
        //使用普通数组,存储的元素类型和 priority_queue 指定的存储类型
        int values[]{4,1,3,2};
        priority_queue<int>copy_values(values,values+4);//{4,2,3,1}
        //使用序列式容器, 存储的元素类型和 priority_queue 指定的存储类型
        array<int,4> values0 {4,1,3,2};
        priority_queue<int>copy_values0(values0.begin(),values0.end());//{4,2,3,1}

        /* 手动指定 priority_queue 使用的底层容器以及排序规则 */
        int values1[]{ 4,1,2,3 };
        priority_queue<int, deque<int>, greater<int> >copy_values1(values1, values1+4);//{1,3,2,4}
        copy_values1.push(5);//{4,2,3,1}

        while (!copy_values1.empty())
        {
            cout << copy_values1.top()<<" ";
            copy_values1.pop();
        }
        cout << endl;
    }

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

    void test_stl_priority_queue_push()
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
};


#endif /*_TEST_STL_PRIORITY_QUEUE_H_*/
