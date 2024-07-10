#include <iostream>
#include <string>
#include <array>

using namespace std;

/**
 * 序列容器	主要包括 vector 、list 以及 deque 双端队列容器。容器不是排序的。将元素插入容器时，指定在什么位置，元素就会位于什么位置。
 * 排序容器	包括 set、multiset、map以及 multimap 。元素默认是由小到大排序好的，插入元素会插入到适当位置，关联容器在查找时具有非常好的性能。
 * 哈希容器	C++ 11 新加入 4 种关联式容器，分别是 unordered_set、unordered_multiset 、unordered_map 以及 unordered_multimap 哈希多重映射。元素是未排序的，元素的位置由哈希函数确定。
*/
/**
 * array 容器是 C++ 11 标准中新增的序列容器，简单地理解，它就是在 C++ 普通数组的基础上，添加了一些成员函数和全局函数。
 * 在使用上，它比普通数组更安全（at()），且效率并没有因此变差。 
 * 和其它容器不同，array 容器的大小是固定的，无法动态的扩展或收缩，这也就意味着，
 * 在使用该容器的过程无法借由增加或移除元素而改变其大小，它只允许访问或者替换存储的元素。
 * at(i)返回容器中 n 位置处元素的引用，该函数自动检查 n 是否在有效的范围内，如果不是则抛出 out_of_range 异常。
*/

/* *
 * namespace std{template <typename T, size_t N> class array;}
 * 在 array<T,N> 类模板中，T 用于指明容器中的存储的具体数据类型，N 用于指明容器的大小。
 * 需要注意的是，这里的 N 必须是常量，不能用变量表示。
*/

void test_stl_array()
{
    // 初始化
    array<double, 10> values_not_init; // Not initialized 数组内容是不确定值
    array<double, 10> values_zeros {}; // 所有的元素初始化为 0 或者和默认元素类型等效的值：
    array<double, 10> values_init {0.5,1.0,1.5,2.0}; // 只初始化了前 4 个元素，剩余的元素都会被初始化为 0.0

    std::array<int, 4> values{};
    //初始化 values 容器为 {0,1,2,3}
    for (unsigned i = 0; i < values.size(); i++) {
        values.at(i) = i;
    }
    //get() 参数为 常量
    cout << get<3>(values) << endl;

    if (!values.empty()) {
        for (auto val = values.begin(); val < values.end(); val++) {
            cout << *val << " ";
        }
    }
    cout << endl;

    int total = 0;
    for(auto&& value : values) {
        total += value;
    }
    cout << total << endl;
}