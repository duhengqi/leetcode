
#include "god.h"
#include "leetcode_binary_tree.h"
/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */

// @lc code=start

class Solution_104 {
public:
    int maxDepthRecursive(TreeNode* root){
        if (root == nullptr) {
            return 0;
        }
        int left = (maxDepthRecursive(root->left) + 1);
        int right = (maxDepthRecursive(root->right)+1);
        return (left > right) ? left : right;
    }
    int maxDepth(TreeNode* root) {
        
        return maxDepthRecursive(root);
    }
};

// @lc code=end

