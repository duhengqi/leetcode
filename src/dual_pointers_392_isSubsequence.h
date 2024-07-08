#include "god.h"

/*
 * @lc app=leetcode.cn id=392 lang=cpp
 *
 * [392] 判断子序列
 */

// @lc code=start
class Solution_392 {
public:
    bool isSubsequence(string s, string t) {
        int left = 0;
        int right = 0;
        while (left < s.size() && right < t.size()) {
            if (s[left] == t[right]) {
                left++;
                right++;
            } else {
                right++;
            }
        }
        if (left != s.size()) {
            return false;
        }
        return true;
    }
};

TEST(test_problem_392, testcase)
{
    Solution_392 so;
    EXPECT_EQ(so.isSubsequence("abc","ahbgdc"), true);
    EXPECT_EQ(so.isSubsequence("axc","ahbgdc"), false);

}
// @lc code=end

