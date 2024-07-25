#ifndef _LEETCODE_NUMS_220_CONTAINSNEARBYALMOSTDUPLICATE_H
#define _LEETCODE_NUMS_220_CONTAINSNEARBYALMOSTDUPLICATE_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 * 给你一个整数数组 nums 和两个整数 indexDiff 和 valueDiff 。
 * 找出满足下述条件的下标对 (i, j)：
 * i != j,
 * abs(i - j) <= indexDiff
 * abs(nums[i] - nums[j]) <= valueDiff
 * 如果存在，返回 true ；否则，返回 false 。
 * 示例 1：
 * 输入：nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
 * 输出：true
 * 解释：可以找出 (i, j) = (0, 3) 。
 * 满足下述 3 个条件：
 * i != j --> 0 != 3
 * abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
 * abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
 * 示例 2：
 * 输入：nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
 * 输出：false
 * 解释：尝试所有可能的下标对 (i, j) ，均无法满足这 3 个条件，因此返回 false 。
 * 提示：
 * 2 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 1 <= indexDiff <= nums.length
 * 0 <= valueDiff <= 10^9
 */

// @lc code=start
class Solution_220 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        int offset;
        int pivot = -109;
        vector<vector<int>> bucket(219);

        for (int i = 0; i < nums.size();i++) {
            bucket[nums[i] - pivot].push_back(i);
        }
        for (int i = 0; i < nums.size();i++) {
            for (int j = 0; j <= valueDiff;j++) {
                offset = nums[i] - pivot + j;
                for (auto iter = bucket[offset].begin(); iter != bucket[offset].end();iter++) {
                    if (*iter != i && abs(*iter - i) <= indexDiff) {
                        return true;
                    }
                }
                offset = nums[i] - pivot - j;
                for (auto iter = bucket[offset].begin(); iter != bucket[offset].end();iter++) {
                    if (*iter != i && abs(*iter - i) <= indexDiff) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};
// @lc code=end

TEST(test_problem_220, testcase0)
{
    Solution_220 so;
    vector<int> nums={1,2,3,1};
    bool result = so.containsNearbyAlmostDuplicate(nums,3,0);
    EXPECT_EQ(result,true);
}

TEST(test_problem_220, testcase1)
{
    Solution_220 so;
    vector<int> nums={1,5,9,1,5,9};
    bool result = so.containsNearbyAlmostDuplicate(nums,2,3);
    EXPECT_EQ(result,false);
}

#endif /*_LEETCODE_NUMS_220_CONTAINSNEARBYALMOSTDUPLICATE_H*/
