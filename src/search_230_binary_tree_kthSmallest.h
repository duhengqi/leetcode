#include "god.h"
#include "leetcode_binary_tree.h"
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
 */

// @lc code=start

/**
 * 二分搜索树（英语：Binary Search Tree），也称为 二叉查找树 、二叉搜索树 、有序二叉树或排序二叉树。
 * 满足以下几个条件：
 * 若它的左子树不为空，左子树上所有节点的值都小于它的根节点。
 * 若它的右子树不为空，右子树上所有的节点的值都大于它的根节点。
*/
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {

    }
};
// @lc code=end


TEST(test_problem_230, testcase0)
{
    Solution so;
    vector<int> nums = {3, 9, 20, NODE_NULL, NODE_NULL, 15, 7};
    TreeNode* root = LeetcodeCreateTreeByVectorInt(nums);
    int result = so.kthSmallest(root,3);
    // EXPECT_EQ(result[0],exceptResult[0]);

}
