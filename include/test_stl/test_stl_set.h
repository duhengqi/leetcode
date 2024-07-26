#ifndef _TEST_STL_SET_H_
#define _TEST_STL_SET_H_

#include <iostream>
#include <set>

using namespace std;
/**
 * 成员方法	功能
 * begin()	            返回指向容器中第一个（注意，是已排好序的第一个）元素的双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
 * end()	            返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
 * rbegin()	        返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
 * rend()	            返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
 * cbegin()	        和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
 * cend()	            和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
 * crbegin()	        和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
 * crend()	            和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的元素值。
 * find(val)	        在 set 容器中查找值为 val 的元素，如果成功找到，则返回指向该元素的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
 * lower_bound(val)	返回一个指向当前 set 容器中第一个大于或等于 val 的元素的双向迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
 * upper_bound(val)	返回一个指向当前 set 容器中第一个大于 val 的元素的迭代器。如果 set 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
 * equal_range(val)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的值为 val 的元素（set 容器中各个元素是唯一的，因此该范围最多包含一个元素）。
 * empty()	            若容器为空，则返回 true；否则 false。
 * size()	            返回当前 set 容器中存有元素的个数。
 * max_size()	        返回 set 容器所能容纳元素的最大个数，不同的操作系统，其返回值亦不相同。
 * insert()        	向 set 容器中插入元素。
 * erase()	            删除 set 容器中存储的元素。
 * swap()	            交换 2 个 set 容器中存储的所有元素。这意味着，操作的 2 个 set 容器的类型必须相同。
 * clear()	            清空 set 容器中所有的元素，即令 set 容器的 size() 为 0。
 * emplace()	        在当前 set 容器中的指定位置直接构造新元素。其效果和 insert() 一样，但效率更高。
 * emplace_hint()	    在本质上和 emplace() 在 set 容器中构造新元素的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示新元素生成位置的迭代器，并作为该方法的第一个参数。
 * count(val)	        在当前 set 容器中，查找值为 val 的元素的个数，并返回。注意，由于 set 容器中各元素的值是唯一的，因此该函数的返回值最大为 1。
*/
class test_stl_set {
public:
    void test_stl_set_init()
    {
        set<int> testSet;
        testSet.insert(3);
        auto iter = testSet.insert(3);
        if (iter.second == false) {
            cout << "insert failed" << endl;
        }

    }
};

#endif /*_TEST_STL_SET_H_*/
