#include <iostream>
#include <string>
#include <map>

using namespace std;
/**
 * 
 * template < class Key,                                     // 指定键（key）的类型
 *            class T,                                       // 指定值（value）的类型
 *            class Compare = less<Key>,                     // 指定排序规则
 *            class Alloc = allocator<pair<const Key,T> >    // 指定分配器对象的类型
 *            > class map;
 */

map<string,int> disMap()
{
    map<string, int>tempMap{ {"key1",10},{"key2",20} };
    return tempMap;
}

void test_stl_map()
{
    /* 空map容器 */
    map<string, int> myMap_empty;
    
    /* myMap 容器在初始状态下，就包含有 2 个键值对。 */
    map<string, int>myMap0 { {"key1",10},{"key2",20} };
    
    /* map容器中存储的键值对，其本质都是 pair类模板创建的 pair 对象。与上面等价：*/
    map<string, int>myMap1{make_pair("key1",10),make_pair("key2",20)};
    
    /* 拷贝（复制）构造函数，myMap 完全一样的 newMap 容器。 */
    map<string, int> newMap(myMap1);
    
    /* 临时的 map 对象作为参数，传递给要初始化的 map 容器时，调用移动构造函数。举个例子：*/

    map<string, int>newMap0(disMap());
    
    /* map 类模板还支持取已建 map 容器中指定区域内的键值对，创建并初始化新的 map 容器。例如：
     *     这里，通过调用 map 容器的双向迭代器，实现了在创建 newMap 容器的同时，将其初始化为包含一个 {"key2",20} 键值对的容器。
     */
    map<string, int>myMap2{ {"key1",10},{"key2",20} };
    map<string, int>newMap2(++myMap2.begin(), myMap2.end());

    map<string, string> testMap;
    testMap.emplace("key1","value1");
    testMap.emplace("key2","value2");
    testMap.emplace("key3","value3");
    testMap.emplace("key4","value4");
    testMap.emplace("key5","value5");
    if (!testMap.empty()) {
        for (auto iter = testMap.begin(); iter != testMap.end(); ++iter) {
            cout << iter->first << " " << iter->second << endl;
        }
    }
    map<string, string>::iterator iter0 = testMap.find("key2");
    cout << iter0->first << " " << iter0->second << endl;

    /* 返回map 容器中第一个大于或等于key的键值对的双向迭代器。以下输出：key2 value2 */
    map<string, string>::iterator iter1 = testMap.lower_bound("key2");
    cout << "lower_bound: " << iter1->first << " " << iter1->second << endl;
    
    /* 返回map 容器中第一个大于key的键值对的迭代器。以下输出：key3 value3 */
    map<string, string>::iterator iter2 = testMap.upper_bound("key2");
    cout << "upper_bound: "<< iter2->first << " " << iter2->second << endl;

    /* 返回一个 pair 对象，其中 pair.first = lower_bound() pair.second = upper_bound() 方法的返回值等价。以下输出：key2 value2 */
    pair <map<string, string>::iterator, map<string, string>::iterator> testPair = testMap.equal_range("key2");
    for (auto iter = testPair.first; iter != testPair.second; ++iter) {
        cout <<"equal_range: "<< iter->first << " " << iter->second << endl;
    }
}

void test_stl_map_access()
{
    map<string, string> testMap;
    testMap.emplace("key1","value1");
    string cValue1 = testMap["key2"];
    /**当前 map 容器中没有包含该指定键的键值对, [] 向该 map 容器中增添一个键值对。
     * 键对应的值取决于 map 容器规定键值对中值的数据类型，使用该类型的默认值作为键值对的值 */
    for (auto iter = testMap.begin(); iter != testMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    /*at() 成员方法 如果在当前容器中查找失败，该方法不会向容器中添加新的键值对，而是直接抛出 out_of_range 异常*/
    cout << testMap.at("key1") << endl;
    //下面一行代码会引发 out_of_range 异常  */
    try
    {
        testMap.at("test");
    } catch(out_of_range) {
        cout << "no test value" << endl;
    }
}

void test_stl_map_insert()
{
    /** 
     * 1) 无需指定插入位置，直接将键值对添加到 map 容器中
     * insert() 方法的语法格式有以下 2 种,此处语法与 emplace()相同
     * 1、引用传递一个键值对   pair<iterator,bool> insert (const value_type& val);
     * 2、以右值引用的方式传递键值对
     * template <class P>
     *     pair<iterator,bool> insert (P&& val);
     * 其中，val 参数表示键值对变量，同时该
     * 方法会返回一个 pair 对象，其中 pair.first 表示一个迭代器，pair.second 为一个 bool 类型变量：
     * 如果成功插入 val，则该迭代器指向新插入的 val，bool 值为 true；
     * 如果插入 val 失败，则表明当前 map 容器中存有和 val 的键相同的键值对（用 p 表示），此时返回的迭代器指向 p，bool 值为 false。
     * 以上 2 种语法格式的区别在于传递参数的方式不同，即无论是局部定义的键值对变量还是全局定义的键值对变量，都采用普通引用传递的方式
     * 而对于临时的键值对变量，则以右值引用的方式传参。*/


    map<string, string> testMap;
    pair<map<string, string>::iterator, bool> ret;

    pair<string, string> value0 = { "key1","value1" };
    // ret = testMap.insert(value0);
    ret = testMap.emplace(value0);
    /* value0 并不是临时变量(是局部变量)，因此会以第一种方式传参 */
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;

    /* 以右值引用的方式传递临时的键值对变量 */
    // ret = testMap.insert({ "key2","value2" });
    ret = testMap.emplace("key2","value2");
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    /* 插入失败 返回map中相同key的迭代器 */
    // ret = testMap.insert({ "key1","value3"});
    ret = testMap.emplace("key1","value3");
    cout << "ret.iter = <{" << ret.first->first << ", " << ret.first->second << "}, " << ret.second << ">" << endl;
    
    /** 2) insert() 方法还支持向 map 容器的指定位置插入新键值对，此处语法与 emplace()相同
     * 以普通引用的方式传递 val 参数 iterator insert (const_iterator position, const value_type& val);
     * 以右值引用的方式传递 val 键值对参数
     * template <class P>
     *     iterator insert (const_iterator position, P&& val);
     * 其中 val 为要插入的键值对变量。注意，和第 1 种方式的语法格式不同，这里 insert() 方法返回的是迭代器，而不再是 pair 对象：
     * 如果插入成功，insert() 方法会返回一个指向 map 容器中已插入键值对的迭代器；
     * 如果插入失败，insert() 方法同样会返回一个迭代器，该迭代器指向 map 容器中和 val 具有相同键的那个键值对。
     * 即便指定了新键值对的插入位置，map 容器仍会对存储的键值对进行排序。
    */
    map<string, string>::iterator it = testMap.begin();
    pair<string, string> value3 = { "key3","value3" };
    /* 向 it 位置以普通引用的方式插入 STL */
    // auto iter1 = testMap.insert(it, value3);
    auto iter1 = testMap.emplace_hint(it, value3);
    cout << iter1->first << " " << iter1->second << endl;
    /* 向 it 位置以右值引用的方式插入临时键值对 */
    // auto iter2 = testMap.insert(it, pair<string, string>("key4", "value4"));
    auto iter2 = testMap.emplace_hint(it, pair<string, string>("key4", "value4"));
    cout << iter2->first << " " << iter2->second << endl;
    /* 插入失败样例，返回map中相同key的迭代器 */
    // auto iter3 = testMap.insert(it, pair<string, string>("key4", "value5"));
    auto iter3 = testMap.emplace_hint(it, pair<string, string>("key4", "value5"));
    cout << iter3->first << " " << iter3->second << endl;

    /**
     * 3) insert() 方法还支持向当前 map 容器中插入其它 map 容器指定区域内的所有键值对
     * template <class InputIterator>
     * void insert (InputIterator first, InputIterator last);
     * 其中first和last都是迭代器，它们的组合<first,last>可以表示某 map 容器中的指定区域。
    */
    map<string, string>copymap;
    /* 此处<first,last> 是从容器第 2 个键值对开始的所有的键值插入到 copymap 中  */
    map<string, string>::iterator first = ++testMap.begin();
    map<string, string>::iterator last = testMap.end();
    copymap.insert(first, last);
    for (auto iter = copymap.begin(); iter != copymap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
    /**
     * 4) insert() 方法允许一次向 map 容器中插入多个键值对，其语法格式为：
     * void insert ({val1, val2, ...});
     * 其中，vali 都表示的是键值对变量。
    */
    map<string, string> testmap2;
    testmap2.insert({ {"keyA", "valueA"},
                   {"keyB", "valueB"},
                   {"keyC", "valueC"}, });
    for (auto iter = testmap2.begin(); iter != testmap2.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }
}


void test_stl_map_sort()
{
    /*默认情况下，map 容器调用 less<T> 规则，对所有键值对做升序排序。
     * 因此，如下 2 行创建 map 容器的方式，其实是等价的,其内部键值对排列的顺序为
     * <"key1", 10>
     * <"key2", 20>
    */
    map<string, int>myMap3{ {"key1",10},{"key2",20} };
    map<string, int, less<string> >myMap4{ {"key1",10},{"key2",20} };

    /* 此时，myMap 容器内部键值对排列的顺序为
     * <"key2", 20>
     * <"key1", 10>
    */
    map<string, int, greater<string> >myMap5{ {"key1",10},{"key2",20} };

}