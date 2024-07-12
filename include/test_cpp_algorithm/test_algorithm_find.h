#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include <cstring>
using namespace std;

/**
* InputIterator find (InputIterator first, InputIterator last, const T& val);
* 其中，first 和 last 为输入迭代器，[first, last) 用于指定该函数的查找范围；val 为要查找的目标元素。
* 正因为 first 和 last 的类型为输入迭代器，因此该函数适用于所有的序列式容器。
* 函数返回输入迭代器，当 find() 函数查找成功时，其指向的是在 [first, last) 区域内查找到的第一个目标元素；如果查找失败，则该迭代器的指向和 last 相同。
* find() 函数的底层实现，其实就是用==运算符将 val 和 [first, last) 区域内的元素逐个进行比对。
* 这也就意味着，[first, last) 区域内的元素必须支持==运算符
*/

void test_algorithm_find()
{
    char stl[] ="I am studying cpp stl";
    char * p = find(stl, stl + strlen(stl), 'c');
    if (p != stl + strlen(stl)) {
        cout << p << endl;
    }

    std::vector<int> myvector{ 10,20,30,40,50 };
    std::vector<int>::iterator it;
    it = find(myvector.begin(), myvector.end(), 30);
    if (it != myvector.end()) {
        cout << "查找成功：" << *it;
    } else {
        cout << "查找失败";
    }
    cout << endl;
}