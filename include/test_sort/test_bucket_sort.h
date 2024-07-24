#ifndef _TEST_BUCKET_SORT_H_
#define _TEST_BUCKET_SORT_H_

#include <algorithm>
#include <iostream>
#include <vector>

#include "gtest.h"
using namespace std;

/**
 * https://www.hello-algo.com/chapter_sorting/bucket_sort/
 */

/**
 * 桶排序（bucket sort）是分治策略的一个典型应用。
 * 它通过设置一些具有大小顺序的桶，每个桶对应一个数据范围，将数据平均分配到各个桶中；
 * 然后，在每个桶内部分别执行排序；最终按照桶的顺序将所有数据合并。
 * 算法流程：
 * 1, 考虑一个长度为 n 的数组，其元素是范围 [0-1) 内的浮点数。
 * 2, 初始化 k 个桶，将 n 个元素分配到 k 个桶中。
 * 3, 对每个桶分别执行排序（这里采用编程语言的内置排序函数）。
 * 按照桶从小到大的顺序合并结果。
 * leetcode 例题：347 220
 */

class test_bucket_sort {
public:
    /* 桶排序 */
    void bucket_sort(vector<float> &nums)
    {
        // 初始化 k = n/2 个桶，预期向每个桶分配 2 个元素
        int k = nums.size() / 2;
        vector<vector<float>> buckets(k);
        // 1. 将数组元素分配到各个桶中
        for (float num : nums) {
            // 输入数据范围为 [0, 1)，使用 num * k 映射到索引范围 [0, k-1]
            int i = num * k;
            // 将 num 添加进桶 bucket_idx
            buckets[i].push_back(num);
        }
        // 2. 对各个桶执行排序
        for (vector<float> &bucket : buckets) {
            // 使用内置排序函数，也可以替换成其他排序算法
            sort(bucket.begin(), bucket.end());
        }
        // 3. 遍历桶合并结果
        int i = 0;
        for (vector<float> &bucket : buckets) {
            for (float num : bucket) {
                nums[i++] = num;
            }
        }
    }
};

TEST(test_sort_bucket_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9};
    vector<int> nums = {7, 6, 9, 3, 1, 5, 2, 4, 10};
    test_bucket_sort so;
    // so.bucket_sort(nums);
    // for (int i = 0; i < nums.size();i++) {
    //     cout << nums[i] << " ";
    // }
    // cout << endl;
    EXPECT_EQ(is_sorted(nums.begin(), nums.end()), true);
}

#endif /* _TEST_BUCKET_SORT_H_ */
