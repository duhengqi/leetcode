#include "god.h"
/*
 * @lc app=leetcode.cn id=205 lang=cpp
 *
 * [205] 同构字符串
 */

// @lc code=start
class Solution_205 {
public:
    bool isIsomorphic(string s, string t) {
        int tableS[256] = {0};
        int tableT[256] = {0};
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            if (tableS[s[i]] == 0 && tableT[t[i]] == 0) {
                tableS[s[i]] = t[i];
                tableT[t[i]] = s[i];
            } else if (tableS[s[i]] == t[i] && tableT[t[i]] == s[i]){
            } else {
                return false;
            }
        }
        return true;
    }
};

TEST(test_problem_205, testcase)
{
    Solution_205 so;
    EXPECT_EQ(so.isIsomorphic("egg","add"), true);
    EXPECT_EQ(so.isIsomorphic("foo","bar"), false);
    EXPECT_EQ(so.isIsomorphic("paper","title"), true);
    EXPECT_EQ(so.isIsomorphic("badc","baba"), false);
    EXPECT_EQ(so.isIsomorphic("13","24"), true);
}

// @lc code=end

