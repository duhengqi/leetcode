#ifndef _TEST_QUICK_SORT_H_
#define _TEST_QUICK_SORT_H_

#include <algorithm>
#include <iostream>
#include <vector>

#include "gtest.h"
using namespace std;

/**
 * https://www.geeksforgeeks.org/quick-sort-algorithm/
 * https://www.hello-algo.com/chapter_sorting/quick_sort/
 
 * leetcode 912 排序数组
 * https://leetcode.cn/problems/sort-an-array/description/
 */

/**
 * 快速排序，从小到大
 * 快速排序（quick sort）是一种基于分治策略的排序算法
 * 选择数组中的某个元素作为“基准数”，将所有小于基准数的元素移到其左侧，
 * 而大于基准数的元素移到其右侧。
 * 快速排序的复杂性分析：
 * 时间复杂度：
 * 问题：下面代码为什么先遍历j，能否先遍历i?
 */
// code=start
class test_quick_sort {
public:
    /* 元素交换 */
    void swap(vector<int> &nums, int i, int j)
    {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    /* 哨兵划分 */
    int partition(vector<int> &nums, int left, int right)
    {
        // 以 nums[left] 为基准数
        int i = left, j = right;
        while (i < j) {
            while (i < j && nums[j] >= nums[left]) {
                j--; // 从右向左找首个小于基准数的元素
            }
            while (i < j && nums[i] <= nums[left]) {
                i++; // 从左向右找首个大于基准数的元素
            }
            swap(nums, i, j); // 交换这两个元素
        }
        swap(nums, i, left); // 将基准数交换至两子数组的分界线
        return i;            // 返回基准数的索引
    }

    /* 快速排序 */
    void quick_sort_recursive(vector<int> &nums, int left, int right)
    {
        // 子数组长度为 1 时终止递归
        if (left >= right) {
            return;
        }
        // 哨兵划分
        int pivot = partition(nums, left, right);
        // 递归左子数组、右子数组
        if (!is_sorted(nums.begin()+left,nums.begin()+pivot)) {
            quick_sort_recursive(nums, left, pivot - 1);
        }
        if (!is_sorted(nums.begin()+pivot + 1,nums.begin()+right+1)) {
            quick_sort_recursive(nums, pivot + 1, right);
        }
    }
};

// code=end

// testcase=start

TEST(test_sort_quick_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9,10};
    vector<int> nums = {7, 6, 9, 3, 1, 5, 2, 4, 10};
    test_quick_sort so;
    so.quick_sort_recursive(nums, 0, nums.size() - 1);

    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

TEST(test_sort_quick_sort, testcase1)
{
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 9, 10};
    test_quick_sort so;
    so.quick_sort_recursive(nums, 0, nums.size() - 1);
    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

TEST(test_sort_quick_sort, testcase2)
{
    vector<int> nums = {1};
    test_quick_sort so;
    so.quick_sort_recursive(nums, 0, nums.size() - 1);
    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

TEST(test_sort_quick_sort, testcase3)
{
    vector<int> nums = {2, 1};
    test_quick_sort so;
    so.quick_sort_recursive(nums, 0, nums.size() - 1);

    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

TEST(test_sort_quick_sort, testcase4)
{
    vector<int> nums = {5, 4, 3, 2, 1, 1, 2, 3, 4, 5};
    test_quick_sort so;
    so.quick_sort_recursive(nums, 0, nums.size() - 1);
    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

TEST(test_sort_quick_sort, testcase5)
{
    vector<int> nums = {2,4,6,5,1,7};
    test_quick_sort so;
    so.quick_sort_recursive(nums, 0, nums.size() - 1);
    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

// testcase=end
#endif /* _TEST_quick_sort_H_ */
