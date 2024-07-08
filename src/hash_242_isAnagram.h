#include "god.h"
/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

// @lc code=start
#define ANAGRAM_242_TABLE_MAX 64
class Solution_242 {
public:
    bool isAnagram(string s, string t) {
        unsigned int sTable[ANAGRAM_242_TABLE_MAX]={0};
        unsigned int tTable[ANAGRAM_242_TABLE_MAX]={0};
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            sTable[s[i] - 'a']++;
            tTable[t[i] - 'a']++;
        }
        for (int i = 0; i < ANAGRAM_242_TABLE_MAX; i++) {
            if (sTable[i] != tTable[i]) {
                return false;
            }
        }
        return true;
    }
};

TEST(test_problem_242, testcase)
{
    Solution_242 so;
    EXPECT_EQ(true, so.isAnagram("anagram", "nagaram"));
}
// @lc code=end

