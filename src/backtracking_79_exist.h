#ifndef _LEETCODE_NUMS_79_ISEXIST_H
#define _LEETCODE_NUMS_79_ISEXIST_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 * Category	Difficulty	Likes	Dislikes
 * algorithms	Medium (46.25%)	1635	-
 * Tags array | backtracking
 * 
 * 给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 示例 1：
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
 * 输出：true
 *  示例 2：
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
 * 输出：true
 * 示例 3：
 * 输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
 * 输出：false
 * 提示：
 * m == board.length
 * n = board[i].length
 * 1 <= m, n <= 6
 * 1 <= word.length <= 15
 * board 和 word 仅由大小写英文字母组成
 * 进阶：你可以使用搜索剪枝的技术来优化解决方案，使其在 board 更大的情况下可以更快解决问题？
 */

// @lc code=start

class Solution_79 {
public:
    bool existRecursion(vector<vector<char>>& board, vector<vector<bool>> &visited, string& word, int i, int j, int index){
        if(index == word.size()) {
            return true;
        }
        visited[i][j] = true;
        if (i - 1 >= 0 && board[i-1][j] == word[index] && visited[i-1][j] ==false && existRecursion(board, visited, word, i-1, j, index+1)) {
            return true;
        }
        
        if (i + 1 < board.size() && board[i+1][j] == word[index] && visited[i+1][j]== false && existRecursion(board, visited, word, i+1, j, index+1)) {
            return true;
        }
        if (j - 1 >= 0 && board[i][j-1] == word[index] && visited[i][j-1] == false && existRecursion(board, visited, word, i, j-1, index+1)) {
            return true;
        }
        if (j + 1 < board[i].size() && board[i][j+1] == word[index] && visited[i][j+1] == false && existRecursion(board, visited, word, i, j+1, index+1)) {
            return true;
        }
        visited[i][j] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> visited(board.size(),vector<bool>(board[0].size(),false));
        for (int i = 0; i < board.size();i++) {
            for (int j = 0; j < board[i].size();j++) {
                if (board[i][j]==word[0]) {
                    if (existRecursion(board, visited, word, i,j,1) == true) {
                        return true;
                    }

                }
            }
        }

        return false;
    }
};
// @lc code=end

TEST(test_problem_79, testcase4)
{
    Solution_79 so;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','E','S'},{'A','D','E','E'}};
    string word = "ABCESEEEFS";
    bool result = so.exist(board,word);
    EXPECT_EQ(result,true);
}

TEST(test_problem_79, testcase0)
{
    Solution_79 so;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCCED";
    bool result = so.exist(board,word);
    EXPECT_EQ(result,true);
}

TEST(test_problem_79, testcase1)
{
    Solution_79 so;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "SEE";
    bool result = so.exist(board,word);
    EXPECT_EQ(result,true);
}

TEST(test_problem_79, testcase2)
{
    Solution_79 so;
    vector<vector<char>> board = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
    string word = "ABCB";
    bool result = so.exist(board,word);
    EXPECT_EQ(result,false);
}

TEST(test_problem_79, testcase3)
{
    Solution_79 so;
    vector<vector<char>> board = {{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'},{'A','A','A','A','A','A'}};
    string word = "AAAAAAAAAAAAAAB";
    bool result = so.exist(board,word);
    EXPECT_EQ(result,false);
}


#endif /*_LEETCODE_NUMS_79_ISEXIST_H*/
