#ifdef  _LEETCODE_BINARY_TREE_H_
#define _LEETCODE_BINARY_TREE_H_

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#endif /* _LEETCODE_BINARY_TREE_H_ */