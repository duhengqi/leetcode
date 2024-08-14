#ifndef _LEETCODE_NUMS_394_DECODE_STRING_H
#define _LEETCODE_NUMS_394_DECODE_STRING_H

#include "god.h"
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 * https://leetcode.cn/problems/decode-string/description
 * 给定一个经过编码的字符串，返回它解码后的字符串。
 * 编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
 * 你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
 * 此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
 * 示例 1：
 * 输入：s = "3[a]2[bc]"    输出："aaabcbc"
 * 示例 2：
 * 输入：s = "3[a2[c]]"     输出："accaccacc"
 * 示例 3：
 * 输入：s = "2[abc]3[cd]ef"   输出："abcabccdcdcdef"
 * 示例 4：
 * 输入：s = "abc3[cd]xyz"   输出："abccdcdcdxyz"
 * 提示：
 * 1 <= s.length <= 30
 * s 由小写英文字母、数字和方括号 '[]' 组成
 * s 保证是一个 有效 的输入。
 * s 中所有整数的取值范围为 [1, 300] 
 */

// @lc code=start
class Solution_394 {
public:
    string decodeString(string s) {
        string result;
        stack<char> lStk;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= 'a' && s[i] <= 'z' && lStk.empty()) {
                result += s[i];
            } else if (s[i] == ']'){
                string tmpRes = "";
                // pop English letters
                while(lStk.top() != '[') {
                    tmpRes += lStk.top();
                    lStk.pop();
                }
                reverse(tmpRes.begin(), tmpRes.end());
                lStk.pop(); //pop '[]

                int dig = 1;
                int num = 0;
                // pop nums
                while(!lStk.empty() && (lStk.top() >= '0' && lStk.top()<= '9')) {
                    num += (lStk.top()-'0') * dig;
                    dig *= 10;
                    lStk.pop();
                }

                if (lStk.empty()) {
                    for (int i = 0; i < num; i++) {
                        result.append(tmpRes);
                    }
                } else {
                    for (int i = 0; i < num; i++) {
                        for (int j = 0; j < tmpRes.size();j++) {
                            lStk.push(tmpRes[j]);
                        }
                    }
                }
            } else {
                lStk.push(s[i]);
            }
        }
        return result;
    }

};

TEST(test_problem_394, testcase0)
{
    Solution_394 so;
    string result = so.decodeString("3[a]2[bc]");
    EXPECT_EQ(result,"aaabcbc");
}

// @lc code=end

#endif /*_LEETCODE_NUMS_394_DECODE_STRING_H*/
