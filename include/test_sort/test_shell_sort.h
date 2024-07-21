#ifndef _TEST_shell_sort_H_
#define _TEST_shell_sort_H_

#include <algorithm>
#include <iostream>
#include <vector>

#include "gtest.h"
using namespace std;

/**
 * 希尔排序 是插入排序的优化版本
 * 插入排序在序列基本有序或者小序列情况下比较高效，希尔排序就是先让序列基本有序
 * 步骤：
 * 1，确定初始分组大小，通常是数组长度的一半
 * 2，以分组大小作为步长进行插入排序
 * 3，缩小分组步长进行插入排序，直到缩小到步长为1
 */


class test_shell_sort {
public:
    void insertion_sort_for_shell(vector<int>& nums, int begin, int step)
    {
        for (int i = begin+step; i < nums.size(); i+=step) {
            if (nums[i] >= nums[i - step]) {
                continue;
            }
            for (int j = i; j > begin; j-=step) {
                if (nums[j] < nums[j - step]) {
                    swap(nums[j], nums[j - step]);
                } else {
                    break;
                }
            }
        }
    }
    void shell_sort(vector<int>& nums) {
        int step = nums.size()/2;
        while (step >= 1) {
            for (int i = 0; i < step ;i++) {
                insertion_sort_for_shell(nums, i, step);
            }
            step /= 2;
        }
    }

};

TEST(test_sort_shell_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9};
    vector<int> nums = {7, 6, 9, 3, 1, 5, 2, 4, 10};
    test_shell_sort so;
    so.shell_sort(nums);
    // for (int i = 0; i < nums.size();i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

#endif /* _TEST_shell_sort_H_ */
