#ifndef _TEST_COUNTING_SORT_H_
#define _TEST_COUNTING_SORT_H_

#include <algorithm>
#include <iostream>
#include <vector>

#include "gtest.h"
using namespace std;

/**
 * https://www.hello-algo.com/chapter_sorting/counting_sort/
 */

/**
 * 计数排序：通过统计元素数量来实现排序，通常应用于整数数组。
 * 给定一个长度为 n 的数组 nums ，其中的元素都是“非负整数”
 * 1, 遍历数组，找出其中的最大数字，记为 m, 然后创建一个长度为 m+1 的辅助数组 counter 。
 * 2, 借助 counter 统计 nums 中各数字的出现次数，其中 counter[num] 对应数字 num 的出现次数。
 *    统计方法很简单，只需遍历 nums（设当前数字为 num），每轮将 counter[num] 增加 1 即可。
 * 3, 由于 counter 的各个索引天然有序，接下来，我们遍历 counter，根据各数字出现次数从小到大的顺序填入 nums 即可。
 */

class test_counting_sort {
public:
    /* 计数排序 */
    // 完整实现，可排序对象，并且是稳定排序
    void counting_sort(vector<int> &nums)
    {
        // 1. 统计数组最大元素 m
        int m = 0;
        for (int num : nums) {
            m = max(m, num);
        }
        // 2. 统计各数字的出现次数
        // counter[num] 代表 num 的出现次数
        vector<int> counter(m + 1, 0);
        for (int num : nums) {
            counter[num]++;
        }
        // 3. 求 counter 的前缀和，将“出现次数”转换为“尾索引”
        // 即 counter[num]-1 是 num 在 res 中最后一次出现的索引
        for (int i = 0; i < m; i++) {
            counter[i + 1] += counter[i];
        }
        // 4. 倒序遍历 nums ，将各元素填入结果数组 res
        // 初始化数组 res 用于记录结果
        int n = nums.size();
        vector<int> res(n);
        for (int i = n - 1; i >= 0; i--) {
            int num = nums[i];
            res[counter[num] - 1] = num; // 将 num 放置到对应索引处
            counter[num]--;              // 令前缀和自减 1 ，得到下次放置 num 的索引
        }
        // 使用结果数组 res 覆盖原数组 nums
        nums = res;
    }
};

TEST(test_sort_counting_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9};
    vector<int> nums = {7, 6, 9, 3, 1, 5, 2, 4, 10};
    test_counting_sort so;
    so.counting_sort(nums);
    // for (int i = 0; i < nums.size();i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

#endif /* _TEST_COUNTING_SORT_H_ */
