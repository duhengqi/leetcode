#ifndef  _LEETCODE_BINARY_TREE_H_
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
#define NODE_NULL (0xFFFFFF)

TreeNode* LeetcodeCreateTreeByVectorInt(vector<int> nums)
{
    if (nums.size() == 0) {
        return nullptr;
    }
    queue<TreeNode *> treeQue;
    TreeNode *root = new (struct TreeNode);
    root->val = nums[0];
    treeQue.push(root);
    int index = 0;
    while(index < nums.size()) {
        if (treeQue.empty()) {
            break;
        }
        TreeNode *node = treeQue.front();
        treeQue.pop();
        if (node == nullptr) {
            treeQue.push(nullptr);
            treeQue.push(nullptr);
            index++;
            continue;
        }
        if (index*2+1 < nums.size()) {
            if (nums[index*2+1] == NODE_NULL) {
                treeQue.push(nullptr);
            } else {
                node->left = new (struct TreeNode);
                node->left->val = nums[index * 2 + 1];
                treeQue.push(node->left);
            }
        } else {
            break;
        }
        if (index*2+2 < nums.size()) {
            if (nums[index*2+2] == NODE_NULL) {
                treeQue.push(nullptr);
            } else {
                node->right = new (struct TreeNode);
                node->right->val = nums[index * 2 + 2];
                treeQue.push(node->right);
            }
        } else {
            break;
        }
        index++;
    }
    return root;
}

// [0,2,4,1,null,3,-1,5,1,null,6,null,8]
struct TreeNode* LeetcodeCreateTreeByVectorString(vector<string> nums)
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
    vector<int> nums = {3, 9, 20, NODE_NULL, NODE_NULL, 15, 7};
    struct TreeNode *root = LeetcodeCreateTreeByVectorInt(nums);
    EXPECT_EQ(0, 0);
}


#endif /* _LEETCODE_BINARY_TREE_H_ */