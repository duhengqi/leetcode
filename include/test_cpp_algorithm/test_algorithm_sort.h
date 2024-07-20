#ifndef _TEST_ALGORITHM_SORT_H_
#define _TEST_ALGORITHM_SORT_H_


#include <iostream>
#include <algorithm>
#include <list>
#include <string>
#include <vector>
using namespace std;

/**
 * C++ STL 标准库中的 sort()  函数，本质就是一个模板函数。
 * 排序规则默认以元素值的大小做升序排序，sort() 函数是基于快速排序实现的
 * 注意：普通数组和具备以下条件的容器，才能使用 sort() 函数：
 * 容器支持的迭代器类型必须为随机访问迭代器。这意味着，sort() 只对 array、vector、deque 这 3 个容器提供支持。
 * 如果对容器中指定区域的元素做默认升序排序，则元素类型必须支持<小于运算符；
 * 同样，如果选用标准库提供的其它排序规则，元素类型也必须支持该规则底层实现所用的比较运算符；
 * sort() 函数在实现排序时，需要交换容器中元素的存储位置如果容器中存储的是自定义的类对象，该类的内部必须提供移动构造函数和移动赋值运算符。
 * 此外，sort()排序是不稳定的，相同值的位置排序后可能会变化
 * 该函数实现排序的平均时间复杂度为N*log2N（其中 N 为指定区域 [first, last) 中 last 和 first 的距离）。
 *
 * 语法：
 * 1，对 [first, last) 区域内的元素做默认的升序排序
 * void sort (RandomAccessIterator first, RandomAccessIterator last);
 * 2，按照指定的 comp 排序规则，对 [first, last) 区域内的元素进行排序
 * void sort (RandomAccessIterator first, RandomAccessIterator last, Compare comp);
*/

//以普通函数的方式实现自定义排序规则
bool mycomp(int i, int j) {
    return (i > j);
}
//以函数对象的方式实现自定义排序规则
class mycomp2 {
public:
    bool operator() (int i, int j) {
        return (i > j);
    }
};

void test_algorithm_sort()
{
    vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };
    sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71) 26 80 53 33

    //调用第二种语法格式，利用STL标准库提供的其它比较规则（比如 greater<T>）进行排序
    sort(myvector.begin(), myvector.begin() + 4, greater<int>()); //(71 45 32 12) 26 80 53 33
   
    //调用第二种语法格式，通过自定义比较规则进行排序
    sort(myvector.begin(), myvector.end(), mycomp);//12 26 32 33 45 53 71 80
    sort(myvector.begin(), myvector.end(), mycomp2());//12 26 32 33 45 53 71 80

    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << ' ';
    }
}

/**
 * stable_sort()可以保证不改变相等元素的相对位置
 * stable_sort() 函数的用法也有 2 种，其语法格式和 sort() 函数完全相同（仅函数名不同）
 * 当可用空间足够的情况下，该函数的时间复杂度可达到O(N*log2(N))；
 * 反之，时间复杂度为O(N*log2(N)2)，其中 N 为指定区域 [first, last) 中 last 和 first 的距离
*/
void test_algorithm_stable_sort()
{
    vector<int> myvector{ 32, 71, 12, 45, 26, 80, 53, 33 };

    stable_sort(myvector.begin(), myvector.begin() + 4); //(12 32 45 71) 26 80 53 33

    stable_sort(myvector.begin(), myvector.begin() + 4, greater<int>()); //(71 45 32 12) 26 80 53 33

    stable_sort(myvector.begin(), myvector.end(), mycomp);//12 26 32 33 45 53 71 80

    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << ' ';
    }
}

/**
 * 部分排序 partial_sort() 函数有 2 种用法，其语法格式分别为：
 * 对 [first, last) 范围的数据进行筛选并排序
 * void partial_sort (RandomAccessIterator first,
 *                    RandomAccessIterator middle,
 *                    RandomAccessIterator last);
 * 按照 comp 排序规则，对 [first, last) 范围的数据进行筛选并排序
 * void partial_sort (RandomAccessIterator first,
 *                    RandomAccessIterator middle,
 *                    RandomAccessIterator last,
 *                    Compare comp);
 * 其中，first、middle 和 last 都是随机访问迭代器，comp 参数用于自定义排序规则。
 * partial_sort() 函数会以交换元素存储位置的方式实现部分排序的。
 * 具体来说，partial_sort() 会将 [first, last) 范围内最小（或最大）的 middle-first 个元素移动到 [first, middle) 区域中，并对这部分元素做升序（或降序）排序。
 * 只有普通数组和具备以下条件的容器，才能使用 partial_sort() 函数：
 * 容器支持的迭代器类型必须为随机访问迭代器。这意味着，partial_sort() 函数只适用于 array、vector、deque 这 3 个容器。
 * 当选用默认的升序排序规则时，容器中存储的元素类型必须支持 <小于运算符；同样，如果选用标准库提供的其它排序规则，元素类型也必须支持该规则底层实现所用的比较运算符；
 * partial_sort() 函数在实现过程中，需要交换某些元素的存储位置。因此，如果容器中存储的是自定义的类对象，则该类的内部必须提供移动构造函数和移动赋值运算符。
 * partial_sort() 函数实现排序的平均时间复杂度为N*log(M)，其中 N 指的是 [first, last) 范围的长度，M 指的是 [first, middle) 范围的长度
*/

void test_algorithm_partial_sort()
{
    vector<int> myvector{ 3,2,5,4,1,6,9,7};
    //以默认的升序排序作为排序规则，将 myvector 中最小的 4 个元素移动到开头位置并排好序
    /*1 2 3 4 5 6 9 7 */
    partial_sort(myvector.begin(), myvector.begin() + 4, myvector.end());
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    // 以指定的 mycomp2 作为排序规则，将 myvector 中最大的 4 个元素移动到开头位置并排好序
    /*9 7 6 5 1 2 3 4*/
    partial_sort(myvector.begin(), myvector.begin() + 4, myvector.end(), mycomp2());
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

}

/**
 * partial_sort_copy() 函数先将选定的部分元素拷贝到另外指定的数组或容器中，然后再对这部分元素进行排序。
 * 默认以升序规则进行部分排序
 * RandomAccessIterator partial_sort_copy (
 *                        InputIterator first,
 *                        InputIterator last,
 *                        RandomAccessIterator result_first,
 *                        RandomAccessIterator result_last);
 * 以 comp 规则进行部分排序
 * RandomAccessIterator partial_sort_copy (
 *                        InputIterator first,
 *                        InputIterator last,
 *                        RandomAccessIterator result_first,
 *                        RandomAccessIterator result_last,
 *                        Compare comp);
 * 其中，first 和 last 为输入迭代器；result_first 和 result_last 为随机访问迭代器；comp 用于自定义排序规则。
 * partial_sort_copy() 函数会将 [first, last) 范围内最小（或最大）的 result_last-result_first 个元素复制到 [result_first, result_last) 区域中，并对该区域的元素做升序（或降序）排序。
 * 值得一提的是，[first, last] 中的这 2 个迭代器类型仅限定为输入迭代器，这意味着相比 partial_sort() 函数
 * partial_sort_copy() 函数放宽了对存储原有数据的容器类型的限制。
 * 换句话说，partial_sort_copy() 函数还支持对 list 容器或者 forward_list 容器中存储的元素进行“部分排序”，而 partial_sort() 函数不行。
 * 
 * 但是，result_first 和 result_last 仍为随机访问迭代器，因此 [result_first, result_last) 指定的区域仍仅限于普通数组和部分类型的容器，这和 partial_sort() 函数对容器的要求是一样的。
 * partial_sort_copy() 函数实现排序的平均时间复杂度为N*log(min(N,M))，其中 N 指的是 [first, last) 范围的长度，M 指的是 [result_first, result_last) 范围的长度
 * */

void test_algorithm_partial_sort_copy()
{
    int myints[5] = { 0 };
    list<int> mylist{ 3,2,5,4,1,6,9,7 };
 
    partial_sort_copy(mylist.begin(), mylist.end(), myints, myints + 5);
    /*1 2 3 4 5 */
    for (int i = 0; i < 5; i++) {
        cout << myints[i] << " ";
    }
    cout << endl;

    partial_sort_copy(mylist.begin(), mylist.end(), myints, myints + 5, mycomp2());

    /*9 7 6 5 4*/
    for (int i = 0; i < 5; i++) {
        cout << myints[i] << " ";
    }
    cout << endl;
}

/**
 * 当采用默认的升序排序规则（less<T>）时，该函数可以从某个序列中找到第 n 小的元素 K，并将 K 移动到序列中第 n 的位置处。
 * 整个序列经过 nth_element() 函数处理后，所有位于 K 之前的元素都比 K 小，所有位于 K 之后的元素都比 K 大。
 * 将 nth_element() 函数的排序规则自定义为降序排序，此时该函数会找到第 n 大的元素 K 并将其移动到第 n 的位置处，
 * 同时所有位于 K 之前的元素都比 K 大，所有位于 K 之后的元素都比 K 小。
 * nth_element() 函数有以下 2 种语法格式：
 * 排序规则采用默认的升序排序
 * void nth_element (RandomAccessIterator first,
 *                   RandomAccessIterator nth,
 *                   RandomAccessIterator last);
 * 排序规则为自定义的 comp 排序规则
 * void nth_element (RandomAccessIterator first,
 *                   RandomAccessIterator nth,
 *                   RandomAccessIterator last,
 *                   Compare comp);
 * 其中，各个参数的含义如下：
 * first 和 last：都是随机访问迭代器，[first, last) 用于指定该函数的作用范围（即要处理哪些数据）；
 * nth：也是随机访问迭代器，其功能是令函数查找“第 nth 大”的元素，并将其移动到 nth 指向的位置；
 * comp：用于自定义排序规则。
 * 
 * 注意，鉴于 nth_element() 函数中各个参数的类型，其只能对普通数组或者部分容器进行排序。换句话说，只有普通数组和符合以下全部条件的容器，才能使用使用 nth_element() 函数：
 * 容器支持的迭代器类型必须为随机访问迭代器。这意味着，nth_element() 函数只适用于 array、vector、deque 这 3 个容器。
 * 当选用默认的升序排序规则时，容器中存储的元素类型必须支持 <小于运算符；同样，如果选用标准库提供的其它排序规则，元素类型也必须支持该规则底层实现所用的比较运算符；
 * nth_element() 函数在实现过程中，需要交换某些元素的存储位置。因此，如果容器中存储的是自定义的类对象，则该类的内部必须提供移动构造函数和移动赋值运算符。
*/

void test_algorithm_nth_element()
{
    vector<int> myvector{3,1,2,5,4};
    /* 默认的升序排序作为排序规则 */
    nth_element(myvector.begin(), myvector.begin()+2, myvector.end());
    /* 2 1 3 4 5 */
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;

    /* 自定义的 mycomp2() 或者 mycomp1 降序排序作为排序规则 */
    nth_element(myvector.begin(), myvector.begin() + 3, myvector.end(),mycomp);
    /*3 5 4 2 1*/
    for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
        cout << *it << ' ';
    }
    cout << endl;
}

/**
 * is_sorted() 函数有 2 种语法格式，分别是：
 * 判断 [first, last) 区域内的数据是否符合 std::less<T> 排序规则，即是否为升序序列
 * bool is_sorted (ForwardIterator first, ForwardIterator last);
 * 判断 [first, last) 区域内的数据是否符合 comp 排序规则  
 * bool is_sorted (ForwardIterator first, ForwardIterator last, Compare comp);
 * 其中，first 和 last 都为正向迭代器（这意味着该函数适用于大部分容器），[first, last) 用于指定要检测的序列；comp 用于指定自定义的排序规则。
 * 注意，如果使用默认的升序排序规则，则 [first, last) 指定区域内的元素必须支持使用 < 小于运算符做比较；
 * 同样，如果指定排序规则为 comp，也要保证 [first, last) 区域内的元素支持该规则内部使用的比较运算符。
 * 如果 [first, last) 范围内的序列符合我们指定的排序规则，则返回true；反之，函数返回false。如果 [first, last) 指定范围内只有1个元素,函数始终返回true
*/
void test_algorithm_is_sorted()
{
    vector<int> myvector{ 3,1,2,4 };
    list<int> mylist{ 1,2,3,4 };

    //调用第 2 种语法格式的 is_sorted() 函数，该判断语句会得到执行
    if (!is_sorted(myvector.begin(), myvector.end(),mycomp2())) {
        cout << "开始对 myvector 容器排序" << endl;
        //对 myvector 容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出 myvector 容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << " ";
        }
    }
   
    //调用第一种语法格式的 is_sorted() 函数，该判断语句得不到执行
    if (!is_sorted(mylist.begin(), mylist.end())) {
        cout << "开始对 mylist 排序" << endl;
        //......
    }
}

/**
 * is_sorted_until() 函数不仅能检测出某个序列是否有序，还会返回一个正向迭代器，指向序列中第一个破坏有序状态的元素。
 * 排序规则为默认的升序排序
 * ForwardIterator is_sorted_until (ForwardIterator first, ForwardIterator last);
 * //排序规则是自定义的 comp 规则
 * ForwardIterator is_sorted_until (ForwardIterator first,
 *                                  ForwardIterator last,
 *                                  Compare comp);
 * 其中，first 和 last 都为正向迭代器（这意味着该函数适用于大部分容器），[first, last) 用于指定要检测的序列；comp 用于指定自定义的排序规则。
 * 注意，如果使用默认的升序排序规则，则 [first, last) 指定区域内的元素必须支持使用 < 小于运算符做比较；
 * 同样，如果指定排序规则为 comp，也要保证 [first, last) 区域内的元素支持该规则内部使用的比较运算符。
 * 注意，如果 [first, last) 指定的序列完全满足默认排序规则或者 comp 排序规则的要求，则该函数将返回一个和 last 迭代器指向相同的正向迭代器。
*/
void test_algorithm_is_sorted_until()
{
    vector<int> myvector{ 3,1,2,4 };
    list<int> mylist{ 1,2,3,4 };
    //如果返回值为 myvector.end()，则表明 myvector 容器中的序列符合 mycomp2() 规则
    if (is_sorted_until(myvector.begin(), myvector.end(),mycomp2()) != myvector.end()) {
        cout << "开始对 myvector 容器排序" << endl;
        //对 myvector 容器做降序排序
        sort(myvector.begin(), myvector.end(),mycomp2());
        //输出 myvector 容器中的元素
        for (auto it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << " ";
        }
    }
   
    //该判断语句得不到执行
    if (is_sorted_until(mylist.begin(), mylist.end()) != mylist.end()) {
        cout << "开始对 mylist 排序" << endl;
        //......
    }

}

#endif /* _TEST_ALGORITHM_SORT_H_ */
