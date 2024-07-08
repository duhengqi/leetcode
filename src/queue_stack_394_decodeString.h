#include "god.h"
/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
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

/* test case
"3[a]2[bc]"
"3[a2[c]]"
"2[abc]3[cd]ef"
*/ 
static void Problem_394_test()
{
    Solution_394 so;
    string result = so.decodeString("3[a]2[bc]");
    cout << result << endl;
    return;
}
// @lc code=end

