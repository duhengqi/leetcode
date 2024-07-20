#ifndef _TEST_SELECTION_SORT_H_
#define _TEST_SELECTION_SORT_H_

#include <iostream>
#include <vector>
#include "gtest.h"
#include <algorithm>
using namespace std;

/**
 * https://www.geeksforgeeks.org/selection-sort-algorithm-2/
 * https://www.geeksforgeeks.org/stable-selection-sort/
 */

/**
 * 选择排序，从小到大
 * 找到未排序数组中的最小值，然后放到已排序的末尾

 * 选择排序的稳定性： 选择排序是一种不稳定的排序方法。
    Example: 4A 5 3 2 4B 1 : 第一次交换将1和4a交换，4a到了4b的后面
* 将选择排序变成稳定排序：4A 5 3 2 4B 1  ->  1 4A 5 3 2 4B, 即前面节点依次与1交换

 * 空间复杂度：选择排序是一种就地排序算法，不需要额外空间，空间复杂度为O（1）；
 * 时间复杂度：在最坏和平均情况下，选择排序的时间复杂度为 O（n^2）
*/
class test_selection_sort {
public:
    void selection_sort(vector<int>& nums)
    {
    for (int i = 0; i < nums.size() - 1;i++) {
            int smallest = nums[i];
            int min_index = i;
            for (int j = i+1; j < nums.size();j++) {
                if (nums[j] < nums[min_index]) {
                    min_index = j;
                }
            }
            if (min_index != i) {
                swap(nums[i], nums[min_index]);
            }
        }
    }
};


TEST(test_sort_selection_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9};
    vector<int> nums = {7,6,9,3,1,5,2,4,10};
    test_selection_sort so;
    
    so.selection_sort(nums);
    EXPECT_EQ(is_sorted(nums.begin(),nums.end()),true);
}

#endif /* _TEST_SELECTION_SORT_H_ */
