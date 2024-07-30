#ifndef _LEETCODE_NUMS_105_BUILD_TREE_H
#define _LEETCODE_NUMS_105_BUILD_TREE_H

#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

// @lc code=start

class Solution {
public:
    TreeNode* buildTreeRecursion(vector<int>& preorder, int pStart, int pEnd, vector<int>& inorder, int iStart, int iEnd) {
        if(pEnd < pStart) {
            return nullptr;
        }
        TreeNode *root = new (TreeNode);
        root->val = preorder[pStart];
        int len = 0;
        for (int i = iStart; i <= iEnd; i++, len++) {
            if (inorder[i] == preorder[pStart]) {
                root->left = buildTreeRecursion(preorder, pStart+1, pStart+len, inorder, iStart, i-1);
                root->right = buildTreeRecursion(preorder, pStart+1+len, pEnd, inorder, i+1, iEnd);
            }
        }
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int pStart = 0;
        int pEnd = preorder.size()-1;
        int iStart = 0;
        int iEnd = inorder.size()-1;
        return buildTreeRecursion(preorder, pStart, pEnd, inorder, iStart, iEnd);
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_105_BUILD_TREE_H*/
