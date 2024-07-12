#include "god.h"
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

    }
};
// @lc code=end

TEST(test_problem_48, testcase0)
{
    Solution so;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    so.rotate(matrix);
    vector<vector<int>> exceptResult = {{7,4,1},{8,5,2},{9,6,3}};
    EXPECT_EQ(is_vector_equal(matrix[0],exceptResult[0]),true);
}

TEST(test_problem_48, testcase1)
{
    Solution so;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    so.rotate(matrix);
    vector<vector<int>> exceptResult = {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
    EXPECT_EQ(is_vector_equal(matrix[0],exceptResult[0]),true);
}
