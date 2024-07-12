#include "god.h"
/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution_59 {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n));
        int left = 0;
        int up = 0;
        int right = n-1;
        int down = n-1;
        int i, j;
        int num = 1;
        while(down >= up) {
            if (down == up) {
                for (i = up, j = left; j <= right; j++) {
                    result[i][j] = num;
                }
                break;
            }
            for (i = up, j = left; j < right; j++) {
                result[i][j] = num;
                num++;
            }
            for (i = up, j = right; i < down; i++) {
                result[i][j] = num;
                num++;
            }
            for (i = down, j = right; j > left; j--) {
                result[i][j] = num;
                num++;
            }
            for (i = down, j = left; i > up; i--) {
                result[i][j] = num;
                num++;
            }
            left++;
            right--;
            up++;
            down--;
        }
        return result;
    }
};
// @lc code=end


TEST(test_problem_59, testcase0)
{
    Solution_59 so;
    vector<vector<int>> result = so.generateMatrix(1);
    vector<vector<int>> exceptResult = {{1}};
    EXPECT_EQ(is_vector_equal(result[0],exceptResult[0]),true);
}

TEST(test_problem_59, testcase1)
{
    Solution_59 so;
    vector<vector<int>> result = so.generateMatrix(2);
    vector<vector<int>> exceptResult = {{1,2},{4,3}};
    EXPECT_EQ(is_vector_equal(result[0],exceptResult[0]),true);
    EXPECT_EQ(is_vector_equal(result[1],exceptResult[1]),true);
}

TEST(test_problem_59, testcase2)
{
    Solution_59 so;
    vector<vector<int>> result = so.generateMatrix(3);
    vector<vector<int>> exceptResult = {{1,2,3},{8,9,4},{7,6,5}};
    EXPECT_EQ(is_vector_equal(result[0],exceptResult[0]),true);
}
