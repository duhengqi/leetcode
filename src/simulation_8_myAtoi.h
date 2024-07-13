#include "god.h"

/*
 * @lc app=leetcode.cn id=8 lang=cpp
 *
 * [8] 字符串转换整数 (atoi)
 */

// @lc code=start
class Solution {
public:
    int myAtoi(string s) {
        /* positive number  negative number */
        bool isPositive = true;
        int index = 0;
        string sRe = "";
        long long int result = 0;
        while(index < s.size()) {
            if (s[index] == ' ') {
                index++;
                continue;
            } else if (s[index] == '-') {
                isPositive = false;
                index++;
                break;
            } else if (s[index] == '+') {
                index++;
                break;
            } else if (s[index] >= '0' && s[index] <= '9') {
                break;
            } else {
                return 0;
            }
        }
        while(index < s.size() && s[index]=='0') {
            index++;
        }
        while(index < s.size()) {
            if (s[index] <'0' || s[index]>'9') {
                break;
            }
            sRe += s[index];
            index++;
        }
        for (int i = 0; i < sRe.size(); i++){
            result = result * 10 + sRe[i] - '0';
            if (result > 2147483648 ) {
                break;
            }
        }
        if (isPositive) {
            return (result >= 2147483647) ? 2147483647 :(int)result;
        }
        return (result >= 2147483648) ? -2147483648 : (int)(0-result);
    }
};
// @lc code=end


TEST(test_problem_8, testcase0)
{
    Solution so;
    EXPECT_EQ(so.myAtoi("42"), 42);
}


TEST(test_problem_8, testcase1)
{
    Solution so;
    EXPECT_EQ(so.myAtoi("-042"), -42);
}

TEST(test_problem_8, testcase2)
{
    Solution so;
    EXPECT_EQ(so.myAtoi("1337c0d3"), 1337);
}

TEST(test_problem_8, testcase3)
{
    Solution so;
    EXPECT_EQ(so.myAtoi("0-1"), 0);
}

TEST(test_problem_8, testcase4)
{
    Solution so;
    EXPECT_EQ(so.myAtoi("words and 987"), 0);
}

/*int最大值 -2147483648~2147483647 */
TEST(test_problem_8, testcase5)
{
    Solution so;
    EXPECT_EQ(so.myAtoi("-112147483648"), -2147483648);
}

TEST(test_problem_8, testcase6)
{
    Solution so;
    EXPECT_EQ(so.myAtoi("123212147483647"), 2147483647);
}

TEST(test_problem_8, testcase7)
{
    Solution so;
    EXPECT_EQ(so.myAtoi("0042"), 42);
}

TEST(test_problem_8, testcase8)
{
    Solution so;
    EXPECT_EQ(so.myAtoi("  +0042"), 42);
}

TEST(test_problem_8, testcase9)
{
    Solution so;
    EXPECT_EQ(so.myAtoi(" + 0042"), 0);
}
