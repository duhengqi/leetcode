#include "god.h"
/*
 * @lc app=leetcode.cn id=6 lang=cpp
 *
 * [6] Z 字形变换
 */

// @lc code=start
class Solution {
public:
    string convert(string s, int numRows) {
        int row = 0;
        int col = 0;
        int index = 0;
        string result;
        vector<vector<int>> z(numRows,vector<int>(1000,0));
        while(index < s.size()){
            row = 0;
            while(index < s.size() && row < numRows) {
                z[row][col] = s[index];
                index++;
                row++;
            }
            row = numRows - 2;
            col++;
            while (index < s.size() && row >0 ) {
                z[row][col] = s[index];
                row--;
                index++;
                col++;
            }
            col++;
        }
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < col; j++) {
                if (z[i][j] != 0) {
                    result += (z[i][j]);
                }
            }
        }
        return result;
    }
};
// @lc code=end

TEST(test_problem_6, testcase1)
{
    Solution so;
    string result = so.convert("PAYPALISHIRING",3);
    EXPECT_EQ(result,"PAHNAPLSIIGYIR");
}

TEST(test_problem_6, testcase2)
{
    Solution so;
    string result = so.convert("PAYPALISHIRING",4);
    EXPECT_EQ(result,"PINALSIGYAHRPI");
}
