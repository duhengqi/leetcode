#ifndef _TEST_MERGE_SORT_H_
#define _TEST_MERGE_SORT_H_

#include <iostream>
#include <vector>
#include "gtest.h"
#include <algorithm>
using namespace std;

/**
 * https://www.geeksforgeeks.org/merge-sort/
 */

/**
 * 合并排序，从小到大
 * 

 * 合并排序的稳定性： 合并排序是一种稳定的排序方法。

 * 空间复杂度：合并排序是一种就地排序算法，不需要额外空间，空间复杂度为O（1）；
 * 时间复杂度：合并排序的时间复杂度为 O（n^2）
*/
class test_merge_sort {
public:
    void recursive(vector<int>& nums)
    {

    }
    void merge_sort_recursive(vector<int>& nums)
    {

    }
};

TEST(test_sort_merge_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9};
    vector<int> nums = {7,6,9,3,1,5,2,4,10};
    test_merge_sort so;
    so.merge_sort_recursive(nums);

    // EXPECT_EQ(is_sorted(nums.begin(),nums.end()),true);
}

#endif /* _TEST_MERGE_SORT_H_ */
