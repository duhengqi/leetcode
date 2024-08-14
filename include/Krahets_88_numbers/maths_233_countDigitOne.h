#ifndef _LEETCODE_NUMS_233_COUNT_DIGIT_ONE_H
#define _LEETCODE_NUMS_233_COUNT_DIGIT_ONE_H

#include "god.h"
#include "cmath"
/*
 * @lc app=leetcode.cn id=233 lang=cpp
 *
 * [233] 数字 1 的个数
 * 给定一个整数 n，计算所有小于等于 n 的非负整数中数字 1 出现的个数。
 * 
 * 示例 1：
 * 输入：n = 13  输出：6
 * 
 * 示例 2：
 * 输入：n = 0  输出：0
 * 
 * 提示：
 * 0 <= n <= 10^9
 */

// @lc code=start
class Solution_233 {
public:
    void countDigitOneRecursion(string str, vector<int>& record, int &result)
    {
        if (str.size() == 0) {
            return;
        }
        if (str.size() == 1) {
            result += 1;
            return;
        }
        int index = 1;
        while (index < str.size()) {
            if (str[index] != '0') {
                break;
            }
            index++;
        }
        string subStr = str.substr(index);
        if (str[0] == '1') {
            result += record[str.size() - 1] + atoi(subStr.c_str())+1;
            countDigitOneRecursion(subStr, record, result);
        } else {
            result += record[str.size() - 1] * (str[0] - '0') + pow(10, str.size()-1);
            countDigitOneRecursion(subStr, record, result);
        }
    }
    int countDigitOne(int n) {
        if (n == 0) {
            return 0;
        }
        if (n < 10) {
            return 1;
        }
        vector<int> record(10);
        record[0] = 0;
        record[1] = 1;
        int dig = 10;
        for (int i = 2; i < 10; i++) {
            record[i] = 10 * record[i - 1] + dig * 1;
            dig *= 10;
        }
        int result = 0;
        countDigitOneRecursion(to_string(n), record, result);

        return result;
    }
};
// @lc code=end

TEST(test_problem_233, testcase0)
{
    Solution_233 so;
    EXPECT_EQ(so.countDigitOne(13), 6);
}


TEST(test_problem_233, testcase1)
{
    Solution_233 so;
    EXPECT_EQ(so.countDigitOne(23), 13);
}


TEST(test_problem_233, testcase2)
{
    Solution_233 so;
    EXPECT_EQ(so.countDigitOne(100), 21);
}

#endif /*_LEETCODE_NUMS_233_COUNT_DIGIT_ONE_H*/
