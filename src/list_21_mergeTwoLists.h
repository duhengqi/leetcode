#include "god.h"
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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

class Solution_21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {

        if (list1 == NULL &&  list2 == NULL) {
            return NULL;
        }
        if (list1 == NULL) {
            return list2;
        }
        if (list2 == NULL) {
            return list1;
        }

        ListNode newnode = {};
        ListNode *nodePoint = &newnode;
        ListNode *L = list1;
        ListNode *R = list2;

        while(L || R) {
            if (L == NULL || R == NULL) {
                nodePoint->next = (L==NULL)?R:L;
                break;
            }
            if (L->val <= R->val) {
                nodePoint->next = L;
                L = L->next;
                nodePoint = nodePoint->next;
            } else {
                nodePoint->next = R;
                R = R->next;
                nodePoint = nodePoint->next;
            }
        }

        return newnode.next;
    }
};

// @lc code=end
