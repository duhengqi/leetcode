#ifndef _LEETCODE_NUMS_10_IS_MATCH_H_
#define _LEETCODE_NUMS_10_IS_MATCH_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=10 lang=cpp
 *
 * [10] 正则表达式匹配
 * 给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。
 * '.' 匹配任意单个字符
 * '*' 匹配零个或多个前面的那一个元素
 * 所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。
 *  
 * 示例 1：
 * 输入：s = "aa", p = "a"  输出：false
 * 解释："a" 无法匹配 "aa" 整个字符串。

 * 示例 2:
 * 输入：s = "aa", p = "a*"   输出：true
 * 解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。

 * 示例 3：
 * 输入：s = "ab", p = ".*"  输出：true
 * 解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。
 * 
 * 提示：
 * 1 <= s.length <= 20
 * 1 <= p.length <= 20
 * s 只包含从 a-z 的小写字母。
 * p 只包含从 a-z 的小写字母，以及字符 . 和 *。
 * 保证每次出现字符 * 时，前面都匹配到有效的字符
 */

// @lc code=start
class Solution_10 {
public:
    bool isMatch(string s, string p) {
        int sIndex = 0;
        int pIndex = 0;
        while (pIndex < p.size() && sIndex < s.size()) {
            if (p[pIndex] == '.') {
                sIndex++;
                pIndex++;
            } else if(p[pIndex] == '*') {
                if (p[pIndex-1] == '.') {
                   string::size_type posTmp = sIndex;
                    while (posTmp != string::npos) {
                        posTmp = s.find(p[pIndex+1], sIndex);
                        if (posTmp == string::npos) {
                            return false;
                        }
                        // cout << s.?substr(posTmp) << " " << p.substr(pIndex + 1) << endl;
                        if (isMatch(s.substr(posTmp),p.substr(pIndex+1))) {
                            return true;
                        }
                        sIndex = posTmp+1;
                    } 
                } else {
                    string::size_type posTmp = sIndex;
                    while (posTmp != string::npos) {
                        posTmp = s.find(p[pIndex+1], sIndex);
                        if (posTmp == string::npos) {
                            return false;
                        }
                        // cout << s.?substr(posTmp) << " " << p.substr(pIndex + 1) << endl;
                        if (isMatch(s.substr(posTmp),p.substr(pIndex+1))) {
                            return true;
                        }
                        sIndex = posTmp+1;
                    }
                    return false;
                }
            } else {
                if (p[pIndex] == s[sIndex]) {
                    sIndex++;
                    pIndex++;
                } else {
                    return false;
                }
            }
            if (sIndex == s.size() && pIndex == p.size()) {
                return true;
            }
        }

        return false;
    }
};
// @lc code=end

TEST(test_problem_10, testcase0)
{
    Solution_10 so;
    string s = "aa";
    string p = "a";
    bool result = so.isMatch(s, p);
    EXPECT_EQ(result, false);
}

TEST(test_problem_10, testcase1)
{
    Solution_10 so;
    string s = "aa";
    string p = "a*";
    bool result = so.isMatch(s, p);
    EXPECT_EQ(result, true);
}

TEST(test_problem_10, testcase2)
{
    Solution_10 so;
    string s = "aa";
    string p = ".*";
    bool result = so.isMatch(s, p);
    EXPECT_EQ(result, true);
}


TEST(test_problem_10, testcase3)
{
    Solution_10 so;
    string s = "aa";
    string p = ".*b";
    bool result = so.isMatch(s, p);
    EXPECT_EQ(result, false);;
}

TEST(test_problem_10, testcase4)
{
    Solution_10 so;
    string s = "aabcdseds";
    string p = "aa.cd*e*s";
    bool result = so.isMatch(s, p);
    EXPECT_EQ(result, true);;
}

TEST(test_problem_10, testcase5)
{
    Solution_10 so;
    string s = "aabcdseds";
    string p = "a*.";
    bool result = so.isMatch(s, p);
    EXPECT_EQ(result, true);;
}

TEST(test_problem_10, testcase6)
{
    Solution_10 so;
    string s = "a";
    string p = "*.";
    bool result = so.isMatch(s, p);
    EXPECT_EQ(result, false);;
}

TEST(test_problem_10, testcase7)
{
    Solution_10 so;
    string s = "aasdfasdf";
    string p = "*.df";
    bool result = so.isMatch(s, p);
    EXPECT_EQ(result, true);;
}

#endif /*_LEETCODE_NUMS_10_IS_MATCH_H_*/
