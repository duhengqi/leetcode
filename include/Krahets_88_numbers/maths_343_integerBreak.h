#ifndef _LEETCODE_NUMS_343_INTEGER_BREAK_H
#define _LEETCODE_NUMS_343_INTEGER_BREAK_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 * 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
 * 返回 你可以获得的最大乘积 。
 * 示例 1:
 * 输入: n = 2  输出: 1
 * 解释: 2 = 1 + 1, 1 × 1 = 1。
 * 
 * 示例 2:
 * 输入: n = 10    输出: 36
 * 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
 * 
 * 提示:
 * 2 <= n <= 58
 * 
 */

// @lc code=start
class Solution_343 {
public:
    int integerBreak(int n) {
        vector<int> record = {0, 1, 1, 2, 4, 6, 9, 12, 18, 27, 36};
        if (n < 11) {
            return record[n];
        }
        int result = 1;
        while (n > 10) {
            result *= 3;
            n -= 3;
        }
        return result*record[n];
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_343_INTEGER_BREAK_H*/
