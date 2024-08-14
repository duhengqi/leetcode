#ifndef _LEETCODE_NUMS_64_MIN_PATH_SUM_H_
#define _LEETCODE_NUMS_64_MIN_PATH_SUM_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */

// @lc code=start
class Solution_64 {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int row = grid.size();
        int col =  grid[0].size();
        vector<vector<int>> dp(row,vector<int>(col));
        dp[0][0] = grid[0][0];
        for (int i = 1; i < col;i++) {
            dp[0][i] = grid[0][i] + dp[0][i-1];
        }
        for (int i = 1; i < row;i++) {
            dp[i][0] = grid[i][0] + dp[i-1][0];
        }
        for (int i = 1; i < row;i++) {
            for (int j = 1; j < col;j++) {
                dp[i][j] = grid[i][j] + (dp[i][j-1]>dp[i-1][j]?dp[i-1][j]:dp[i][j-1]);
            }
        }
        return dp[row-1][col-1];
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_64_MIN_PATH_SUM_H_*/
