#ifndef _LEETCODE_NUMS_1480_RUNNING_SUM_H_
#define _LEETCODE_NUMS_1480_RUNNING_SUM_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=1480 lang=cpp
 *
 * [1480] 一维数组的动态和
 */

// @lc code=start
class Solution_1480 {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int>runningSum(nums.size());
        runningSum[0] = nums[0];
        for (int i =1;i < nums.size();i++) {
            runningSum[i] = runningSum[i-1] + nums[i];
        }
        return runningSum;
    }
};
// @lc code=end


#endif /*_LEETCODE_NUMS_1480_RUNNING_SUM_H_*/
