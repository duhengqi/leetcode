#ifndef _TEST_BUBBLE_SORT_H_
#define _TEST_BUBBLE_SORT_H_

#include <iostream>
#include <vector>
#include "gtest.h"
#include <algorithm>
using namespace std;

/**
 * https://www.geeksforgeeks.org/bubble-sort-algorithm/
 */

/**
 * 冒泡排序，从小到大
 * 从0开始遍历，两两比较，i > i+1 就交换位置，每一次循环会将最大值放到最右边

 * 冒泡排序的稳定性： 冒泡排序是一种稳定的排序方法。

 * 空间复杂度：冒泡排序是一种就地排序算法，不需要额外空间，空间复杂度为O（1）；
 * 时间复杂度：冒泡排序的时间复杂度为 O（n^2）
*/
class test_bubble_sort {
public:
    void bubble_sort(vector<int>& nums)
    {
        bool sorted = true;
        for (int i = 0; i < nums.size(); i++) {
            sorted = true;
            for (int j = 0; j < nums.size()-1-i;j++) {
                if (nums[j] > nums[j+1]) {
                    swap(nums[j], nums[j+1]);
                    sorted = false;
                }
            }
            if(sorted) {
                break;
            }
        }
    }
};

TEST(test_sort_bubble_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9};
    vector<int> nums = {7,6,9,3,1,5,2,4,10};    
    test_bubble_sort so;
    so.bubble_sort(nums);

    EXPECT_EQ(is_sorted(nums.begin(),nums.end()),true);
}

#endif /* _TEST_BUBBLE_SORT_H_ */
