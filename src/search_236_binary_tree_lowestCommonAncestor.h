#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start

class Solution {
public:
    bool recursion(TreeNode* root, TreeNode* target, stack<TreeNode*>stk) {
        if (root == NULL) {
            return false;
        }
        if (root == target) {
            stk.push(root);
            return true;
        }
        if (recursion(root->left, target, stk)) {
            stk.push(root);
            return true;
        }
        if (recursion(root->right, target, stk)) {
            stk.push(root);
            return true;
        }
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pStk;
        stack<TreeNode*> qStk;
        recursion(root, p, pStk);
        recursion(root, q, qStk);
        TreeNode* before = pStk.top();
        while (!pStk.empty() &&  !qStk.empty()) {
            if (pStk.top() == qStk.top()) {
                before = pStk.top();
                pStk.pop();
                qStk.pop();
            } else {
                return before;
            }
        }
        return before;
    }
};
// @lc code=end


TEST(test_problem_236, testcase0)
{
    Solution so;
    vector<int> nums = {3,5,1,6,2,0,8,NODE_NULL,NODE_NULL,7,4};
    TreeNode* root = LeetcodeCreateTreeByVectorInt(nums);

    // EXPECT_EQ(result[2],exceptResult[2]);
}
