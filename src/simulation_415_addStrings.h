#include "god.h"

/*
 * @lc app=leetcode.cn id=415 lang=cpp
 *
 * [415] 字符串相加
 */

// @lc code=start
class Solution {
public:
    string addStrings(string num1, string num2) {
        int sum;
        int bit = 0;
        stack<char> stk;
        string result = "";
        int index1 = num1.size()-1;
        int index2 = num2.size()-1;

        while (index1 >= 0 && index2>=0) {
            sum = num1[index1] - '0' + num2[index2] - '0' + bit;
            if (sum > 9) {
                bit = 1;
                stk.push(sum-10+'0');
            } else {
                bit = 0;
                stk.push(sum+'0');
            }
            index1--;
            index2--;
        }

        while(index1 >= 0) {
            sum = num1[index1] - '0' + bit;
            if (sum > 9) {
                bit = 1;
                stk.push(sum-10+'0');
            } else {
                bit = 0;
                stk.push(sum+'0');
            }
            index1--;
        }
        while(index2 >= 0) {
            sum = num2[index2] - '0' + bit;
            if (sum > 9) {
                bit = 1;
                stk.push(sum-10+'0');
            } else {
                bit = 0;
                stk.push(sum+'0');
            }
            index2--;
        }
        if (bit == 1) {
            stk.push('1');
        }
        while(!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }

};

TEST(test_problem_415, testcase1)
{
    Solution so;
    string strCase1Left = "11";
    string strCase1Right = "123";
    string result = so.addStrings(strCase1Left,strCase1Right);
    string exceptResult = "134";

    EXPECT_EQ(exceptResult, result);
}

TEST(test_problem_415, testcase2)
{
    Solution so;
    string strCase1Left = "456";
    string strCase1Right = "77";
    string result = so.addStrings(strCase1Left,strCase1Right);
    string exceptResult = "533";

    EXPECT_EQ(exceptResult, result);
}

TEST(test_problem_415, testcase3)
{
    Solution so;
    string strCase1Left = "0";
    string strCase1Right = "0";
    string result = so.addStrings(strCase1Left,strCase1Right);
    string exceptResult = "0";

    EXPECT_EQ(exceptResult, result);
}

TEST(test_problem_415, testcase4)
{
    Solution so;
    string strCase1Left = "6";
    string strCase1Right = "501";
    string result = so.addStrings(strCase1Left,strCase1Right);
    string exceptResult = "507";

    EXPECT_EQ(exceptResult, result);
}

// @lc code=end

