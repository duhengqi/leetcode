#ifndef _LEETCODE_NUMS_105_BUILD_TREE_H
#define _LEETCODE_NUMS_105_BUILD_TREE_H

#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 * 给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历，
 * inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。
 * 示例 1:
 * 输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 输出: [3,9,20,null,null,15,7]
 * 
 * 示例 2:
 * 输入: preorder = [-1], inorder = [-1]
 * 输出: [-1]

 * 提示:
 * 1 <= preorder.length <= 3000
 * inorder.length == preorder.length
 * -3000 <= preorder[i], inorder[i] <= 3000
 * preorder 和 inorder 均 无重复 元素
 * inorder 均出现在 preorder
 * preorder 保证 为二叉树的前序遍历序列
 * inorder 保证 为二叉树的中序遍历序列
 */

// @lc code=start

class Solution_105 {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIndex = 0;
        int inIndex = 0;
        bool isBackNode = false;
        map<int, TreeNode*> mapNode;
        map<int, TreeNode*>::iterator iter;

        TreeNode* Root = new TreeNode;
        Root->val = preorder[0];
        mapNode[preorder[0]] = Root;
        TreeNode* curTreeRoot = Root;
        preIndex++;
    
        while (inIndex < inorder.size()) {
            iter = mapNode.find(inorder[inIndex]);
            if (iter != mapNode.end()) {
                while (preorder[preIndex] != inorder[inIndex]) {
                    TreeNode* node = new TreeNode;
                    node->val = preorder[preIndex];
                    if (isBackNode) {
                        curTreeRoot->right = node;
                        isBackNode = false;
                    } else {
                        curTreeRoot->left = node;
                    }
                    curTreeRoot = node;
                    preIndex++;

                }
                TreeNode* node = new TreeNode;
                node->val = preorder[preIndex];
                if (isBackNode) {
                    curTreeRoot->right = node;
                    isBackNode = false;
                } else {
                    curTreeRoot->left = node;
                }
                curTreeRoot = node;
                preIndex++;

                inIndex++;
            } else {
                curTreeRoot = iter->second;
                inIndex++;
                isBackNode = true;
            }
        }
        return Root;
    }
};

class Solution_105_recursion {
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
