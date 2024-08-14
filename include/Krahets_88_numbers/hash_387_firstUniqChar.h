#ifndef _LEETCODE_NUMS_387_FIRSTUNIQCHAR_H
#define _LEETCODE_NUMS_387_FIRSTUNIQCHAR_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 * https://leetcode.cn/problems/first-unique-character-in-a-string/
 */

// @lc code=start
class Solution_387 {
public:
// -1 初始值
// -100 无效值表示超过1个字符
// 大于0 表示 索引
    int firstUniqChar(string s) {
        int table[64] = {0};
        for (int i = 0; i < s.size(); i++) {
                table[s[i]-'a'] ++;
        }
        // 从字符串遍历，才能找到第一个，不能从数组遍历
        for (int i = 0; i < s.size();i++) {
            if (table[s[i]-'a'] == 1) {
                return i;
            }
        }
        return -1;
    }
};

TEST(test_problem_387, testcase)
{
    Solution_387 so;
    EXPECT_EQ(so.firstUniqChar("leetcode"), 0);
    EXPECT_EQ(so.firstUniqChar("loveleetcode"), 2);
    EXPECT_EQ(so.firstUniqChar("aabb"), -1);
}

// @lc code=end

#endif /*_LEETCODE_NUMS_387_FIRSTUNIQCHAR_H*/
