#include "god.h"
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {

    }
};
// @lc code=end

TEST(test_problem_946, testcase1)
{
    Solution so;
    string result = so.convert("PAYPALISHIRING",3);
    EXPECT_EQ(result,"PAHNAPLSIIGYIR");
}

TEST(test_problem_946, testcase1)
{
    Solution so;
    string result = so.convert("PAYPALISHIRING",4);
    EXPECT_EQ(result,"PINALSIGYAHRPI");
}
