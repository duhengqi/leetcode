#ifndef _LEETCODE_NUMS_206_REVERSELIST_H
#define _LEETCODE_NUMS_206_REVERSELIST_H

#include "god.h"
#include "leetcode_list.h"

/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 * https://leetcode.cn/problems/reverse-linked-list/description/
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution_206 {
public:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) {
            return nullptr;
        }

        ListNode *pre = head;
        ListNode *cur = head->next;
        pre->next = nullptr;
        while (cur != nullptr) {
            ListNode* next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_206_REVERSELIST_H*/
