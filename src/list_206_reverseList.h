#include "god.h"
/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
        if (head->next == nullptr) {
            return head;
        }
        ListNode *last = head;
        ListNode *cur = head->next;
        ListNode *next = cur->next;
        last->next = nullptr;
        while (cur != nullptr) {
            cur->next = last;
            if (next == nullptr) {
                break;
            }
            last = cur;
            cur = next;
            next = next->next;
        }
        return cur;
    }
};
// @lc code=end

