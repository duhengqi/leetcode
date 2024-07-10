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
    //下面一行代码会引发 out_of_range 异常
    try
    {
        testMap.at("test");
    } catch(out_of_range) {
        cout << "no test value" << endl;
    }
}

void test_stl_map_insert()
{
    map<string, string> testMap;
    testMap.emplace("key1","value1");
    string cValue1 = testMap["key1"];
    /**当前 map 容器中没有包含该指定键的键值对, [] 向该 map 容器中增添一个键值对。
     * 键对应的值取决于 map 容器规定键值对中值的数据类型，使用该类型的默认值作为键值对的值 */
    for (auto iter = testMap.begin(); iter != testMap.end(); ++iter) {
        cout << iter->first << " " << iter->second << endl;
    }

    /*at() 成员方法 如果在当前容器中查找失败，该方法不会向容器中添加新的键值对，而是直接抛出 out_of_range 异常*/
    cout << testMap.at("key1") << endl;
    //下面一行代码会引发 out_of_range 异常
    //cout << testMap.at("test") << endl;
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