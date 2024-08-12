#ifndef _LEETCODE_NUMS_264_NTH_UGLY_NUMBER_H_
#define _LEETCODE_NUMS_264_NTH_UGLY_NUMBER_H_

#include "god.h"
#include "cmath"
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
        queue<long> single;
        int m = 2;
        int twoIndex = 2;
        vector<long> uglys = {1, 2, 3, 4, 5};
        single.push(3);
        single.push(5);
        while (uglys.size() < n) {
            long fiveNum = pow(5, m);
            if (2*uglys[twoIndex] < 3*single.front()) {
                if (2*uglys[twoIndex] < fiveNum) {
                    uglys.push_back(2*uglys[twoIndex]);
                    twoIndex++;
                } else {
                    single.push(fiveNum);
                    uglys.push_back(fiveNum);
                    m++;
                }
            } else {
                if (3*single.front() < fiveNum) {
                    single.push(3*single.front());
                    uglys.push_back(3*single.front());
                    single.pop();
                } else {
                    single.push(fiveNum);
                    uglys.push_back(fiveNum);
                    m++;
                }
            }
        }
        return uglys[n-1];
    }
};

// @lc code=end

TEST(test_problem_264, testcase0)
{
    Solution_264 so;
    EXPECT_EQ(so.nthUglyNumber(10), 12);
    return;
}

#endif /*_LEETCODE_NUMS_264_NTH_UGLY_NUMBER_H_*/
