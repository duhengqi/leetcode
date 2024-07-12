#include "god.h"
/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        return result;
    }
};
// @lc code=end
TEST(test_problem_54, testcase0)
{
    Solution so;
    vector<vector<int>> matrix = {{1,2,3,4}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,4};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase1)
{
    Solution so;
    vector<vector<int>> matrix = {{1},{2},{3},{4},{5}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,4,5,6};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase2)
{
    Solution so;
    vector<vector<int>> matrix = {{1,2},{3,4}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,4,3};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase3)
{
    Solution so;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,6,9,8,7,4,5};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase4)
{
    Solution so;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9},{10,11,12}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,6,9,8,7,4,5};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase5)
{
    Solution so;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,6,9,8,7,4,5};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}

TEST(test_problem_54, testcase6)
{
    Solution so;
    vector<vector<int>> matrix = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> result = so.spiralOrder(matrix);
    vector<int> exceptResult = {1,2,3,4,8,12,11,10,9,5,6,7};
    EXPECT_EQ(is_vector_equal(result,exceptResult),true);
}