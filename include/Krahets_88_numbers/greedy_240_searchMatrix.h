#ifndef _LEETCODE_NUMS_240_SEARCH_MATRIX_H_
#define _LEETCODE_NUMS_240_SEARCH_MATRIX_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=240 lang=cpp
 *
 * [240] 搜索二维矩阵 II
 * 编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：
 * 每行的元素从左到右升序排列。
 * 每列的元素从上到下升序排列。
 * 
 * 示例 1：
 * 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
 * 输出：true
 * 
 * 示例 2：
 * 输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
 * 输出：false
 * 
 * 提示：
 * m == matrix.length
 * n == matrix[i].length
 * 1 <= n, m <= 300
 * -10^9 <= matrix[i][j] <= 10^9
 * 每行的所有元素从左到右升序排列
 * 每列的所有元素从上到下升序排列
 * -10^9 <= target <= 10^9
 */

// @lc code=start
class Solution_240 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int i = 0;
        int j = matrix[0].size()-1;
        while (i < matrix.size()&&j>=0){
            if (matrix[i][j] == target) {
                return true;
            }
            if (matrix[i][j] < target) {
                i++;
                continue;
            } else {
                j--;
            }
        }
        return false;
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_240_SEARCH_MATRIX_H_*/


TEST(test_problem_240, testcase0)
{
    Solution_240 so;
    vector<vector<int>> matrix = {{-5}};

    bool result = so.searchMatrix(matrix,-10);

    EXPECT_EQ(result, false);
}

