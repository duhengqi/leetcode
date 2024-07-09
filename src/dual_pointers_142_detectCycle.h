#include "god.h"

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
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
class Solution_142 {
public:
    ListNode *detectCycle(ListNode *head) {
        int aLen = 0;
        ListNode node;
        node.next = head;
        ListNode *slow =&node;
        ListNode *fast =&node;
        ListNode *ptr  =&node;

        if (head == nullptr || head->next == nullptr) {
            return nullptr;
        }
        while (fast != nullptr) {
            if (slow->next != nullptr) {
                slow = slow->next;
            } else {
                return nullptr;
            }
            if (fast->next != nullptr && fast->next->next != nullptr) {
                fast = fast->next->next;
            } else {
                return nullptr;
            }
            aLen++;
            if (fast == slow) {
                break;
            }
        }
        while (aLen--) {
            slow = slow->next;
            ptr = ptr->next;
            if (slow == ptr) {
                return slow;
            }
        }
        return nullptr;
    }
};
// @lc code=end
 
