#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

// @lc code=start

/**
 * 循环解法
*/
class Solution_145_loop_stack {
public:
    vector<int> postorderTraversal(TreeNode* root) {

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
    Solution_145_recursion so;
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10};
    TreeNode* root = LeetcodeCreateTreeByVectorInt(nums);
    vector<int> result = so.postorderTraversal(root);
    vector<int> exceptResult = {7,8,3,9,10,4,1,5,6,2,0};
    EXPECT_EQ(result,exceptResult);

}
