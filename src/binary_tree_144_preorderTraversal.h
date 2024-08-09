#ifndef _LEETCODE_NUMS_144_PREORDERTRAVERSAL_H
#define _LEETCODE_NUMS_144_PREORDERTRAVERSAL_H

#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */

// @lc code=start
/**
 * 循环解法
*/
class Solution_144_loop_stack {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> result;
        stack<TreeNode*> stk;
        stk.push(root);
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            result.push_back(node->val);
            if(node->right) {
                stk.push(node->right);
            }
            if(node->left) {
                stk.push(node->left);
            }
        }
        return result;
    }
};

/**
 * 递归解法
*/
class Solution_144_recursion {
public:
    void recursion(TreeNode* root, vector<int> &result){
        if (root == nullptr) {
            return;
        }
        result.push_back(root->val);
        recursion(root->left, result);
        recursion(root->right, result);
    }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        recursion(root, result);
        return result;
    }
};
// @lc code=end

TEST(test_problem_144, testcase0)
{
    Solution_144_loop_stack so;
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10};
    LeetCodeBinaryTree lcTree;
    TreeNode *root = lcTree.CreateTreeByVectorInt(nums);
    vector<int> result = so.preorderTraversal(root);
    vector<int> exceptResult = {0,1,3,7,8,4,9,10,2,5,6};
    EXPECT_EQ(result,exceptResult);

}

#endif /*_LEETCODE_NUMS_144_PREORDERTRAVERSAL_H*/
