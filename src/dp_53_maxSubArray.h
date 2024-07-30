#ifndef _LEETCODE_NUMS_53_MAX_SUB_ARRAY_H_
#define _LEETCODE_NUMS_53_MAX_SUB_ARRAY_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 * 给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 * 子数组 是数组中的一个连续部分。
 * 
 * 示例 1：
 * 输入：nums = [-2,1,-3,4,-1,2,1,-5,4] 输出：6
 * 解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
 * 
 * 示例 2：  输入：nums = [1]  输出：1
 * 
 * 示例 3： 输入：nums = [5,4,-1,7,8]  输出：23
 * 
 * 提示：
 * 1 <= nums.length <= 105
 * -104 <= nums[i] <= 104
 * 进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
 */

// @lc code=start
class Solution_53 {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = nums[0];
        int tmp = nums[0];
        int i;
        for (i = 0; i < nums.size();i++) {
            if(nums[i] >= 0) {
                sum = nums[i];
                tmp = nums[i];
                break;
            }
            if (nums[i] > tmp) {
                tmp = nums[i];
                sum = nums[i];
            }
        }
        if (sum < 0) {
            return sum;
        }
        for (i = i+1; i < nums.size(); i++) {
            if (tmp + nums[i] > 0) {
                tmp += nums[i];
                sum = (tmp > sum ? tmp : sum);
            } else {
                tmp = 0;
            }
        }
        return sum;
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_53_MAX_SUB_ARRAY_H_*/
