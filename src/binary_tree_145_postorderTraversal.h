#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start

/**
 * 循环解法 : 后序遍历
 * 问题：如何判断当前节点的子节点 已经放入stack中？
 * 判断条件：
 * 1，新增 before节点，含义是上一个取出的节点，如果上个动作时是插入节点，将before置为NULL。
 * 2，先将 root及root的子节点入栈，然后开始出栈
 * 3，出栈对node判断， 如果node为叶子节点，直接加入result，并before = node
 *    如果node子节点已经入栈，则before必等于node的子节点
*/
class Solution_145_loop_stack {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> result;
        stack<TreeNode*> stk;

        stk.push(root);
        if(root->right) {
            stk.push(root->right);
        }
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
            if ((before!= nullptr && node->left != nullptr && node->left == before) 
            || (before!= nullptr && node->right != nullptr && node->right == before)) {
                before = node;
                result.push_back(node->val);
                continue;
            }
            stk.push(node);
            if(node->right) {
                stk.push(node->right);
            }
            if(node->left) {
                stk.push(node->left);
            }
            before = nullptr;
        }

        return result;
    }
};

/**
 * 递归解法
*/
class Solution_145_recursion {
public:
    void recursion(TreeNode* root, vector<int> &result){
        if (root == nullptr) {
            return;
        }
        recursion(root->left, result);
        recursion(root->right, result);
        result.push_back(root->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        recursion(root, result);
        return result;
    }

};
// @lc code=end

TEST(test_problem_145, testcase0)
{
    Solution_145_loop_stack so;
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10};
    TreeNode* root = LeetcodeCreateTreeByVectorInt(nums);
    vector<int> result = so.postorderTraversal(root);
    vector<int> exceptResult = {7,8,3,9,10,4,1,5,6,2,0};
    EXPECT_EQ(result,exceptResult);

}
