#include "god.h"
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }
        
    }
};
// @lc code=end



TEST(test_problem_724, testcase0)
{
    Solution so;
    vector<int> nums = {1,3,4,2,2};
    EXPECT_EQ(so.findDuplicate(nums), 2);
}