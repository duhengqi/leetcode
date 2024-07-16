#include "god.h"
#include "leetcode_list.h"

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
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
class Solution_86 {
public:
    ListNode* partition(ListNode* head, int x) {
        if (head == nullptr || head->next==nullptr) {
            return head;
        }
        ListNode smallNode = {};
        ListNode bigNode = {};
        ListNode *sHead = &smallNode;
        ListNode *bHead = &bigNode;

        while(head != nullptr) {
            if (head->val < x) {
                sHead->next = head;
                sHead = sHead->next;
            } else {
                bHead->next = head;
                bHead = bHead->next;
            }
            head = head->next;
        }
        bHead->next = nullptr;
        sHead->next = bigNode.next;

        return smallNode.next;
    }
};
// @lc code=end

