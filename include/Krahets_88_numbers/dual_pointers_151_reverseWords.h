#ifndef _LEETCODE_NUMS_151_REVERSEWORDS_H
#define _LEETCODE_NUMS_151_REVERSEWORDS_H

#include "god.h"
/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution_151 {
public:
    string reverseWords(string s) {
        string result = "";
        vector<string> words;
        for (int i = 0; i < s.size();i++) {
            while(i < s.size() && s[i] == ' ') {
                i++;
            }
            if (i == s.size()) {
                break;
            }
            string word = "";
            while (i < s.size() && s[i] != ' ') {
                word += s[i];
                i++;
            }
            words.push_back(word);
        }
        for (int i = words.size() - 1; i>0; i--) {
            result.append(words[i]);
            result += ' ';
        }
        result.append(words[0]);
        return result;
    }
};

TEST(test_problem_151, testcase)
{
    Solution_151 so;
    EXPECT_EQ(so.reverseWords("the sky is blue"), "blue is sky the");
    EXPECT_EQ(so.reverseWords("  hello world  "), "world hello");
    EXPECT_EQ(so.reverseWords("a good   example"), "example good a");
}
// @lc code=end

#endif /*_LEETCODE_NUMS_151_REVERSEWORDS_H*/
