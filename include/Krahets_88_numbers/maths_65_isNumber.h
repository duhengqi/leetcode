#ifndef _LEETCODE_NUMS_65_IS_NUMBER_H
#define _LEETCODE_NUMS_65_IS_NUMBER_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=65 lang=cpp
 *
 * [65] 有效数字
 * 给定一个字符串 s ，返回 s 是否是一个 有效数字。
 * 例如，下面的都是有效数字："2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"，
 * 而接下来的不是："abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"。
 * 
 * 一般的，一个 有效数字 可以用以下的规则之一定义：
 * 一个 整数 后面跟着一个 可选指数。
 * 一个 十进制数 后面跟着一个 可选指数。
 * 一个 整数 定义为一个 可选符号 '-' 或 '+' 后面跟着 数字。
 * 一个 十进制数 定义为一个 可选符号 '-' 或 '+' 后面跟着下述规则：
 * 数字 后跟着一个 小数点 .。
 * 数字 后跟着一个 小数点 . 再跟着 数位。
 * 一个 小数点 . 后跟着 数位。
 * 指数 定义为指数符号 'e' 或 'E'，后面跟着一个 整数。
 * 数字 定义为一个或多个数位。
 * 
 * 示例 1：
 * 输入：s = "0"   输出：true
 * 
 * 示例 2：
 * 输入：s = "e"    输出：false
 * 
 * 示例 3：
 * 输入：s = "."    输出：false
 * 
 * 提示：
 * 1 <= s.length <= 20
 * s 仅含英文字母（大写和小写），数字（0-9），加号 '+' ，减号 '-' ，或者点 '.' 。
 */

// @lc code=start
class Solution_65 {
public:
    bool isNumber(string s) {
        bool has_pos_neg = false;
        bool has_pos_neg_after_e = false;
        bool has_e = false;
        bool has_dot = false;
        bool has_number = false;
        bool has_number_after_dot = false;
        bool has_number_after_e = false;

        for (int i = 0; i < s.size();i++) {
            if (s[i] == '+' || s[i] == '-') {
                if (i != 0 && s[i-1] != 'e'&& s[i-1] != 'E') {
                    return false;
                }
            } else if (s[i] == '.') {
                if (has_e || has_dot) {
                    return false;
                }
                has_dot = true;
            } else if (s[i] == 'e' || s[i] == 'E') {
                if (has_e || has_number == false) {
                    return false;
                }
                has_e = true;
            } else if (s[i] >= '0' && s[i] <= '9') {
                if (has_e) {
                    has_number_after_e = true;
                } else{
                    has_number = true;
                }
            } else {
                return false;
            }
        }
        if (!has_number) {
            return false;
        } else if (has_e && !has_number_after_e) {
            return false;
        }

        return true;
    }
};
// @lc code=end

TEST(test_problem_65, testcase0)
{
    Solution_65 so;
    bool result = so.isNumber("2");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase1)
{
    Solution_65 so;
    bool result = so.isNumber("0089");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase2)
{
    Solution_65 so;
    bool result = so.isNumber("-0.1");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase3)
{
    Solution_65 so;
    bool result = so.isNumber("+3.14");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase4)
{
    Solution_65 so;
    bool result = so.isNumber("4.");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase5)
{
    Solution_65 so;
    bool result = so.isNumber("-.9");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase6)
{
    Solution_65 so;
    bool result = so.isNumber("2e10");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase7)
{
    Solution_65 so;
    bool result = so.isNumber("-90E3");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase8)
{
    Solution_65 so;
    bool result = so.isNumber("3e+7");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase9)
{
    Solution_65 so;
    bool result = so.isNumber("+3.14");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase10)
{
    Solution_65 so;
    bool result = so.isNumber("+6e-1");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase11)
{
    Solution_65 so;
    bool result = so.isNumber("-53.5e93");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase12)
{
    Solution_65 so;
    bool result = so.isNumber("-123.456e789");
    EXPECT_EQ(result, true);
}

TEST(test_problem_65, testcase13)
{
    Solution_65 so;
    bool result = so.isNumber("abc");
    EXPECT_EQ(result, false);
}

TEST(test_problem_65, testcase14)
{
    Solution_65 so;
    bool result = so.isNumber("1a");
    EXPECT_EQ(result, false);
}

TEST(test_problem_65, testcase15)
{
    Solution_65 so;
    bool result = so.isNumber("1e");
    EXPECT_EQ(result, false);
}

TEST(test_problem_65, testcase16)
{
    Solution_65 so;
    bool result = so.isNumber("e3");
    EXPECT_EQ(result, false);
}

TEST(test_problem_65, testcase17)
{
    Solution_65 so;
    bool result = so.isNumber("99e2.5");
    EXPECT_EQ(result, false);
}

TEST(test_problem_65, testcase18)
{
    Solution_65 so;
    bool result = so.isNumber("--6");
    EXPECT_EQ(result, false);
}

TEST(test_problem_65, testcase19)
{
    Solution_65 so;
    bool result = so.isNumber("-+3");
    EXPECT_EQ(result, false);
}

TEST(test_problem_65, testcase20)
{
    Solution_65 so;
    bool result = so.isNumber("95a54e53");
    EXPECT_EQ(result, false);
}

#endif /*_LEETCODE_NUMS_65_IS_NUMBER_H*/
