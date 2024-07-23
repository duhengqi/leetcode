#ifndef _LEETCODE_NUMS_167_TWOSUM_H
#define _LEETCODE_NUMS_167_TWOSUM_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
 * [167] 两数之和 II - 输入有序数组
 */

// @lc code=start
class Solution_167 {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> result;
        while (left < right) {
            if (numbers[left] + numbers[right] > target) {
                right--;
            } else if (numbers[left] + numbers[right] < target) {
                left++;
            } else {
                result.push_back(left + 1);
                result.push_back(right + 1);
                break;
            }
            // cout << left << right << endl;
        }
        return result;
    }
};

TEST(test_problem_167, testcase)
{
    Solution_167 so;

    vector<int> result1;
    vector<int> testData1 = {2,7,11,15};

    result1 = so.twoSum(testData1, 9);
    EXPECT_EQ(result1[0], 1);
    EXPECT_EQ(result1[1], 2);

    vector<int> result2;
    vector<int> testData2 = {2,3,4};
    result2 = so.twoSum(testData2, 6);
    EXPECT_EQ(result2[0], 1);
    EXPECT_EQ(result2[1], 3);
    
    vector<int> result3;
    vector<int> testData3 = {-1,0};
    result3 = so.twoSum(testData3, -1);
    EXPECT_EQ(result3[0], 1);
    EXPECT_EQ(result3[1], 2);
}
// @lc code=end

#endif /*_LEETCODE_NUMS_167_TWOSUM_H*/
