#ifndef _LEETCODE_NUMS_103_ZIGZAGLEVELORDER_H
#define _LEETCODE_NUMS_103_ZIGZAGLEVELORDER_H

#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
 * 给你二叉树的根节点 root ，返回其节点值的 锯齿形层序遍历 。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
示例 1：
输入：root = [3,9,20,NODE_NULL,NODE_NULL,15,7] 输出：[[3],[20,9],[15,7]]
示例 2：
输入：root = [1] 输出：[[1]]
示例 3：
输入：root = [] 输出：[]

提示：
树中节点数目在范围 [0, 2000] 内
-100 <= Node.val <= 100
 */

// @lc code=start

class Solution_103 {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) {
            return {};
        }
        stack<TreeNode*> stkL;
        stack<TreeNode*> stkR;
        vector<vector<int>> result;
        stkL.push(root);
        while(!stkL.empty() || !stkR.empty()) {
            vector<int> vctL;
            while(!stkL.empty()) {
                TreeNode* node = stkL.top();
                stkL.pop();
                vctL.push_back(node->val);
                if (node->left) {
                    stkR.push(node->left);
                }
                if (node->right) {
                    stkR.push(node->right);
                }
            }
            if (!vctL.empty()) {
                result.push_back(vctL);
            }
            vector<int> vctR;
            while(!stkR.empty()) {
                TreeNode* node = stkR.top();
                stkR.pop();
                vctR.push_back(node->val);
                if (node->right) {
                    stkL.push(node->right);
                }
                if (node->left) {
                    stkL.push(node->left);
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

TEST(test_problem_103, testcase0)
{
    Solution_103 so;
    vector<int> nums = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    TreeNode* root = LeetcodeCreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.zigzagLevelOrder(root);
    vector<vector<int>> exceptResult = {{0},{2,1},{3,4,5,6},{14,13,12,11,10,9,8,7}};
    EXPECT_EQ(result[0],exceptResult[0]);
    EXPECT_EQ(result[1],exceptResult[1]);
    EXPECT_EQ(result[2],exceptResult[2]);
    EXPECT_EQ(result[3],exceptResult[3]);
}

TEST(test_problem_103, testcase1)
{
    Solution_103 so;
    vector<int> nums = {0,2,4,1,NODE_NULL,3,-1,5,1,NODE_NULL,6,NODE_NULL,8};
    TreeNode* root = LeetcodeCreateTreeByVectorInt(nums);
    vector<vector<int>> result = so.zigzagLevelOrder(root);
    vector<vector<int>> exceptResult = {{0},{4,2},{1,3,-1},{8,6,1,5}};
    EXPECT_EQ(result[0],exceptResult[0]);
    EXPECT_EQ(result[1],exceptResult[1]);
    EXPECT_EQ(result[2],exceptResult[2]);
    // EXPECT_EQ(result[3],exceptResult[3]);
}

#endif /*_LEETCODE_NUMS_103_ZIGZAGLEVELORDER_H*/
