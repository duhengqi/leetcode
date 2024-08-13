#ifndef _LEETCODE_NUMS_238_PRODUCT_EXCEPT_SELF_H
#define _LEETCODE_NUMS_238_PRODUCT_EXCEPT_SELF_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 * 给你一个整数数组 nums，返回 数组 answer ，其中 answer[i] 等于 nums 中除 nums[i] 之外其余各元素的乘积 。
 * 题目数据 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内。
 * 请不要使用除法，且在 O(n) 时间复杂度内完成此题。
 * 示例 1:
 * 输入: nums = [1,2,3,4]    输出: [24,12,8,6]
 * 
 * 示例 2:
 * 输入: nums = [-1,1,0,-3,3]  输出: [0,0,9,0,0]
 *  
 * 提示：
 * 2 <= nums.length <= 10^5
 * -30 <= nums[i] <= 30
 * 保证 数组 nums之中任意元素的全部前缀元素和后缀的乘积都在  32 位 整数范围内
 * 进阶：你可以在 O(1) 的额外空间复杂度内完成这个题目吗？（出于对空间复杂度分析的目的，输出数组 不被视为 额外空间。）
 */

// @lc code=start
class Solution_238 {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(nums.size());
        result[len - 1] = 1;
        result[len - 2] = nums[len - 1];
        for (int i = len - 3; i >= 0; i --) {
            result[i] = result[i + 1] * nums[i+1];
        }
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << " ";
        }
        cout << endl;
        int preSum = nums[0];
        for (int i = 1; i < len; i++) {
            result[i] *= preSum;
            preSum *= nums[i];
        }

        return result;
    }
};
// @lc code=end

TEST(test_problem_238, testcase0)
{
    Solution_238 so;
    vector<int> nums = {1,2,3,4};
    vector<int> exceptResult = {24,12,8,6};
    vector<int> result = so.productExceptSelf(nums);
    EXPECT_EQ(is_vector_equal(result, exceptResult), true);
}

#endif /*_LEETCODE_NUMS_238_PRODUCT_EXCEPT_SELF_H*/
