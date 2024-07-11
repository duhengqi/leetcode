#include "god.h"
/*
 * @lc app=leetcode.cn id=796 lang=cpp
 *
 * [796] 旋转字符串
 */

// @lc code=start
class Solution_796 {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }

        int i = 0;
        while (i < s.size()) {
            if (s[i] != goal[0]) {
                i++;
                continue;
            }
            if (string(s, i)+string(s, 0, i) == goal) {
                return true;
            } else {i++;}
        }
        return false;
    }
};
// @lc code=end

TEST(test_problem_796, testcase1)
{
    Solution_796 so;
    bool result = so.rotateString("abcde","cdeab");
    EXPECT_EQ(result,true);
}

TEST(test_problem_796, testcase2)
{
    Solution_796 so;
    bool result = so.rotateString("abcde","abced");
    EXPECT_EQ(result,false);
}
