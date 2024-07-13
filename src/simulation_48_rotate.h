#include "god.h"
/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */

// @lc code=start
class Solution_48 {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int up = 0;
        int right = matrix.size()-1;
        int down = matrix.size()-1;

        //四个角坐标 左上[up,left] 右上 [up,right] 左下 [down,left] 右下 [down,right]
        while(left < right) {
            int tmp0, tmp1;
            for (int i = 0; i+left < right;i++) {
                tmp0 = matrix[left+i][right];
                matrix[left+i][right] = matrix[up][left+i];

                tmp1 = matrix[down][right-i];
                matrix[down][right-i] = tmp0;

                tmp0 = matrix[right-i][left];
                matrix[right-i][left] = tmp1;

                matrix[up][left+i] = tmp0;
            }            
            left++;
            right--;
            up++;
            down--;
        }
    }
};
// @lc code=end

TEST(test_problem_48, testcase1)
{
    Solution_48 so;
    vector<vector<int>> matrix = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    so.rotate(matrix);
    vector<vector<int>> exceptResult = {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
    for (int i = 0; i < exceptResult.size();i++) {
        EXPECT_EQ(is_vector_equal(matrix[i], exceptResult[i]), true);
    }
}

TEST(test_problem_48, testcase2)
{
    Solution_48 so;
    vector<vector<int>> matrix = {{1,2},{3,4}};
    so.rotate(matrix);
    vector<vector<int>> exceptResult = {{3,1},{4,2}};
    EXPECT_EQ(is_vector_equal(matrix[0],exceptResult[0]),true);
    EXPECT_EQ(is_vector_equal(matrix[1],exceptResult[1]),true);
}

TEST(test_problem_48, testcase0)
{
    Solution_48 so;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    so.rotate(matrix);
    vector<vector<int>> exceptResult = {{7,4,1},{8,5,2},{9,6,3}};
    EXPECT_EQ(is_vector_equal(matrix[0],exceptResult[0]),true);
}
