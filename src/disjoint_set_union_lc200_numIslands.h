#ifndef _LEETCODE_NUMS_200_NUM_ISLANDS_H_
#define _LEETCODE_NUMS_200_NUM_ISLANDS_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 * 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
 * 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
 * 此外，你可以假设该网格的四条边均被水包围。
 * 
 * 示例 1：
 * 输入：grid = [
 *   ["1","1","1","1","0"],
 *   ["1","1","0","1","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","0","0","0"]
 * ]
 * 输出：1
 * 
 * 示例 2：
 * 输入：grid = [
 *   ["1","1","0","0","0"],
 *   ["1","1","0","0","0"],
 *   ["0","0","1","0","0"],
 *   ["0","0","0","1","1"]
 * ]
 * 输出：3
 * 
 * 提示：
 * m == grid.length
 * n == grid[i].length
 * 1 <= m, n <= 300
 * grid[i][j] 的值为 '0' 或 '1'
 */

// @lc code=start
class Solution_200 {
public:
    int numIslands(vector<vector<char>>& grid) {
        int num = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[i].size();j++) {
                if (grid[i][j] == '0') {
                  continue;
                }
                if ((i > 0 && grid[i-1][j] == '1') || (j > 0 && grid[i][j-1] == '1')) {
                    continue;
                }
                num++;
            }
        }
        return num;
    }
};
// @lc code=end

TEST(test_problem_200, testcase0)
{
    Solution_200 so;
    vector<vector<char>> grid = {
        {'1', '1', '1', '1', '0'},
        {'1', '1', '0', '1', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };
    int result = so.numIslands(grid);
    EXPECT_EQ(result, 1);;
}


TEST(test_problem_200, testcase1)
{
    Solution_200 so;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int result = so.numIslands(grid);
    EXPECT_EQ(result, 3);;
}

#endif /*_LEETCODE_NUMS_200_NUM_ISLANDS_H_*/
