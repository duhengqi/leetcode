#ifndef _LEETCODE_NUMS_217_CONTAINSDUPLICATE_H
#define _LEETCODE_NUMS_217_CONTAINSDUPLICATE_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 * 给你一个整数数组 nums 。如果任一值在数组中出现 至少两次 ，返回 true ；如果数组中每个元素互不相同，返回 false 。
 * 示例 1：
 * 输入：nums = [1,2,3,1]  输出：true
 * 示例 2：
 * 输入：nums = [1,2,3,4]  输出：false
 * 示例 3：
 * 输入：nums = [1,1,1,3,3,4,3,2,4,2]  输出：true
 * 
 * 提示：
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 */

// @lc code=start
class Solution_217 {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> testSet;

        for (int i = 0; i < nums.size();i++) {
            auto iter = testSet.insert(nums[i]);
            if (iter.second == false) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

TEST(test_problem_217, testcase0)
{
    Solution_217 so;
    vector<int> nums = {1, 2, 3, 4};
    bool result = so.containsDuplicate(nums);
    EXPECT_EQ(result,false);
}

#endif /*_LEETCODE_NUMS_217_CONTAINSDUPLICATE_H*/
