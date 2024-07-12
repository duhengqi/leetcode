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

/* 创建一个会返回临时 multimap 对象的函数 */
    multimap<string, string> dismultimap() {
        multimap<string, string>tempmultimap{ {"keyA", "valueA"},{"keyB", "valueC"} };
        return tempmultimap;
    }

void test_stl_multimap()
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