#ifndef _LEETCODE_NUMS_297_SERIALIZE_H
#define _LEETCODE_NUMS_297_SERIALIZE_H

#include "god.h"
#include "leetcode_binary_tree.h"

/*
 * @lc app=leetcode.cn id=297 lang=cpp
 *
 * [297] 二叉树的序列化与反序列化
 * 序列化是将一个数据结构或者对象转换为连续的比特位的操作，进而可以将转换后的数据存储在一个文件或者内存中，同时也可以通过网络传输到另一个计算机环境，采取相反方式重构得到原数据。
 * 请设计一个算法来实现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
 * 提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。
 * 
 * 示例 1：
 * 输入：root = [1,2,3,null,null,4,5]
 * 输出：[1,2,3,null,null,4,5]
 * 
 * 示例 2：
 * 输入：root = []
 * 输出：[]
 * 
 * 示例 3：
 * 输入：root = [1] 输出：[1]
 * 
 * 示例 4：
 * 输入：root = [1,2] 输出：[1,2]
 * 
 * 提示：
 * 树中结点数在范围 [0, 104] 内
 * -1000 <= Node.val <= 1000
 */

// @lc code=start

class Codec {
public:

    void CodecSplitString(const string& s, vector<int>& v, const string& c)
    {
      string::size_type pos1, pos2;
      pos2 = s.find(c);
      pos1 = 0;
      while(string::npos != pos2)
      {
        v.push_back(atoi(s.substr(pos1, pos2-pos1).c_str()));
    
        pos1 = pos2 + c.size();
        pos2 = s.find(c, pos1);
      }
      if(pos1 != s.length())
        v.push_back(atoi(s.substr(pos1).c_str()));
    }

    void CodecRecursion(TreeNode* root, string &res, bool isPreOrder){
        if (root == nullptr) {
            return;
        }
        if (isPreOrder) {
            res += to_string(root->val);
            res += ' ';
            CodecRecursion(root->left, res, isPreOrder);
        } else {
            CodecRecursion(root->left, res, isPreOrder);
            res += to_string(root->val);
            res += ' ';
        }
        CodecRecursion(root->right, res, isPreOrder);
    }
    
    TreeNode* CodecBuildTree(vector<int>& preorder, vector<int>& inorder)
    {
        int preIndex = 0;
        int inIndex = 0;
        bool isRightNode = false;
        map<int, TreeNode*> mapNode;
        map<int, TreeNode*>::iterator iter;

        TreeNode* Root = new TreeNode;
        Root->val = preorder[0];
        mapNode[preorder[0]] = Root;
        TreeNode* curTreeRoot = Root;
        preIndex++;

        while (inIndex < inorder.size() && preIndex < preorder.size()) {
            iter = mapNode.find(inorder[inIndex]);
            if (iter == mapNode.end()) {
                while (preorder[preIndex] != inorder[inIndex]) {
                    TreeNode* node = new TreeNode;
                    node->val = preorder[preIndex];
                    mapNode[node->val] = node;
                    if (isRightNode) {
                        curTreeRoot->right = node;
                        isRightNode = false;
                    } else {
                        curTreeRoot->left = node;
                    }
                    curTreeRoot = node;
                    preIndex++;
                }
                TreeNode* node = new TreeNode;
                node->val = preorder[preIndex];
                mapNode[node->val] = node;
                if (isRightNode) {
                    curTreeRoot->right = node;
                    isRightNode = false;
                } else {
                    curTreeRoot->left = node;
                }
                curTreeRoot = node;
                preIndex++;
                inIndex++;
                if (inIndex < inorder.size() && preIndex < preorder.size() && preorder[preIndex] == preorder[preIndex])
                {
                    isRightNode = true;
                }
            } else {
                curTreeRoot = iter->second;
                inIndex++;
                isRightNode = true;
            }
        }
        return Root;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        CodecRecursion(root, res, true);
        res += ',';
        CodecRecursion(root, res, false);
        cout << res << endl;
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<int> preOrder;
        vector<int> inOrder;
        int endPos = 0;
        for (endPos = 0; endPos < data.size();endPos++) {
            if (data[endPos] == ',') {
                break;
            }
        }
        string pre(data, 0, endPos-1);
        string in(data, endPos+1);
        CodecSplitString(pre, preOrder, " ");
        CodecSplitString(in, inOrder, " ");
        for (int i = 0; i < preOrder.size();i++) {
            cout << preOrder[i] << endl;
        }
        for (int i = 0; i < inOrder.size();i++) {
            cout << inOrder[i] << endl;
        }
        return CodecBuildTree(preOrder, inOrder);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

#endif /*_LEETCODE_NUMS_297_SERIALIZE_H*/
