#include "god.h"
/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
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
class Solution_160 {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int Alen = 0;
        int Blen = 0;
        ListNode *longList = nullptr;
        ListNode *shortList = nullptr;
        ListNode *tmpA = headA;
        ListNode *tmpB = headB;
        int n = 0;
        if (headA == nullptr || headB == nullptr) {
            return nullptr;
        }
        while (headA != nullptr || headB != nullptr) {
            if (headA != nullptr) {
                Alen++;
                headA = headA->next;
            }
            if (headB != nullptr) {
                Blen++;
                headB = headB->next;
            }
            cout << Alen << Blen << endl;
        }
        if (Alen > Blen) {
            longList = tmpA;
            shortList = tmpB;
            n = Alen - Blen;
        } else {
            longList = tmpB;
            shortList = tmpA;
            n = Blen - Alen;
        }
        
        while(n--) {
            longList = longList->next;
        }
        while (longList != nullptr) {
            if (longList == shortList) {
                return longList;
            }
            longList = longList->next;
            shortList = shortList->next;
        }
        return nullptr;
    }
};
// @lc code=end

