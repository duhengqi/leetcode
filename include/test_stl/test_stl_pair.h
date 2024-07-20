#ifndef _TEST_STL_PAIR_H_
#define _TEST_STL_PAIR_H_

#include <iostream>
#include <string>
#include <utility>

using namespace std;
class test_stl_pair {
public:

    void test_stl_pair_init()
    {
        /* 默认构造函数 */
        pair <string, double> pair1;
        pair1.first = "key1";
        pair1.second = 1.0;
        cout << "new pair1: " << pair1.first << " " << pair1.second << endl;

        pair <string, string> pair2("key1","value1");

        /* 拷贝构造函数 */
        pair <string, string> pair3(pair2);

        /* make_pair() 是 <utility> 头文件提供的，其功能是生成一个 pair 对象。
        * 当我们将 make_pair() 函数的返回值（临时对象）传递给 pair() 构造函数时，
        * 其调用的是移动构造函数，而不是拷贝构造函数。*/
        pair <string, string> pair4(make_pair("key2","value2"));
        pair <string, string> pair5 = make_pair("key2", "value2");
        /* 调用第 5 种构造函数 */
        pair <string, string> pair6(string("key3"), string("value3"));  
    
        cout << "pair1: " << pair1.first << " " << pair1.second << endl;
        cout << "pair2: " << pair2.first << " " << pair2.second << endl;
        cout << "pair3: " << pair3.first << " " << pair3.second << endl;
        cout << "pair4: " << pair4.first << " " << pair4.second << endl;
        cout << "pair5: " << pair5.first << " " << pair5.second << endl;
    }

    /** 
     * <utility>头文件 为 pair 对象重载了 <、<=、>、>=、==、!= 这 6 的运算符
     * 其运算规则是：先比较 pair.first 元素的大小，如果相等则继续比较 pair.second 元素的大小。
     * 对于进行比较的2个pair对象，其对应的键和值的类型相同，否则将没有可比性，
     * 同时编译器提示没有相匹配的运算符，即找不到合适的重载运算符。
    */
    void test_stl_pair_compare()
    {
        pair <string, int> pair1("key1", 20);
        pair <string, int> pair2("key2", 20);
        pair <string, int> pair3("key2", 30);
        //pair1和pair2的key不同，value相同
        if (pair1 != pair2) {
            cout << "pair != pair2" << endl;
        }
        //pair2和pair3的key相同，value不同
        if (pair2 != pair3) {
            cout << "pair2 != pair3" << endl;
        }
    }

    /**
     * 互换2个pair对象的键值对，前提是这2个pair对象的键和值的类型要相同
    */
    void test_stl_pair_swap()
    {
        pair <string, int> pair1("pair", 10);                   
        pair <string, int> pair2("pair2", 20);

        pair1.swap(pair2);
        cout << "pair1: " << pair1.first << " " << pair1.second << endl;
        cout << "pair2: " << pair2.first << " " << pair2.second << endl;
        // pair1: pair2 20
        // pair2: pair 10
    }

};

#endif /*_TEST_STL_PAIR_H_*/
