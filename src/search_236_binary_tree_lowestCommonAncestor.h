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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
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
