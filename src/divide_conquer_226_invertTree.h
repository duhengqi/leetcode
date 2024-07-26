#ifndef _LEETCODE_NUMS_226_INVERT_TREE_H
#define _LEETCODE_NUMS_226_INVERT_TREE_H

#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=226 lang=cpp
 *
 * [226] 翻转二叉树
 * 给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
 */

// @lc code=start

class Solution_226 {
public:
    void invertTreeRecursion(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        TreeNode* node = root->right;
        root->right = root->left;
        root->left = node;
        invertTreeRecursion(root->right);
        invertTreeRecursion(root->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        invertTreeRecursion(root);
        return root;
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_226_INVERT_TREE_H*/
