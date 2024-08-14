#ifndef _LEETCODE_NUMS_113_PATHSUM_H
#define _LEETCODE_NUMS_113_PATHSUM_H

#include "god.h"
#include "leetcode_binary_tree.h"
/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */

// @lc code=start

class Solution_113 {
public:
    void pathSumRecursive(TreeNode* root, int targetSum, vector<vector<int>>& result, vector<int> path, int sum)
    {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        sum += root->val;
        if (sum == targetSum && root->left == nullptr && root->right==nullptr) {
            result.push_back(path);
            return;
        }
        pathSumRecursive(root->left, targetSum, result, path, sum);
        pathSumRecursive(root->right, targetSum, result, path, sum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> result;
        vector<int> path;
        int sum = 0;
        pathSumRecursive(root, targetSum, result, path, sum);

        return result;
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_113_PATHSUM_H*/
