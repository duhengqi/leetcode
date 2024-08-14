#ifndef _LEETCODE_NUMS_179_LARGEST_NUMBER_H_
#define _LEETCODE_NUMS_179_LARGEST_NUMBER_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=179 lang=cpp
 * [179] 最大数
 * 给定一组非负整数 nums，重新排列每个数的顺序（每个数不可拆分）使之组成一个最大的整数。
 * 注意：输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 * 
 * 示例 1：
 * 输入：nums = [10,2]   输出："210"
 * 
 * 示例 2：
 * 输入：nums = [3,30,34,5,9] 输出："9534330"
 *  
 * 提示：
 * 1 <= nums.length <= 100
 * 0 <= nums[i] <= 10^9
 */

// @lc code=start
bool myCompare(int numA, int numB) {
    if (numA == numB) {
        return false;
    }
    string A = to_string(numA)+to_string(numB);
    string B = to_string(numB)+to_string(numA);
    int aLen = A.size();
    for (int i = 0; i < aLen; i++) {
        if (A[i] > B[i]) {
            return true;
        } else if (A[i] < B[i]) {
            return false;
        }
    }
    return true;
}
class Solution_179 {
public:

    string largestNumber(vector<int>& nums) {
        if (nums.size() == 1) {
            return to_string(nums[0]);
        }
        sort(nums.begin(),nums.end(),myCompare);
        string result = to_string(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            result += to_string(nums[i]);
        }
        for (int i = 0; i < result.size();i++) {
            if (result[i] != '0') {
                break;
            }
            if (i != 0 && result[i] == '0') {
                return "0";
            }
        }
        return result;
    }
};
// @lc code=end

TEST(test_problem_179, testcase0)
{
    Solution_179 so;
    vector<int> nums = {10,2,9,39,17};
    string result = so.largestNumber(nums);
    EXPECT_EQ(result, "93921710");
}

#endif /*_LEETCODE_NUMS_179_LARGEST_NUMBER_H_*/
