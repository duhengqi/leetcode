#ifndef _LEETCODE_NUMS_128_LONGEST_CONSECUTIVE_H_
#define _LEETCODE_NUMS_128_LONGEST_CONSECUTIVE_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 * 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
 * 请你设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 
 * 示例 1：
 * 输入：nums = [100,4,200,1,3,2]
 * 输出：4
 * 解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
 * 
 * 示例 2：
 * 输入：nums = [0,3,7,2,5,8,4,6,0,1]
 * 输出：9
 * 
 * 提示：
 * 0 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 */

// @lc code=start
class Solution_128 {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        unordered_map<int,int> uMap;
        int result = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (uMap.find(nums[i]) != uMap.end()) {
                continue;
            }
            uMap[nums[i]] = nums[i];
            auto iterF = uMap.find(nums[i] - 1);
            auto iterB = uMap.find(nums[i] + 1);
            if (iterF != uMap.end() && iterB != uMap.end()) {
                int min = uMap[nums[i] - 1];
                int max = uMap[nums[i] + 1];
                uMap[uMap[nums[i]-1]] = uMap[nums[i]+1];
                uMap[uMap[nums[i] + 1]] = min;
                result = (result > ( max-min + 1)) ? result : ( max-min + 1);
            } else if (iterF != uMap.end()) {
                int min = uMap[nums[i] - 1];
                uMap[nums[i]] = uMap[nums[i] - 1];
                uMap[uMap[nums[i]]] = nums[i];
                result = (result > (nums[i]-min+1)) ? result : (nums[i]-min+1);
            } else if (iterB != uMap.end()) {
                int max = uMap[nums[i] + 1];
                uMap[nums[i]] = uMap[nums[i]+1];
                uMap[uMap[nums[i] + 1]] = nums[i];
                result = (result > (max - nums[i]+1)) ? result : (max - nums[i]+1);
            }
        }

        return result;
    }
};
// @lc code=end

TEST(test_problem_128, testcase2)
{
    Solution_128 so;
    vector<int> nums = {1, 0, -1};
    int result = so.longestConsecutive(nums);
    EXPECT_EQ(result, 3);
}

TEST(test_problem_128, testcase1)
{
    Solution_128 so;
    vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    int result = so.longestConsecutive(nums);
    EXPECT_EQ(result, 9);;
}

TEST(test_problem_128, testcase0)
{
    Solution_128 so;
    vector<int> nums = {100,4,200,1,3,2};
    int result = so.longestConsecutive(nums);
    EXPECT_EQ(result, 4);;
}


#endif /*_LEETCODE_NUMS_128_LONGEST_CONSECUTIVE_H_*/
