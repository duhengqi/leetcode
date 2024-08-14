#ifndef _LEETCODE_NUMS_50_MYPOW_H
#define _LEETCODE_NUMS_50_MYPOW_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=50 lang=cpp
 *
 * [50] Pow(x, n)
 * 实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，x^n ）。
 * 示例 1：
 * 输入：x = 2.00000, n = 10   输出：1024.00000
 * 示例 2：
 * 输入：x = 2.10000, n = 3   输出：9.26100
 * 示例 3：
 * 输入：x = 2.00000, n = -2
 * 输出：0.25000
 * 解释：2^-2 = 1/2*2 = 1/4 = 0.25
 * 提示：
 * -100.0 < x < 100.0
 * -2^31 <= n <= 2^31-1
 * n 是一个整数
 * 要么 x 不为零，要么 n > 0 。
 * -10^4 <= xn <= 10^4
 */

// @lc code=start
class Solution {
public:
    double myPowRecursion(double x, int n)
    {
        if (n == 0) {
            return 1;
        } else if (n == 1) {
            return x;
        }
        double result = myPowRecursion(x, n / 2);
        if (n % 2) {
            return  result* result * x;
        } else {
            return result* result;
        }
    }

    double myPow(double x, int n) {
        if (x == 0) {
            return 0;
        }
        if (n > 0) {
            return myPowRecursion(x, n); 
        } else {
            return 1/myPowRecursion(x, abs(n)); 
        }
    }
};

// @lc code=end

TEST(test_problem_50, testcase0)
{
    Solution so;
    double result = so.myPow(2.00000, 10);
    cout << result << endl;
    // EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_50, testcase1)
{
    Solution so;
    double result = so.myPow(2.1, 3);
    cout << result << endl;
    // EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_50, testcase2)
{
    Solution so;
    double result = so.myPow(2.00000, -2);
    cout << result << endl;
    // EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

#endif /*_LEETCODE_NUMS_50_MYPOW_H*/
