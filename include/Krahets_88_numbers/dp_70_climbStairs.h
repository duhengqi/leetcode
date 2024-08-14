#ifndef _LEETCODE_NUMS_70_CLIMB_STAIRS_H_
#define _LEETCODE_NUMS_70_CLIMB_STAIRS_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 示例 1：
 * 输入：n = 2  输出：2
 * 解释：有两种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶
 * 2. 2 阶
 * 
 * 示例 2：
 * 输入：n = 3  输出：3
 * 解释：有三种方法可以爬到楼顶。
 * 1. 1 阶 + 1 阶 + 1 阶
 * 2. 1 阶 + 2 阶
 * 3. 2 阶 + 1 阶
 * 
 * 提示：
 * 1 <= n <= 45
 */

// @lc code=start

class Solution_70 {
public:
    int climbStairs(int n) {
        vector<int> fib;
        fib.push_back(0);
        fib.push_back(1);
        fib.push_back(2);
        for(int i = 3; i <= n; i++) {
            fib.push_back(fib[i-1]+fib[i-2]);
        }
        return fib[n];
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_70_CLIMB_STAIRS_H_*/
