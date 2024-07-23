#ifndef _LEETCODE_NUMS_21_MERGETWOLISTS_H
#define _LEETCODE_NUMS_21_MERGETWOLISTS_H

#include "god.h"
#include "leetcode_list.h"
/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 * https://leetcode.cn/problems/merge-two-sorted-lists/
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

#endif /*_LEETCODE_NUMS_21_MERGETWOLISTS_H*/
