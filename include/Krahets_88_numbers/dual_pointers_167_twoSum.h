#ifndef _LEETCODE_NUMS_167_TWOSUM_H
#define _LEETCODE_NUMS_167_TWOSUM_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=167 lang=cpp
 * https://leetcode.cn/problems/two-sum-ii-input-array-is-sorted/
 * [167] 两数之和 II - 输入有序数组
 * 给你一个下标从 1开始的整数数组 numbers，该数组已按非递减顺序排列，请你从数组中找出满足相加之和等于目标数target的两个数。
 * 如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length。
 * 以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。
 * 你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。
 * 你所设计的解决方案必须只使用常量级的额外空间。
 *  
 * 示例 1：
 * 输入：numbers = [2,7,11,15], target = 9
 * 输出：[1,2]
 * 解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
 * 
 * 示例 2：
 * 输入：numbers = [2,3,4], target = 6
 * 输出：[1,3]
 * 解释：2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。
 * 
 * 示例 3：
 * 输入：numbers = [-1,0], target = -1
 * 输出：[1,2]
 * 解释：-1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
 * 
 * 提示：
 * 2 <= numbers.length <= 3 * 10^4
 * -1000 <= numbers[i] <= 1000
 * numbers 按 非递减顺序 排列
 * -1000 <= target <= 1000
 * 仅存在一个有效答案
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
