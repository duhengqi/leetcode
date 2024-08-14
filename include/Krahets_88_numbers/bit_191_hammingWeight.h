#ifndef _LEETCODE_NUMS_191_HAMMING_WEIGHT_H_
#define _LEETCODE_NUMS_191_HAMMING_WEIGHT_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=191 lang=cpp
 *
 * [191] 位1的个数
 * 编写一个函数，获取一个正整数的二进制形式并返回其二进制表达式中 设置位 的个数（也被称为汉明重量）。
 * 示例 1：
 * 输入：n = 11  输出：3
 * 解释：输入的二进制串 1011 中，共有 3 个设置位。
 * 
 * 示例 2：
 * 输入：n = 128  输出：1
 * 解释：输入的二进制串 10000000 中，共有 1 个设置位。
 * 
 * 示例 3：
 * 输入：n = 2147483645  输出：30
 * 解释：输入的二进制串 11111111111111111111111111111101 中，共有 30 个设置位。
 * 
 * 提示：
 * 1 <= n <= 231 - 1
 * 
 * 进阶：
 * 如果多次调用这个函数，你将如何优化你的算法？
 */

// @lc code=start
class Solution_191 {
public:
    int hammingWeight(int n) {
        int sum = 0;
        for (int i = 0;i<31;i++){
            int tmp = 1 << i;
            if (tmp > n) {
                break;
            }
            if ((n & tmp) != 0) {
                sum++;
            }
        }
        return sum;
    }
};
// @lc code=end

TEST(test_problem_191, testcase0)
{
    Solution_191 so;
    EXPECT_EQ(so.hammingWeight(11), 3);
}

TEST(test_problem_191, testcase1)
{
    Solution_191 so;
    EXPECT_EQ(so.hammingWeight(2147483645), 30);
}

TEST(test_problem_191, testcase2)
{
    Solution_191 so;
    EXPECT_EQ(so.hammingWeight(128), 1);
}

#endif /*_LEETCODE_NUMS_191_HAMMING_WEIGHT_H_*/
