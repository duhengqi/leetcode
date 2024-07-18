#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start

/**
 * 循环解法
*/

class Solution {
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

        // before上一个取出的节点，插入节点时，before置nullptr
        TreeNode* before = nullptr;
        while(!stk.empty()) {
            TreeNode* node = stk.top();
            stk.pop();
            if (node->left == nullptr && node->right == nullptr) {
                result.push_back(node->val);
                before = node;
                continue;
            }

            // 判断 node是否是未入队的右节点 方法：上个取出的节点的右子节点等于node
            // 判断 node是否是未入队的左节点  方法：before== null
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
// @lc code=end



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
    Solution_94_recursion so;
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10};
    TreeNode* root = LeetcodeCreateTreeByVectorInt(nums);
    vector<int> result = so.inorderTraversal(root);
    vector<int> exceptResult = {7,3,8,1,9,4,10,0,5,2,6};
    EXPECT_EQ(result,exceptResult);

}
