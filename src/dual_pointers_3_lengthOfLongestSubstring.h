#include "god.h"

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
class Solution_3 {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        int table[256] = {0};
        int result = 0;
        int tSize = 0;
        int sLen = s.size();

        if (sLen <= 1) {
            return sLen;
        }
        while (right < sLen) {
            if (table[s[right]] == 0) {
                table[s[right]] = 1;
                right++;
                tSize++;
                result = ((tSize > result) ? tSize : result);
                continue;
            }
            while (table[s[right]] != 0) {
                table[s[left]] = 0;
                left++;
                tSize--;
            }
        }
        return result;
    }
};
// @lc code=end

TEST(test_problem_3, testcase)
{
    Solution_3 so;
    EXPECT_EQ(so.lengthOfLongestSubstring("abcabcbb"), 3);
    EXPECT_EQ(so.lengthOfLongestSubstring("bbbbb"), 1);
    EXPECT_EQ(so.lengthOfLongestSubstring("pwwkew"), 3);
}