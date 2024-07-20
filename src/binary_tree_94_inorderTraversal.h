#ifndef _LEETCODE_NUMS_94_H
#define _LEETCODE_NUMS_94_H

#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

/**
 * 循环解法 : 中序遍历 不同与前序遍历，节点取出后不能直接放进vector，要左右子节点和当前节点重新放进stack
 * 问题：如何判断当前节点的子节点 已经放入stack中？
 * 判断条件：
 * 1，新增 before节点，含义是上一个取出的节点，如果上个动作时是插入节点，将before置为NULL。
 * 2，先将 root及root的子节点入栈，然后开始出栈
 * 3，出栈对node判断， 如果node为叶子节点，直接加入result，并before = node
 * 
 * 两种逻辑：
 * 1，node不为叶子节点时，如果能够判断node的左节点或者右节点在栈中， 则node可以直接出栈
 *
 * 2，node不为叶子节点时，如果能够判断node为刚插入的左节点或者右节点，则将node左右子节点入栈，否则node直接出栈
 * 
 * 判断 node是否是未入队的右节点 方法：上个取出的节点的右子节点等于node 
 * 判断 node是否是未入队的左节点  方法：before== null，且栈中节点是其父节点
*/

class Solution_94_loop_stack {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> result;
        stack<TreeNode*> stk;

        if(root->right) {
            stk.push(root->right);
        }
        stk.push(root);
        if(root->left) {
            stk.push(root->left);
        }
        TreeNode* before = nullptr;

        while(!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->left == nullptr && node->right == nullptr) {
                result.push_back(node->val);
                before = node;
                continue;
            }

            if ((before!= nullptr && node == before->right) 
            || (before== nullptr && !stk.empty() && node == stk.top()->left)) {
                if(node->right) {
                    stk.push(node->right);
                }
                stk.push(node);
                if(node->left) {
                    stk.push(node->left);
                }
                before = nullptr;
                continue;
            }
            before = node;
            result.push_back(node->val);
        }

        return result;
    }
};

/**
 * 递归解法
*/
class Solution_94_recursion {
public:
    void recursion(TreeNode* root, vector<int>& result) {
        if (root == nullptr) {
            return;
        }
        recursion(root->left, result);
        result.push_back(root->val);
        recursion(root->right, result);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> result;
        recursion(root, result);
        return result;
    }
};
// @lc code=end

TEST(test_problem_94, testcase0)
{
    Solution_94_loop_stack so;
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10};
    TreeNode* root = LeetcodeCreateTreeByVectorInt(nums);
    vector<int> result = so.inorderTraversal(root);
    vector<int> exceptResult = {7,3,8,1,9,4,10,0,5,2,6};
    EXPECT_EQ(result,exceptResult);

}

#endif /*_LEETCODE_NUMS_94_H*/
