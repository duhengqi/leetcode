#ifndef _TEST_INSERTION_SORT_H_
#define _TEST_INSERTION_SORT_H_

#include <iostream>
#include <vector>
#include <algorithm>
#include "gtest.h"
using namespace std;


/**
 * 插入排序，从小到大
 * 从数组 i=1，开始遍历，i前已排序
 * 如果 nums[i] >= num[i-1] continue
 * 否则
 * 逻辑1：找到nums[i] 在 0 - (i-1)应该插入的位置 j
 * 将j - (i - 1)的数据向后移动一个位置，然后将nums[i] 放到j的位置

 * 逻辑2：原地排序 nums[i]如果小于num[i-1]，则swap，循环继续

 * 插入排序的稳定性： 插入排序是一种稳定的排序方法。
 * 空间复杂度：用到常数个辅助存储空间，空间复杂度为O（1）；
 * 时间复杂度：
 * 在最好的情况下，每个元素插入之前已经有序，时间复杂度为O(n)；
 * 在最坏的情况下，原序列按照从大到小的次序排列，每次插入要比较i-1次，时间复杂度为O(n²）； 平均时间复杂度为O(n²）。
*/

class test_insertion_sort {
public:
    void insertion_sort_inplace_swap(vector<int>& nums)
    {
        if (nums.size() < 2) {
            return;
        }

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] >= nums[i - 1]) {
                continue;
            }
            for (int j = i; j > 0; j--) {
                if (nums[j] < nums[j - 1]) {
                    swap(nums[j], nums[j - 1]);
                } else {
                    break;
                }
            }
        }
    }

    void insertion_sort_copy(vector<int>& nums)
    {
        if (nums.size() < 2) {
            return;
        }

        for (int i = 1; i < nums.size(); i++) {
            int index = i - 1;
            if (nums[i] >= nums[index]) {
                continue;
            }
            for (int j = 0; j <= index; j++) {
                if (nums[i] < nums[j]) {
                    int tmp = nums[i];
                    for (int k = index; k >= j; k--) {
                        nums[k + 1] = nums[k];
                    }
                    nums[j] = tmp;
                }
            }
        }
    }
};

TEST(test_sort_insertion_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9};
    vector<int> nums = {7, 6, 9, 3, 1, 5, 2, 4, 10};
    test_insertion_sort so;
    so.insertion_sort_inplace_swap(nums);
    // for (int i = 0; i < nums.size();i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

#endif /* _TEST_INSERTION_SORT_H_ */
