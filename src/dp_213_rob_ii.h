#ifndef _LEETCODE_NUMS_213_ROB_II_H_
#define _LEETCODE_NUMS_213_ROB_II_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，
 * 这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，今晚能够偷窃到的最高金额。
 * 
 * 示例 1：
 * 输入：nums = [2,3,2] 输出：3
 * 解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。
 * 
 * 示例 2：
 * 输入：nums = [1,2,3,1] 输出：4
 * 解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 *      偷窃到的最高金额 = 1 + 3 = 4 。
 * 
 * 示例 3：
 * 输入：nums = [1,2,3] 输出：3
 *  
 * 提示：
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 1000
 */

// @lc code=start

class Solution_213 {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1) {
            return nums[0];
        } else if (nums.size() == 2) {
            return nums[1] > nums[0] ? nums[1] : nums[0];
        }
        int res1;
        int res2;
        int len = nums.size();
        {
            int nums0 = nums[0];
            bool flag0 = true;
            int nums1;
            bool flag1;
            int nums2;
            bool flag2;
            if (nums[1] > nums[0]) {
                nums1 = nums1;
                flag1 = false;
            } else {
                nums1 = nums[0];
                flag1 = true;
            }
            for (int i = 2; i < nums.size()-1;i++) {
                if (nums[i] + nums0 > nums1) {
                    nums2 = nums[i] + nums0;
                    flag2 = flag0;
                } else {
                    nums2 = nums1;
                    flag2 = flag1;
                }
                nums0 = nums1;
                flag0 = flag1;
                nums1 = nums2;
                flag1 = flag2;
            }
            if (flag0) {
                res1 = (nums1 > nums0 ? nums1 : nums0);
            } else {
                res1 = (nums0 + nums[len - 1] > nums1 ? nums0 + nums[len - 1] : nums1);
            }
        } 
        {
           int nums0 = nums[len-1];
            bool flag0 = true;
            int nums1;
            bool flag1;
            int nums2;
            bool flag2;
            if (nums[len-2] > nums0) {
                nums1 = nums[len-2];
                flag1 = false;
            } else {
                nums1 = nums0;
                flag1 = true;
            }
            for (int i = len-3; i > 0;i--) {
                if (nums[i] + nums0 > nums1) {
                    nums2 = nums[i] + nums0;
                    flag2 = flag0;
                } else {
                    nums2 = nums1;
                    flag2 = flag1;
                }
                nums0 = nums1;
                flag0 = flag1;
                nums1 = nums2;
                flag1 = flag2;
            }
            if (flag0) {
                res2 = (nums1 > nums0 ? nums1 : nums0);
            } else {
                res2 = (nums0 + nums[0] > nums1 ? nums0 + nums[0] : nums1);
            }            
        }

        return res1>res2?res1:res2;
    }
};

// @lc code=end

#endif /*_LEETCODE_NUMS_213_ROB_II_H_*/
