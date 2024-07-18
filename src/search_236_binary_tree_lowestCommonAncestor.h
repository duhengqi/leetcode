#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=236 lang=cpp
 *
 * [236] 二叉树的最近公共祖先
 */

// @lc code=start

/**
 * 将二叉树看成完全二叉树，找到p,q在这棵树的索引,
 * 然后可以分别计算出p,q所有父节点的所有，找到最近的父节点索引，然后取出来
 * 完成二叉树，理解为[0, 1,2,  3,4,5,6, ...]
 * 待实现
*/

/**
 * 判定最近公共祖先条件
 * 二选一：左子树包含q，右子树包含p；     当前节点等于q，孩子中包含p
 * 问题：为什么result往前回溯不会被覆盖
*/
class Solution_236 {
public:
    TreeNode* result;
    bool recursion(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) {
            return false;
        }
        bool lson = recursion(root->left, p, q);
        bool rson = recursion(root->right, p, q);
        if (lson && rson) {
            result = root;
        }
        if (root == p && (lson || rson)) {
            result = root;
        }
        if (root == q && (lson || rson)) {
            result = root;
        }

        return (root== q || root == p || lson || rson);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recursion(root, p, q);
        return result;
    }
};

/**
 * 递归 + 双栈
 * 递归查找target，找到后将target及target的parent 加入栈中
 * 将p,q的parent加入栈后，依次比较
*/
class Solution_236_recursion_two_stack {
public:
    bool recursion(TreeNode* root, TreeNode* target, stack<TreeNode*>& stk) {
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
