#ifndef _LEETCODE_NUMS_400_FIND_NTH_DIGIT_H
#define _LEETCODE_NUMS_400_FIND_NTH_DIGIT_H

#include "god.h"
#include "cmath"
/*
 * @lc app=leetcode.cn id=400 lang=cpp
 *
 * [400] 第 N 位数字
 * 给你一个整数 n ，请你在无限的整数序列 [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...] 中找出并返回第 n 位上的数字。
 * 
 * 示例 1：
 * 输入：n = 3   输出：3
 * 
 * 示例 2：
 * 输入：n = 11   输出：0
 * 解释：第 11 位数字在序列 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... 里是 0 ，它是 10 的一部分。
 * 
 * 提示：
 * 1 <= n <= 2^31 - 1
 */

// @lc code=start
class Solution_400 {
public:
    int findNthDigit(int n) {
        if (n < 10) {
            return n;
        }
        long num = 9;
        int dig = 1;

        while (n >= num*dig) {
            n -= num * dig;
            num *= 10;
            dig += 1;
        }

        if (n == 0) {
            return 9;
        }

        int start = pow(10, dig-1) + (n-1)/dig;
        int result = to_string(start)[(n-1) % dig] - '0';

        return result;
    }
};
// @lc code=end

TEST(test_problem_400, testcase0)
{
    Solution_400 so;
    EXPECT_EQ(so.findNthDigit(11), 0);
}

TEST(test_problem_400, testcase1)
{
    Solution_400 so;
    EXPECT_EQ(so.findNthDigit(10), 1);
}

TEST(test_problem_400, testcase2)
{
    Solution_400 so;
    EXPECT_EQ(so.findNthDigit(189), 9);
}

TEST(test_problem_400, testcase3)
{
    Solution_400 so;
    EXPECT_EQ(so.findNthDigit(191), 0);
}

#endif /*_LEETCODE_NUMS_400_FIND_NTH_DIGIT_H*/
