#ifndef _LEETCODE_NUMS_107_LEVEL_ORDER_BOTTOM_H
#define _LEETCODE_NUMS_107_LEVEL_ORDER_BOTTOM_H

#include "god.h"
#include "leetcode_binary_tree.h"
/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层序遍历 II
 * 给你二叉树的根节点 root ，返回其节点值 自底向上的层序遍历 。 
 * （即按从叶子节点所在层到根节点所在的层，逐层从左向右遍历）
 * 
 * 示例 1：
 * 输入：root = [3,9,20,null,null,15,7]    输出：[[15,7],[9,20],[3]]
 * 
 * 示例 2：
 * 输入：root = [1] 输出：[[1]]
 * 
 * 示例 3：
 * 输入：root = []   输出：[]
 *  
 * 提示：
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
 */

// @lc code=start

class Solution {
public:

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> queL;
        stack<int> stk;
        stack<int> stkSize;
        vector<vector<int>> result;
        int levelIndex;

        queL.push(root);
        stk.push(root->val);
        while(!queL.empty()) {
            levelIndex = queL.size();
            stkSize.push(levelIndex);
            while(levelIndex) {
                TreeNode* node = queL.front();
                queL.pop();
                if (node->right) {
                    queL.push(node->right);
                    stk.push(node->right->val);
                }
                if (node->left) {
                    queL.push(node->left);
                    stk.push(node->left->val);
                }
                levelIndex--;
            }
        }
        while(!stkSize.empty()) {
            levelIndex = stkSize.top();
            stkSize.pop();
            vector<int> vct;
            while(levelIndex) {
                vct.push_back(stk.top());
                stk.pop();
                levelIndex--;
            }
            result.push_back(vct);
        }
        return result;
    }

};
// @lc code=end

#endif /*_LEETCODE_NUMS_107_LEVEL_ORDER_BOTTOM_H*/
