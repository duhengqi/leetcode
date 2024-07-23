#ifndef _LEETCODE_NUMS_237_DELETENODE_H
#define _LEETCODE_NUMS_237_DELETENODE_H

#include "god.h"
#include "leetcode_list.h"

/*
 * @lc app=leetcode.cn id=237 lang=cpp
 *
 * [237] 删除链表中的节点
 * https://leetcode.cn/problems/delete-node-in-a-linked-list/description
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution_237 {
public:
    void deleteNode(ListNode* node) {
        ListNode *next = node->next;
        node->val = next->val;
        node->next = next->next;
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_237_DELETENODE_H*/
