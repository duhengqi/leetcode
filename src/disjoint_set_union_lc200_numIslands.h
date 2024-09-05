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
    int find(vector<int> &father, int x)
    {
        if (father[x] == x) {
            return x;
        } else {
            return father[x] = find(father, father[x]);
        }
    }

    void merge(vector<int> &father, int i, int j)
    {
        int x = find(father, i);
        int y = find(father, j);
        if (find(father, x) < find(father, y)) {
            father[y] = find(father, x);
        } else {
            father[x] = find(father, y);
        }
    }

    int numIslands(vector<vector<char>> &grid)
    {
        int num = 0;
        int row = grid.size();
        int col = grid[0].size();
        vector<int> father(row * col, -1);

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '0') {
                    continue;
                }
                father[i * col + j] = i * col + j;
                if ((i > 0 && grid[i - 1][j] == '1') && (j > 0 && grid[i][j - 1] == '1')) {
                    int x = (i - 1) * col + j;
                    int y = i * col + j - 1;
                    father[i * col + j] = (find(father, x) < find(father, y) ? find(father, x) : find(father, y));
                    merge(father, x, y);
                } else if (i > 0 && grid[i - 1][j] == '1') {
                    father[i * col + j] = find(father, (i - 1) * col + j);
                } else if (j > 0 && grid[i][j - 1] == '1') {
                    father[i * col + j] = find(father, i * col + j - 1);
                }
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (father[i * col + j] == i * col + j) {
                    num++;
                }
            }
        }
        return num;
    }
};

// @lc code=end

TEST(test_problem_200, testcase4)
{
    Solution_200 so;
    vector<vector<char>> grid = {
        {'1', '0', '1', '1', '1'},
        {'1', '0', '1', '0', '1'},
        {'1', '1', '1', '0', '1'}
    };
    int result = so.numIslands(grid);
    EXPECT_EQ(result, 1);
}

TEST(test_problem_200, testcase3)
{
    Solution_200 so;
    vector<vector<char>> grid = {
        {'1', '1', '0', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };
    int result = so.numIslands(grid);
    EXPECT_EQ(result, 3);
}

TEST(test_problem_200, testcase2)
{
    Solution_200 so;
    vector<vector<char>> grid = {{'0'}};
    int result = so.numIslands(grid);
    EXPECT_EQ(result, 0);
}

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
    EXPECT_EQ(result, 1);
    ;
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
    EXPECT_EQ(result, 3);
}

#endif /*_LEETCODE_NUMS_200_NUM_ISLANDS_H_*/
