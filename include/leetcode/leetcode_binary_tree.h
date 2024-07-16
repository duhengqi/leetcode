#ifdef  _LEETCODE_BINARY_TREE_H_
#define _LEETCODE_BINARY_TREE_H_

#include <iostream>
#include <vector>
#include "gtest.h"

using namespace std;

typedef struct TreeNode TreeNode;
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 根据 数组nums 创建二叉树，假定数组不使用数字-1，-1表示null，空节点
*/
struct TreeNode* LeetcodeCreateTreeByVector(vector<int> nums)
{
    if (nums.size() == 0) {
        return nullptr;
    }

    struct TreeNode *root = new (struct TreeNode);
    cout << root->val << endl;
    if (root->left == nullptr) {
        cout << "left null" << endl;
    }

    return root;
}

TEST(test_leetcode_binary_tree, testcase0)
{
    // {3, 9, 20, null, null, 15, 7};
    vector<int> nums = {3, 9, 20, -1, -1, 15, 7};
    struct TreeNode *root = LeetcodeCreateTreeByVector(nums);
    EXPECT_EQ(0, 0);
}


#endif /* _LEETCODE_BINARY_TREE_H_ */