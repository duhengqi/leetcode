#ifndef _TEST_ALGORITHM_MERGE_H_
#define _TEST_ALGORITHM_MERGE_H_

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

/**
 * merge() 函数用于将 2 个有序序列合并为 1 个有序序列，前提是这 2 个有序序列的排序规则相同（要么都是升序，要么都是降序）。  
 * 以默认的升序排序作为排序规则
 * OutputIterator merge (InputIterator1 first1, InputIterator1 last1,
 *                       InputIterator2 first2, InputIterator2 last2,
 *                       OutputIterator result);
 * 以自定义的 comp 规则作为排序规则
 * OutputIterator merge (InputIterator1 first1, InputIterator1 last1,
 *                       InputIterator2 first2, InputIterator2 last2,
 *                       OutputIterator result, Compare comp);
 * first1、last1、first2 以及 last2 都为输入迭代器，[first1, last1) 和 [first2, last2) 各用来指定一个有序序列；
 * result 为输出迭代器，用于为最终生成的新有序序列指定存储位置；comp 用于自定义排序规则。同时，该函数会返回一个输出迭代器，其指向的是新有序序列中最后一个元素之后的位置。
 * 注意，当采用第一种语法格式时，[first1, last1) 和 [first2, last2) 指定区域内的元素必须支持 < 小于运算符；
 * 同样当采用第二种语法格式时，[first1, last1) 和 [first2, last2) 指定区域内的元素必须支持 comp 排序规则内的比较运算符。
 */
class test_algorithm_merge {
public:
    void algorithm_merge()
    {
        int first[] = {5, 10, 15, 20, 25};
        int second[] = {7, 17, 27, 37, 47, 57};

        vector<int> myvector(11);

        // 将 [first,first+5) 和 [second,second+6) 合并为 1 个有序序列，并存储到 myvector 容器中。 */
        merge(first, first + 5, second, second + 6, myvector.begin());

        for (vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it) {
            cout << *it << ' ';
        }
    }

    /**
     * 默认采用升序的排序规则
     * void inplace_merge (BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last);
     * 采用自定义的 comp 排序规则
     * void inplace_merge (BidirectionalIterator first, BidirectionalIterator middle, BidirectionalIterator last, Compare comp);
     * 其中，first、middle 和 last 都为双向迭代器，[first, middle) 和 [middle, last) 各表示一个有序序列。
     * 
     * [first, middle) 和 [middle, last) 指定的这 2 个序列必须遵循相同的排序规则，且当采用第一种语法格式时，这 2 个序列中的元素必须支持 < 小于运算符；
     * 同样，当采用第二种语法格式时，这 2 个序列中的元素必须支持 comp 排序规则内部的比较运算符。
     * 不同之处在于，merge() 函数会将最终合并的有序序列存储在其它数组或容器中，而 inplace_merge() 函数则将最终合并的有序序列存储在 [first, last) 区域中。

     */
    void algorithm_inplace_merge()
    {
        //该数组中存储有 2 个有序序列
        int first[] = { 5,10,15,20,25,7,17,27,37,47,57 };

        //将 [first,first+5) 和 [first+5,first+11) 合并为 1 个有序序列。
        inplace_merge(first, first + 5,first +11);

        for (int i = 0; i < 11; i++) {
            cout << first[i] << " ";
        }
    }
};

#endif /* _TEST_ALGORITHM_MERGE_H_ */
