#ifndef _TEST_STL_VECTOR_H_
#define _TEST_STL_VECTOR_H_

#include <iostream>
#include <vector>

using namespace std;
/**
 * vector 实现的是一个动态数组，即可以进行元素的插入和删除，vector 会动态调整所占用的内存空间。
 * vector 常被称为向量容器，尾部插入或删除元素，在常量时间内就可以完成，时间复杂度为O(1)
 * 而对于在容器头部或者中部插入或删除元素，则花费时间要长一些（移动元素需要耗费时间），时间复杂度为线性阶O(n)
 */
class test_stl_vector {
public:

    void test_stl_vector_init()
    {
        /* 空vector 容器，容器中没有元素。当添加第一个元素（比如 push_back()）时，vector会自动分配内存。*/
        vector<double> values;

        /**
         * 容器的内存分配，即至少可以容纳 20 个元素。如果 vector 的容量已经大于或等于 20，那么这条语句什么也不做； 
         * 调用 reserve() 不会影响已存储的元素，也不会生成任何元素，即 values容器内此时仍然没有任何元素。 
         * 还需注意的是，调用 reserve(),之前的迭代器都可能会失效，
         * 这是因为，vector<T> 容器的元素可能已经被复制或移到了新的内存地址。
         */
        values.reserve(20);

        vector<int> primes{2, 3, 5, 7, 11, 13, 17, 19};

        /**
         * values 容器开始时就有 20 个元素，它们的默认初始值都为 0。(20) 表示元素的个数， {20}  则表示一个元素 20
         * 注意，(20) 表示元素的个数， {20}  则表示一个元素 20
         * */
        vector<double> values_nums(20);

        /* 第二个参数指定了所有元素的初始值，因此这 20 个元素的值都是 1.0。*/
        vector<double> values0(20, 1.0);

        /* 圆括号 () 中的 2 个参数，既可以是常量，也可以用变量来表示，例如：*/
        int num = 20;
        double value = 1.0;
        vector<double> values00(num, value);

        /* 通过存储元素类型相同的其它 vector 容器，也可以创建新的 vector 容器，例如：*/
        /* value2 容器中也具有 5 个字符 'c'。*/
        std::vector<char> value1(5, 'c');
        std::vector<char> value2(value1);

        /* 可以用一对指针或者迭代器来指定初始值的范围，例如： values 将保存{1,2} */
        int array[] = {1, 2, 3};
        std::vector<int> value10(array, array + 2);

        /* value2 容器中就包含了 {1,2,3} 这 3 个元素。*/
        std::vector<int> value100{1, 2, 3, 4, 5};
        std::vector<int> value200(std::begin(value1), std::begin(value1) + 3); // value2保存{1,2,3}
    }

    void test_stl_vector_insert()
    {

        vector<char> value;
        value.push_back('S');
        value.push_back('T');
        value.push_back('L');

        for (auto iter = value.begin(); iter < value.end(); iter++) {
            cout << *iter << " ";
        }
        cout << endl;

        /* 向容器开头插入字符*/
        value.insert(value.begin(), 'C');
        /*vector at() 的索引会造成越界时，会抛出std::out_of_range异常*/
        cout << "首个元素为：" << value.at(0) << endl;

        vector<int> values{1,2,3,4,5};
        /* 输出容器中第 3 个元素的值 */
        cout << *(values.data() + 2) << endl;
        /* 修改容器中第 2 个元素的值 */
        *(values.data() + 1) = 10;
        cout << *(values.data() + 1) << endl;

        for (auto&& tmp : values) {
            cout << tmp << " ";
        }

    }
};

#endif /*_TEST_STL_VECTOR_H_*/
