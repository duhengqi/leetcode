#ifndef _LEETCODE_BINARY_TREE_H_
#define _LEETCODE_BINARY_TREE_H_

#include <iostream>
#include <queue>
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

class LeetCodeBinaryTree {
public:
    void CreateTreeByString_BuildNode(TreeNode *&node, string &str, string::size_type &start)
    {
        if (str[start] == 'n') {
            node->left = NULL;
            start += 5;
        } else {
            string::size_type posTmp = str.find(",", start);
            node->left = new TreeNode;
            node->left->val = atoi(str.substr(start, posTmp - start).c_str());
            start = posTmp + 1;
        }

        if (str[start] == 'n') {
            node->right = NULL;
            start += 5;
        } else {
            string::size_type posTmp = str.find(",", start);
            node->right = new TreeNode;
            node->right->val = atoi(str.substr(start, posTmp - start).c_str());
            start = posTmp + 1;
        }
    }

    // strCase0 = "0,2,4,1,null,3,-1,5,1,null,6,null,8"
    TreeNode *CreateTreeByString(string &str)
    {
        if (str.empty()) {
            return NULL;
        }
        TreeNode *root;
        queue<TreeNode *> que;
        string::size_type start, end;
        string c = ",";

        start = 0;
        end = str.find(c);

        root = new TreeNode;
        root->val = atoi(str.substr(start, end - start).c_str());
        start = end + c.size();
        que.emplace(root);

        while (!que.empty() && start < str.size()) {
            TreeNode *node = que.front();
            que.pop();

            CreateTreeByString_BuildNode(node, str, start);

            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }

        return root;
    }

/**
 * 根据 数组nums 创建二叉树，假定数组不使用数字-1，-1表示null，空节点
 */
#define NODE_NULL (0xFFFFFF)

    TreeNode *CreateTreeByVectorInt(vector<int> nums)
    {
        if (nums.size() == 0) {
            return nullptr;
        }
        int index = 0;
        TreeNode *root;
        queue<TreeNode *> treeQue;

        root = new TreeNode;
        root->val = nums[index];
        index++;
        treeQue.push(root);

        while(!treeQue.empty() && index < nums.size()) {
            TreeNode *node = treeQue.front();
            treeQue.pop();
            if(nums[index] != NODE_NULL) {
                node->left = new TreeNode;
                node->left->val = nums[index];
                treeQue.push(node->left);
                index++;
            } else {
                index++;
            }
            
            if(nums[index] != NODE_NULL) {
                node->right = new TreeNode;
                node->right->val = nums[index];
                treeQue.push(node->right);
                index++;
            } else {
                index++;
            }
        }

        return root;
    }

};

TEST(test_leetcode_binary_tree, testcase0)
{
    // {3, 9, 20, null, null, 15, 7};
    vector<int> nums = {3, 9, 20, NODE_NULL, NODE_NULL, 15, 7};
    LeetCodeBinaryTree so;
    struct TreeNode *root = so.CreateTreeByVectorInt(nums);
    EXPECT_EQ(0, 0);
}

#endif /* _LEETCODE_BINARY_TREE_H_ */