#ifndef _TEST_STL_MULTIMAP_H_
#define _TEST_STL_MULTIMAP_H_

#include <iostream>
#include <string>
#include <map>

using namespace std;
/**
 * template < class Key,                                   // 指定键（key）的类型
 *         class T,                                     // 指定值（value）的类型
 *         class Compare = less<Key>,                   // 指定排序规则
 *         class Alloc = allocator<pair<const Key,T> >  // 指定分配器对象的类型
 *         > class multimap;
*/
/*
成员方法	功能
begin()	返回指向容器中第一个（注意，是已排好序的第一个）键值对的双向迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
end()	返回指向容器最后一个元素（注意，是已排好序的最后一个）所在位置后一个位置的双向迭代器，通常和 begin() 结合使用。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
rbegin()	返回指向最后一个（注意，是已排好序的最后一个）元素的反向双向迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
rend()	返回指向第一个（注意，是已排好序的第一个）元素所在位置前一个位置的反向双向迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的反向双向迭代器。
cbegin()	和 begin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
cend()	和 end() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crbegin()	和 rbegin() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
crend()	和 rend() 功能相同，只不过在其基础上，增加了 const 属性，不能用于修改容器内存储的键值对。
find(key)	在 multimap 容器中查找首个键为 key 的键值对，如果成功找到，则返回指向该键值对的双向迭代器；反之，则返回和 end() 方法一样的迭代器。另外，如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
lower_bound(key)	返回一个指向当前 multimap 容器中第一个大于或等于 key 的键值对的双向迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
upper_bound(key)	返回一个指向当前 multimap 容器中第一个大于 key 的键值对的迭代器。如果 multimap 容器用 const 限定，则该方法返回的是 const 类型的双向迭代器。
equal_range(key)	该方法返回一个 pair 对象（包含 2 个双向迭代器），其中 pair.first 和 lower_bound() 方法的返回值等价，pair.second 和 upper_bound() 方法的返回值等价。也就是说，该方法将返回一个范围，该范围中包含的键为 key 的键值对。
empty() 	若容器为空，则返回 true；否则 false。
size()	返回当前 multimap 容器中存有键值对的个数。
max_size()	返回 multimap 容器所能容纳键值对的最大个数，不同的操作系统，其返回值亦不相同。
insert()	向 multimap 容器中插入键值对。
erase()	删除 multimap 容器指定位置、指定键（key）值或者指定区域内的键值对。
swap()	交换 2 个 multimap 容器中存储的键值对，这意味着，操作的 2 个键值对的类型必须相同。
clear()	清空 multimap 容器中所有的键值对，使 multimap 容器的 size() 为 0。
emplace()	在当前 multimap 容器中的指定位置处构造新键值对。其效果和插入键值对一样，但效率更高。
emplace_hint()	在本质上和 emplace() 在 multimap 容器中构造新键值对的方式是一样的，不同之处在于，使用者必须为该方法提供一个指示键值对生成位置的迭代器，并作为该方法的第一个参数。
count(key)	在当前 multimap 容器中，查找键为 key 的键值对的个数并返回。

*/
class test_stl_multimap {
public:
    /* 创建一个会返回临时 multimap 对象的函数 */
    multimap<string, string> dismultimap() {
        multimap<string, string>tempmultimap{ {"keyA", "valueA"},{"keyB", "valueC"} };
        return tempmultimap;
    }

    void test_stl_multimap_init()
    {
        multimap<string, string>mymultimap0{ { {"keyA", "valueA"}, {"keyB", "valueB"},  {"keyC", "valueC"}, } };

        /* 借助 pair 类模板的构造函数来生成各个pair类型的键值对 */
        multimap<string, string>mymultimap1{
            pair<string,string>{"keyA", "valueA"},
            pair<string,string>{"keyB", "valueB"},
            pair<string,string>{"keyC", "valueC"}
        };

        /* mymultimap1 容器中的最后 2 个键值对，用于初始化 newmultimap 容器 */
        multimap<string, string>newmultimap(++mymultimap1.begin(), mymultimap1.end());

        /* 调用 make_pair() 函数，生成键值对元素 */
        multimap<string, string>mymultimap{
            make_pair("keyA", "valueA"),
            make_pair("keyB", "valueB"),
            make_pair("keyB", "valueB"),
            make_pair("keyC", "valueC")
        };

        //输出 mymultimap 容器中存储键为 'b' 的键值对的数量
        cout << mymultimap.count("keyB") << endl;
        for (auto iter = mymultimap.begin(); iter != mymultimap.end(); ++iter) {
            cout << iter->first << " " << iter->second << endl;
        }

        pair<multimap<string, string>::iterator, multimap<string, string>::iterator> ret = mymultimap.equal_range("keyB");
        for (multimap<string, string>::iterator iter2 = ret.first; iter2 != ret.second;iter2++) {
            cout << iter2->first << " " << iter2->second;
        }
        /* 拷贝（复制）构造函数 和 mymultimap 完全一样的 newmultimap 容器。*/
        multimap<string, string>copymultimap(mymultimap);

        /* 临时的 multimap 容器作为参数初始化新 multimap 容器时，其底层就会调用移动构造函数来实现初始化操作 */
        multimap<string, string>newmultimap2(dismultimap());

    }


    void test_stl_multimap_sort()
    {
        /*默认情况下，multimap 容器调用 less<T> 规则，对所有键值对做升序排序。
        * 因此，如下 2 行创建 multimap容器的方式，其实是等价的,*/
        multimap<string, int>mymultimap1{ {"key1",10},{"key2",20} };
        multimap<string, int, less<string> >mymultimap2{ {"key1",10},{"key2",20} };
        /*此时，其内部键值对排列的顺序为
        * <"key1", 10>
        * <"key2", 20>
        */

        multimap<string, int, greater<string> >mymultimap3{ {"key1",10},{"key2",20} };
        /* 此时，容器内部键值对排列的顺序为
        * <"key2", 20>
        * <"key1", 10>
        */

    }
};

#endif /*_TEST_STL_MULTIMAP_H_*/
