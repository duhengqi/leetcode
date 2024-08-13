#ifndef _LEETCODE_NUMS_169_MAJORITY_ELEMENT_H
#define _LEETCODE_NUMS_169_MAJORITY_ELEMENT_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 * 给定一个大小为 n 的数组 nums ，返回其中的多数元素。多数元素是指在数组中出现次数 大于 ⌊ n/2 ⌋ 的元素。
 * 你可以假设数组是非空的，并且给定的数组总是存在多数元素。
 * 
 * 示例 1：
 * 输入：nums = [3,2,3]   输出：3
 * 
 * 示例 2：
 * 输入：nums = [2,2,1,1,1,2,2]    输出：2
 * 
 * 提示：
 * n == nums.length
 * 1 <= n <= 5 * 10^4
 * -10^9 <= nums[i] <= 10^9
 * 进阶：尝试设计时间复杂度为 O(n)、空间复杂度为 O(1) 的算法解决此问题。
 */

// @lc code=start
class Solution_169 {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> map;
        int max = 0;
        int result;
        int len = nums.size();
        for (int i = 0; i < len; i++) {
            map[nums[i]]++;
            if (map[nums[i]] > max) {
                result = nums[i];
                max = map[nums[i]];
            }
            if (max > len/2) {
                return result;
            }
        }
        return result;
    }
};
// @lc code=end


TEST(test_problem_169, testcase0)
{
    Solution_169 so;
    vector<int> nums = {2, 2, 1};
    EXPECT_EQ(so.majorityElement(nums), 2);
}

TEST(test_problem_169, testcase1)
{
    Solution_169 so;
    vector<int> nums = {2, 2, 3, 3, 2};
    EXPECT_EQ(so.majorityElement(nums), 2);
}

#endif /*_LEETCODE_NUMS_169_MAJORITY_ELEMENT_H*/
