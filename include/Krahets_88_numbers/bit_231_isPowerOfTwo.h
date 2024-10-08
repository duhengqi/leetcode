#ifndef _LEETCODE_NUMS_231_IS_POWER_OF_TWO_H_
#define _LEETCODE_NUMS_231_IS_POWER_OF_TWO_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=231 lang=cpp
 *
 * [231] 2 的幂
 * 给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。
 * 如果存在一个整数 x 使得 n == 2^x ，则认为 n 是 2 的幂次方。
 *
 * 示例 1：
 * 输入：n = 1  输出：true
 * 解释：2^0 = 1
 *
 * 示例 2：
 * 输入：n = 16   输出：true
 * 解释：24 = 16
 *
 * 示例 3：
 * 输入：n = 3   输出：false
 *
 * 提示：
 * -2^31 <= n <= 2^31 - 1
 * 进阶：你能够不使用循环/递归解决此问题吗？
 */

// @lc code=start
class Solution {
public:
    bool isPowerOfTwo(int n)
    {
        if (n < 0) {
            return false;
        }
        n = (n & 0x55555555) + ((n >> 1) & 0x55555555);
        n = (n & 0x33333333) + ((n >> 2) & 0x33333333);
        n = (n & 0x0f0f0f0f) + ((n >> 4) & 0x0f0f0f0f);
        n = (n & 0x00ff00ff) + ((n >> 8) & 0x00ff00ff);
        n = (n & 0x0000ffff) + ((n >> 16) & 0x0000ffff);
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};

// @lc code=end

#endif /*_LEETCODE_NUMS_231_IS_POWER_OF_TWO_H_*/
