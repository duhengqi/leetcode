#include "god.h"
#include "leetcode_binary_tree.h"
/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 * 给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。
 * 示例 1：
 * 输入：root = [3,9,20,null,null,15,7]  输出：[[3],[9,20],[15,7]]
 * 示例 2：
 * 输入：root = [1]   输出：[[1]]
 * 示例 3：
 * 输入：root = []   输出：[]
 * 
 * 提示：
 * 树中节点数目在范围 [0, 2000] 内
 * -1000 <= Node.val <= 1000
 */

// @lc code=start

/** 
 * 单队列 加 层索引
*/
class Solution_102_single_queue {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> queL;
        vector<vector<int>> result;
        queL.push(root);
        int levelIndex;
        while(!queL.empty()) {
            vector<int> vctL;
            levelIndex = queL.size();
            while(levelIndex) {
                TreeNode* node = queL.front();
                queL.pop();
                vctL.push_back(node->val);
                if (node->left) {
                    queL.push(node->left);
                }
                if (node->right) {
                    queL.push(node->right);
                }
                levelIndex--;
            }
            if (!vctL.empty()) {
                result.push_back(vctL);
            }
        }
        return result;
    }
};

/**
 * 题解：两个队列 解法，一层进一个队列
*/
class Solution_102_two_queue {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        queue<TreeNode*> queL;
        queue<TreeNode*> queR;
        vector<vector<int>> result;
        queL.push(root);
        while(!queL.empty() || !queR.empty()) {
            vector<int> vctL;
            while(!queL.empty()) {
                TreeNode* node = queL.front();
                queL.pop();
    
                vctL.push_back(node->val);
                if (node->left) {
                    queR.push(node->left);
                }
                if (node->right) {
                    queR.push(node->right);
                }
            }
            if (!vctL.empty()) {
                result.push_back(vctL);
            }
            vector<int> vctR;
            while(!queR.empty()) {
                TreeNode* node = queR.front();
                queR.pop();
    
                vctR.push_back(node->val);
                if (node->left) {
                    queL.push(node->left);
                }
                if (node->right) {
                    queL.push(node->right);
                }
            }
            if (!vctR.empty()) {
                result.push_back(vctR);
            }
        }
        return result;
    }
};

// @lc code=end

TEST(test_problem_102, testcase0)
{
    Solution_102_single_queue so;
    vector<int> nums = {3, 9, 20, NODE_NULL, NODE_NULL, 15, 7};
    LeetCodeBinaryTree lcTree;
    TreeNode *root = lcTree.CreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.levelOrder(root);
    vector<vector<int>> exceptResult = {{3},{9,20},{15,7}};
    EXPECT_EQ(result[0],exceptResult[0]);
    EXPECT_EQ(result[1],exceptResult[1]);
    EXPECT_EQ(result[2],exceptResult[2]);
}

TEST(test_problem_102, testcase1)
{
    Solution_102_single_queue so;
    vector<int> nums = {3, 9, 20, 4, 5, 15, 7};
    LeetCodeBinaryTree lcTree;
    TreeNode *root = lcTree.CreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.levelOrder(root);
    vector<vector<int>> exceptResult = {{3},{9,20},{4,5,15,7}};
    EXPECT_EQ(result[0],exceptResult[0]);
    EXPECT_EQ(result[1],exceptResult[1]);
    EXPECT_EQ(result[2],exceptResult[2]);
}

TEST(test_problem_102, testcase2)
{
    Solution_102_single_queue so;
    vector<int> nums = {3, 9, 20, NODE_NULL, 5, 15, 7};
    LeetCodeBinaryTree lcTree;
    TreeNode *root = lcTree.CreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.levelOrder(root);
    vector<vector<int>> exceptResult = {{3},{9,20},{5,15,7}};
    EXPECT_EQ(result[0],exceptResult[0]);
    EXPECT_EQ(result[1],exceptResult[1]);
    EXPECT_EQ(result[2],exceptResult[2]);
}

TEST(test_problem_102, testcase3)
{
    Solution_102_single_queue so;
    vector<int> nums = {3, 9, 20, 4, NODE_NULL, 15, 7};
    LeetCodeBinaryTree lcTree;
    TreeNode *root = lcTree.CreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.levelOrder(root);
    vector<vector<int>> exceptResult = {{3},{9,20},{4,15,7}};
    EXPECT_EQ(result[0],exceptResult[0]);
    EXPECT_EQ(result[1],exceptResult[1]);
    EXPECT_EQ(result[2],exceptResult[2]);
}

TEST(test_problem_102, testcase4)
{
    Solution_102_single_queue so;
    vector<int> nums = {3, 9, 20, 4, NODE_NULL, 15, 7};
    LeetCodeBinaryTree lcTree;
    TreeNode *root = lcTree.CreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.levelOrder(root);
    vector<vector<int>> exceptResult = {{3},{9,20},{4,15,7}};
    EXPECT_EQ(result[0],exceptResult[0]);
    EXPECT_EQ(result[1],exceptResult[1]);
    EXPECT_EQ(result[2],exceptResult[2]);
}

TEST(test_problem_102, testcase5)
{
    Solution_102_single_queue so;
    vector<int> nums = {3};
    LeetCodeBinaryTree lcTree;
    TreeNode *root = lcTree.CreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.levelOrder(root);
    vector<vector<int>> exceptResult = {{3}};
    EXPECT_EQ(result[0],exceptResult[0]);
}

TEST(test_problem_102, testcase6)
{
    Solution_102_single_queue so;
    vector<int> nums = {3, NODE_NULL, 20, 15, 7};
    LeetCodeBinaryTree lcTree;
    TreeNode *root = lcTree.CreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.levelOrder(root);
    vector<vector<int>> exceptResult = {{3},{20},{15,7}};
    EXPECT_EQ(result[0],exceptResult[0]);
    EXPECT_EQ(result[1],exceptResult[1]);
    EXPECT_EQ(result[2],exceptResult[2]);
}


TEST(test_problem_102, testcase7)
{
    Solution_102_single_queue so;
    vector<int> nums = {3, 9, NODE_NULL, 4, NODE_NULL, 15, 7};
    LeetCodeBinaryTree lcTree;
    TreeNode *root = lcTree.CreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.levelOrder(root);
    vector<vector<int>> exceptResult = {{3},{9},{4},{15,7}};
    EXPECT_EQ(result[0],exceptResult[0]);
    EXPECT_EQ(result[1],exceptResult[1]);
    EXPECT_EQ(result[2],exceptResult[2]);
    EXPECT_EQ(result[3],exceptResult[3]);
}