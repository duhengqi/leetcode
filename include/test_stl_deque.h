#include <iostream>
#include <array>
#include <string>
#include <deque>

using namespace std;
/**
 * deque 是 double-ended queue 的缩写，又称双端队列容器。
 * deque 容器擅长在序列序列头部添加或删除元素、尾部添加或删除元素（时间复杂度为O(1)），而不擅长在序列中间添加或删除元素。
 * deque 容器也可以根据需要修改自身的容量和大小。
 * deque 容器中存储元素并不能保证所有元素都存储到连续的内存空间中,不要使用指针去访问deque中指定位置处的元素

 * deque 容器以模板类 deque<T>
 * 
*/

void test_stl_deque()
{

    /* 10 个元素（默认都为 0） */
    deque<int> d0(10);
    /* 10 个元素 值都为 5 */
    deque<int> d1(10, 5);
    /* 拷贝deque容器创建一个新的 deque，新旧容器存储的元素类型一致*/
    deque<int> d2(d1);

    /* 拷贝普通数组，创建deque容器 */
    int a[] = { 1,2,3,4,5 };
    deque<int>d3(a, a + 5);
    /* 适用于所有类型的容器 */
    array<int, 5>arr{ 11,12,13,14,15 };
    deque<int>d(arr.begin()+2, arr.end());//拷贝arr容器中的{13,14,15}

    /**
     *  首尾添加和删除元素 
     * push_back()构造元素，然后再将该元素移动或复制到容器的尾部
     * emplace_back直接在容器头部构造元素，省去了复制或移动元素的过程
     */
    d.push_back(3);
    d.emplace_back(3);
    d.push_front(0);
    d.emplace_front(0);

    d.pop_back();
    d.pop_front();
    for (auto i = d.begin(); i < d.end(); i++) {
        cout << *i << " ";
    }

    cout << endl;
    /* 修改首尾元素 */
    d.front() = 10;
    cout << "deque 新的首元素为：" << d.front() << endl;
    d.back() = 20;
    cout << "deque 新的尾元素为：" << d.back() << endl;
    /* at() 可以访问和修改 */
    cout << "deque " << d.at(0) << endl;

}

/* emplace()用法与insert()相同 */
void test_stl_deque_insert()
{
    deque<int> d{ 1,2 };

    /* iterator insert(pos,elem) */
    /* 在迭代器 pos 之前插入一个新元素elem，并返回表示新插入元素位置的迭代器。 */
    d.insert(d.begin() + 1, 3);//{1,3,2}

    /* iterator insert(pos,n,elem) */
    /* 在迭代器 pos 之前插入 n 个元素 elem，并返回表示第一个新插入元素位置的迭代器。 */
    d.insert(d.end(), 2, 5);//{1,3,2,5,5}

    /* iterator insert(pos,first,last) */
    /* 在迭代器 pos 之前，插入其他容器中位于 [first,last) 区域的所有元素，并返回表示第一个新插入元素位置的迭代器 */
    array<int, 3>test{ 7,8,9 };
    d.insert(d.end(), test.begin(), test.end());//{1,3,2,5,5,7,8,9}

    /* iterator insert(pos,initlist) */
    /* 迭代器 pos 之前，插入初始化列表中所有的元素，并返回表示第一个新插入元素位置的迭代器 */
    d.insert(d.end(), { 10,11 });//{1,3,2,5,5,7,8,9,10,11}

    for (int i = 0; i < d.size(); i++) {
        cout << d[i] << " ";
    }
}