#include "god.h"
/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 */

// @lc code=start
class Solution {
public:
    int longestPalindrome(string s) {
        int dupNum = 0;
        int singleNum = 0;
        int result = 0;
        unsigned int table[64] = {0};

        for (int i = 0; i < s.size(); i++) {
            table[s[i] - 'A']++;
        }
        for (int i = 0; i < 64; i++) {
            if (table[i] == 0) {
                continue;
            }
            if (table[i]%2 == 0) {
                dupNum += table[i];
            } else {
                dupNum += table[i]-1;
                singleNum += 1;
            }
        }
        result = dupNum + ((singleNum > 0) ? 1 : 0);
        return result;
    }
};

TEST(test_problem_409, testcase)
{
    Solution so;
    EXPECT_EQ(so.longestPalindrome("abccccdd"), 7);
    EXPECT_EQ(so.longestPalindrome("a"), 1);
    EXPECT_EQ(so.longestPalindrome("ABCabc"), 1);
    EXPECT_EQ(so.longestPalindrome("ABBDC"), 3);
    EXPECT_EQ(so.longestPalindrome("aaacccddd"), 7);
}
// @lc code=end

