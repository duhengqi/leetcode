#include "god.h"
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution_54 {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int left = 0;
        int up = 0;
        int right = matrix[0].size()-1;
        int down = matrix.size()-1;
        int i, j;
        while(1) {
            if (down < up) {
                break;
            } else if (down == up) {
                for (i = up, j = left; j <= right; j++) {
                    result.push_back(matrix[i][j]);
                }
                break;
            }
            if ( right < left) {
                break;
            } else if (right == left) {
                for (i = up, j = left; i <= down; i++) {
                    result.push_back(matrix[i][j]);
                }
                break;
            }
            for (i = up, j = left; j < right; j++) {
                result.push_back(matrix[i][j]);
            }
            for (i = up, j = right; i < down; i++) {
                result.push_back(matrix[i][j]);
            }
            for (i = down, j = right; j > left; j--) {
                result.push_back(matrix[i][j]);
            }
            for (i = down, j = left; i > up; i--) {
                result.push_back(matrix[i][j]);
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
TEST(test_problem_54, testcase0)
{
    Solution_54 so;
    vector<vector<int>> matrix = {{1,2,3,4}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,4};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase1)
{
    Solution_54 so;
    vector<vector<int>> matrix = {{1},{2},{3},{4},{5}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,4,5};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase2)
{
    Solution_54 so;
    vector<vector<int>> matrix = {{1,2},{3,4}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,4,3};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase3)
{
    Solution_54 so;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,4,8,12,11,10,9,5,6,7};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase4)
{
    Solution_54 so;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,6,9,12,11,10,7,4,5,8};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase5)
{
    Solution_54 so;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,6,9,8,7,4,5};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase6)
{
    Solution_54 so;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,4,8,12,11,10,9,5,6,7};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}