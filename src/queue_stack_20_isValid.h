#ifndef _LEETCODE_NUMS_20_ISVALID_H
#define _LEETCODE_NUMS_20_ISVALID_H

#include "god.h"
/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 * https://leetcode.cn/problems/valid-parentheses/description/
 */

// @lc code=start
class Solution_20 {
public:
    bool isValid(string s) {
        stack<char> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else if (s[i] == ')' && !stk.empty() && stk.top() == '(') {
                stk.pop();
            } else if (s[i] == '}' && !stk.empty() && stk.top() == '{') {
                stk.pop();
            } else if (s[i] == ']' && !stk.empty() && stk.top() == '[') {
                stk.pop();
            } else {
                return false;
            }

        }
        return  stk.empty();
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_20_ISVALID_H*/
