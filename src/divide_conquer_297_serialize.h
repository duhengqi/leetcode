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

    void CodecLevelOrder(TreeNode* root, string& result) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> queL;
        queL.push(root);
        result += to_string(root->val);
        result += ",";
        int levelIndex;
        while(!queL.empty()) {
            string str;
            levelIndex = queL.size();
            while(levelIndex) {
                TreeNode* node = queL.front();
                queL.pop();
                if (node->left) {
                    queL.push(node->left);
                    str += to_string(node->left->val);
                    str += ",";

                } else {
                    str += "null,";
                }
                if (node->right) {
                    queL.push(node->right);
                    str += to_string(node->right->val);
                    str += ",";
                } else {
                    str += "null,";
                }
                levelIndex--;
            }
            if (!str.empty()) {
                result += str;
            }
        }
        return;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string res;
        CodecLevelOrder(root, res);
        cout << res << endl;
        return res;
    }

    void CodecBuildNode(TreeNode* &node, string &str, string::size_type &start)
    {
        if(str[start] == 'n') {
            node->left = NULL;
            start += 5;
        } else {
            string::size_type posTmp = str.find(",", start);
            node->left = new TreeNode;
            node->left->val = atoi(str.substr(start, posTmp - start).c_str());
            start = posTmp + 1;
        }

        if(str[start] == 'n') {
            node->right = NULL;
            start += 5;
        } else {
            string::size_type posTmp = str.find(",", start);
            node->right = new TreeNode;
            node->right->val = atoi(str.substr(start, posTmp - start).c_str());
            start = posTmp + 1;
        }
    }

    TreeNode* CodecBuildTree(string &str) 
    {
        if(str.empty()) {
            return NULL;
        }
        TreeNode* root = new TreeNode;
        queue<TreeNode*> que;
        string::size_type start, end;
        string c = ",";
        end = str.find(c);
        cout <<"end pos: "<< end << endl;
        start = 0;
        root->val = atoi(str.substr(start, end - start).c_str());
        cout <<"root->val"<< root->val << endl;
        start = end + c.size();
        que.emplace(root);

        while(!que.empty() && start < str.size()) {
            TreeNode* node = que.front();
            que.pop();

            CodecBuildNode(node, str, start);

            if (node->left) {
                que.push(node->left);
            }
            if (node->right) {
                que.push(node->right);
            }
        }

        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return CodecBuildTree(data);
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
// @lc code=end

TEST(test_problem_297, testcase0)
{
    Codec so;
    TreeNode* root = new TreeNode;
    root->val = 1;
    root->left = new TreeNode;
    root->right = new TreeNode;
    root->left->val = 2;
    root->right->val = 3;
    root->right->left = new TreeNode;
    root->right->right = new TreeNode;
    root->right->left->val = 4;
    root->right->right->val = 5;
    string str = so.serialize(root);
    cout << str << endl;
}

#endif /*_LEETCODE_NUMS_297_SERIALIZE_H*/
