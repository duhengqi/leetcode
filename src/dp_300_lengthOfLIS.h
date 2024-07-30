#ifndef _LEETCODE_NUMS_300_LENGTH_OF_LIS_H_
#define _LEETCODE_NUMS_300_LENGTH_OF_LIS_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 * 给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。
 * 子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。
 * 
 * 示例 1：
 * 输入：nums = [10,9,2,5,3,7,101,18]  输出：4
 * 解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
 * 
 * 示例 2：
 * 输入：nums = [0,1,0,3,2,3] 输出：4
 * 
 * 示例 3：
 * 输入：nums = [7,7,7,7,7,7,7]  输出：1
 * 
 * 提示：
 * 1 <= nums.length <= 2500
 * -104 <= nums[i] <= 104
 * 进阶：
 * 你能将算法的时间复杂度降低到 O(n log(n)) 吗?
 */

// @lc code=start

class Solution_300 {
public:
    int lengthOfLIS(vector<int>& nums) {
        int res = 1;
        multimap<int, int> dpMap;
        dpMap.emplace(nums[0], 1);
        for (int i = 1; i<nums.size();i++) {
            auto iter = dpMap.lower_bound(nums[i]);
            if (iter == dpMap.end()) {
                iter--;
                dpMap.emplace(nums[i], res+1);
                res++;
                // res = (iter->second+1 > res?iter->second+1:res);
            } else {
                if (iter == dpMap.begin()) {
                    dpMap.emplace(nums[i], 1);
                } else {
                    int tmp = 1;
                    while (iter != dpMap.begin()) {
                        iter--;
                        if (iter->second>tmp) {
                            tmp = iter->second;
                            if (tmp == res) {
                                break;
                            }
                        }
                    }
                    dpMap.emplace(nums[i], tmp+1);
                    res = (tmp+1 > res?tmp+1:res);
                }
            }
        }
        return res;
    } 
};

// @lc code=end

#endif /*_LEETCODE_NUMS_300_LENGTH_OF_LIS_H_*/
