#ifndef _TEST_RADIX_SORT_H_
#define _TEST_RADIX_SORT_H_

#include <algorithm>
#include <iostream>
#include <vector>

#include "gtest.h"
using namespace std;

/**
 * https://www.hello-algo.com/chapter_sorting/radix_sort/
 */

/**
 * 假设我们需要对 n=10^6 个学号进行排序，而学号是一个 8位数字，这意味着数据范围非常大，
 * 使用计数排序需要分配大量内存空间，而基数排序可以避免这种情况。 
 * 基数排序（radix sort）的核心思想与计数排序一致，也通过统计个数来实现排序。
 * 在此基础上，基数排序利用数字各位之间的递进关系，依次对每一位进行排序，从而得到最终的排序结果。
 * 以学号数据为例，假设数字的最低位是第 1 位，最高位是第 8 位
 * 初始化位数 k=1, 对学号的第 k 位执行“计数排序”。完成后，数据会根据第 k 位从小到大排序。
 * 将 k 增加 1 ，然后返回步骤 2. 继续迭代，直到所有位都排序完成后结束。
 */

class test_radix_sort {
public:
    /* 获取元素 num 的第 k 位，其中 exp = 10^(k-1) */
    int digit(int num, int exp)
    {
        // 传入 exp 而非 k 可以避免在此重复执行昂贵的次方计算
        return (num / exp) % 10;
    }

    /* 计数排序（根据 nums 第 k 位排序） */
    void countingSortDigit(vector<int> &nums, int exp)
    {
        // 十进制的位范围为 0~9 ，因此需要长度为 10 的桶数组
        vector<int> counter(10, 0);
        int n = nums.size();
        // 统计 0~9 各数字的出现次数
        for (int i = 0; i < n; i++) {
            int d = digit(nums[i], exp); // 获取 nums[i] 第 k 位，记为 d
            counter[d]++;                // 统计数字 d 的出现次数
        }
        // 求前缀和，将“出现个数”转换为“数组索引”
        for (int i = 1; i < 10; i++) {
            counter[i] += counter[i - 1];
        }
        // 倒序遍历，根据桶内统计结果，将各元素填入 res
        vector<int> res(n, 0);
        for (int i = n - 1; i >= 0; i--) {
            int d = digit(nums[i], exp);
            int j = counter[d] - 1; // 获取 d 在数组中的索引 j
            res[j] = nums[i];       // 将当前元素填入索引 j
            counter[d]--;           // 将 d 的数量减 1
        }
        // 使用结果覆盖原数组 nums
        for (int i = 0; i < n; i++) {
            nums[i] = res[i];
        }
    }

    /* 基数排序 */
    void radix_sort(vector<int> &nums)
    {
        // 获取数组的最大元素，用于判断最大位数
        int m = *max_element(nums.begin(), nums.end());
        // 按照从低位到高位的顺序遍历
        for (int exp = 1; exp <= m; exp *= 10) {
            // 对数组元素的第 k 位执行计数排序
            // k = 1 -> exp = 1
            // k = 2 -> exp = 10
            // 即 exp = 10^(k-1)
            countingSortDigit(nums, exp);
        }
    }
};

TEST(test_sort_radix_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9};
    vector<int> nums = {7, 6, 9, 3, 1, 5, 2, 4, 10};
    test_radix_sort so;
    so.radix_sort(nums);
    // for (int i = 0; i < nums.size();i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

#endif /* _TEST_RADIX_SORT_H_ */
