#ifndef _LEETCODE_NUMS_371_GET_SUM_H_
#define _LEETCODE_NUMS_371_GET_SUM_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=371 lang=cpp
 *
 * [371] 两整数之和
 * 给你两个整数 a 和 b ，不使用 运算符 + 和 - ​​​​​​​，计算并返回两整数之和。
 * 示例 1：
 * 输入：a = 1, b = 2   输出：3
 *
 * 示例 2：
 * 输入：a = 2, b = 3   输出：5
 *
 * 提示：
 * -1000 <= a, b <=
 *
 * 数字9 原码：0000 1001
 * 数字9 反码  1111 0110
 * 数字9 补码  1111 0111 (反码+1)
 */

// @lc code=start

class Solution_371 {
public:
    /** 
     * a&b == 1 表示存在进位 (a&b)<<1保存了进位，继续与 a^b 运算
     * a&b == 0 表示没有进位，则 a^b就是结果。
    */
    int getSum1(int a, int b)
    {
        while (b != 0) {
            unsigned int carry = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = carry;
        }
        return a;
    }

    int getSum(int a, int b)
    {
        bool dig = false;
        int result = 0;
        for (int i = 0; i < 32; i++) {
            int tmp = 1 << i;
            if ((a & tmp) & (b & tmp)) {
                if (dig) {
                    result |= tmp;
                    dig = true;
                } else {
                    dig = true;
                }
            } else if ((a & tmp) ^ (b & tmp)) {
                if (dig) {
                    dig = true;
                } else {
                    result |= tmp;
                }
            } else {
                if (dig) {
                    result |= tmp;
                    dig = false;
                }
            }
        }
        return result;
    }
};

// @lc code=end

TEST(test_problem_371, testcase0)
{
    Solution_371 so;
    EXPECT_EQ(so.getSum(3, 3), 6);
}

TEST(test_problem_371, testcase1)
{
    Solution_371 so;
    EXPECT_EQ(so.getSum(-41, 30), -11);
}

TEST(test_problem_371, testcase2)
{
    Solution_371 so;
    EXPECT_EQ(so.getSum(-11, 30), 19);
}

TEST(test_problem_371, testcase3)
{
    Solution_371 so;
    EXPECT_EQ(so.getSum(-11, -30), -41);
}

#endif /*_LEETCODE_NUMS_371_GET_SUM_H_*/
