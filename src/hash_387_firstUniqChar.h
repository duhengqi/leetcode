#include "god.h"

/*
 * @lc app=leetcode.cn id=387 lang=cpp
 *
 * [387] 字符串中的第一个唯一字符
 */

// @lc code=start
class Solution_387 {
public:
    int firstUniqChar(string s) {
        int table[64] = {-1};
        for (int i = 0; i< 64;i++) {
            table[i] = -1;
        }
        for (int i = 0; i < s.size(); i++) {
            if (table[s[i]-'a'+1] == -1) {
                table[s[i]-'a'+1] = i;
                
            } else if (table[s[i]-'a'+1] >= 0){
                table[s[i]-'a'+1] = -100;
            }
        }
        for (int i = 0; i < s.size();i++) {
            if (table[s[i]-'a'+1] >= 0) {
                return i;
            }
        }
        return -1;
    }
};
// @lc code=end

