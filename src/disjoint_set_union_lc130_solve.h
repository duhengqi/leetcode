#ifndef _LEETCODE_NUMS_130_SOLVE_H_
#define _LEETCODE_NUMS_130_SOLVE_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 * 给你一个 m x n 的矩阵 board ，由若干字符 'X' 和 'O' 组成，捕获 所有 被围绕的区域：
 * 连接：一个单元格与水平或垂直方向上相邻的单元格连接。
 * 区域：连接所有 'O' 的单元格来形成一个区域。
 * 围绕：如果您可以用 'X' 单元格 连接这个区域，并且区域中没有任何单元格位于 board 边缘，则该区域被 'X' 单元格围绕。
 * 通过将输入矩阵 board 中的所有 'O' 替换为 'X' 来 捕获被围绕的区域。
 *
 * 示例 1：
 * 输入：board = [
 * ["X","X","X","X"],
 * ["X","O","O","X"],
 * ["X","X","O","X"],
 * ["X","O","X","X"]]
 * 输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 * 解释：
 * 在上图中，底部的区域没有被捕获，因为它在 board 的边缘并且不能被围绕。

 * 示例 2：
 * 输入：board = [["X"]]
 * 输出：[["X"]]
 *
 * 提示：
 * m == board.length
 * n == board[i].length
 * 1 <= m, n <= 200
 * board[i][j] 为 'X' 或 'O'
 */

// @lc code=start
class Solution_130 {
public:
    int find(vector<int>& father, int x){
        if (x == -1) {
            return -1;
        } else if (father[x] == x) {
            return x;
        } else {
            return father[x] = find(father, father[x]);
        }
    }
    void  merge(vector<int>& father, int i, int j){
        int x = find(father,i);
        int y = find(father,j);
        if (x == -1 && y == -1) {
            return;
        } else if (x == -1) {
            father[y] = -1;
        } else if (y == -1) {
            father[x] = -1;
        } else if (x < y) {
            father[y] = x;
        } else {
            father[x] = y;
        }
    }
    void solve(vector<vector<char>>& board) {
        int row = board.size();
        int col = board[0].size();
        vector<int> father(row*col,-1);
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (board[i][j] == 'X') {
                    continue;
                }
                if (i == row - 1 || j == col - 1) {
                    father[i * col + j] = -1;
                    if (board[i-1][j] == 'O') {
                        int x = find(father,(i-1)*col+j);
                        if (x != -1) {
                            father[x] = -1;
                        }
                    }
                    if (board[i][j-1] == 'O') {
                        int x = find(father, i*col+j - 1);
                        if (x != -1) {
                            father[x] = -1;
                        }
                    }
                    continue;
                }

                if (board[i-1][j] == 'O' && board[i][j-1] == 'O') {
                    merge(father, (i - 1) * col + j, i * col + j - 1);
                    father[i * col + j] = find(father, (i - 1) * col + j);
                } else if (board[i-1][j] == 'O') {
                    father[i * col + j] = find(father, (i - 1) * col + j);
                } else if (board[i][j-1] == 'O') {
                    father[i * col + j] = find(father, i * col + j - 1);
                } else {
                    father[i * col + j] = i * col + j;
                }
            }
        }
        for (int i = 1; i < row; i++) {
            for (int j = 1; j < col; j++) {
                if (board[i][j] == 'X') {
                    continue;
                }
                if (find(father,i * col + j) != -1) {
                    board[i][j] = 'X';
                }
            }
        }     
    }
};

// @lc code=end

TEST(test_problem_130, testcase1)
{
    Solution_130 so;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    so.solve(board);
}

TEST(test_problem_130, testcase0)
{
    Solution_130 so;
    vector<vector<char>> board = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'X', 'O', 'X', 'X'}
    };
    so.solve(board);
}


#endif /*_LEETCODE_NUMS_130_SOLVE_H_*/
