#ifndef _LEETCODE_NUMS_264_NTH_UGLY_NUMBER_H_
#define _LEETCODE_NUMS_264_NTH_UGLY_NUMBER_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 * 给你一个整数 n ，请你找出并返回第 n 个 丑数 。
 * 丑数 就是质因子只包含 2、3 和 5 的正整数。
 *
 * 示例 1：
 * 输入：n = 10   输出：12
 * 解释：[1, 2, 3, 4, 5, 6, 8, 9, 10, 12] 是由前 10 个丑数组成的序列。
 *
 * 示例 2：
 * 输入：n = 1  输出：1
 * 解释：1 通常被视为丑数。
 *
 * 提示：
 * 1 <= n <= 1690
 *  */

// @lc code=start
class Solution_264 {
public:
    int nthUglyNumber(int n)
    {
        queue<int> que;
        set<int> res;
        que.push(2);
        que.push(3);
        que.push(5);
        while(res.size() < 2*n) {
            int tmp = que.front();
            que.pop();
            res.emplace(tmp * 2);
            res.emplace(tmp * 3);
            res.emplace(tmp * 5);
        }
        
    }
};

// @lc code=end

TEST(test_problem_264, testcase0)
{
    Solution_264 so;
    EXPECT_EQ(so.nthUglyNumber(1352), 12);
    return;
}

#endif /*_LEETCODE_NUMS_264_NTH_UGLY_NUMBER_H_*/
