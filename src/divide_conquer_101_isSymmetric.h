#ifndef _LEETCODE_NUMS_101_IS_SYMMETRIC_H
#define _LEETCODE_NUMS_101_IS_SYMMETRIC_H

#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 * 给你一个二叉树的根节点 root ， 检查它是否轴对称。
 */

// @lc code=start

class Solution_101 {
public:
    bool isSymmetricRecursion(queue<TreeNode*>& left,queue<TreeNode*>&right){
        if (left.size() != right.size()) {
            return false;
        }
        if (left.empty() && right.empty()) {
            return true;
        }
        if (left.front() == nullptr && right.front() == nullptr) {
            left.pop();
            right.pop();
            return isSymmetricRecursion(left,right);
        } else if (left.front() != nullptr && right.front() != nullptr) {
            if (left.front()->val == right.front()->val) {
                left.push(left.front()->left);
                left.push(left.front()->right);
                right.push(right.front()->right);
                right.push(right.front()->left);
                left.pop();
                right.pop();
                return isSymmetricRecursion(left,right);
            } else {
                return false;
            }
        } else {
            return false;
        }

    }
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> left;
        queue<TreeNode*> right;
        left.push(root->left);
        right.push(root->right);
        return isSymmetricRecursion(left,right);
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_101_IS_SYMMETRIC_H*/