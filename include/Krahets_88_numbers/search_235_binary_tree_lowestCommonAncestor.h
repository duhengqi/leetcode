#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=235 lang=cpp
 *
 * [235] 二叉搜索树的最近公共祖先
 */

// @lc code=start

/**
 * 二叉搜索树最近公共祖先必然满足以下两个条件之一
 * 1，最近的公共祖先节点使得，p在左，q在右或者相反，即 root->val < p->val && root->val > q->val
 * 2，p是q的祖先，或者相反
 * 
 * 或者相反的逻辑
 * 只有p,q不是同时在一侧的节点，当前节点及最近的公共最先
*/
class Solution_235_recursion {
public:
    TreeNode* result;
    void recursion(TreeNode* root, TreeNode* p, TreeNode* q) {
       if (root == NULL) {
            return;
        }
        if ((root->val < p->val && root->val > q->val )
        ||(root->val > p->val && root->val < q->val )) {
            result = root;
            return;
        }
        if (root == p) {
            result = p;
            return;
        }
        if (root == q) {
            result = q;
            return;
        }
        if (root->val < p->val) {
            recursion(root->right, p, q);
        } else {
            recursion(root->left, p, q);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        recursion(root, p, q);
        return result;
    }
};


/**
 * 给定一个二叉搜索树, 找到该树中两个指定节点的最近公共祖先。
 * 百度百科中最近公共祖先的定义为：
 * “对于有根树 T 的两个结点 p、q，最近公共祖先表示为一个结点 x，满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”
 * 判定最近公共祖先条件
 * 二选一：左子树包含q，右子树包含p；     当前节点等于q，孩子中包含p
 * 问题：为什么result往前回溯不会被覆盖
*/
class Solution_235_generic {
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
class Solution_235_recursion_two_stack {
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
