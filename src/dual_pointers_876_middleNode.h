#include "god.h"
#include "leetcode_list.h"

/*
 * @lc app=leetcode.cn id=876 lang=cpp
 *
 * [876] 链表的中间结点
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
class Solution_876 {
public:
    ListNode* middleNode(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        int len = 1;
        ListNode* result = head;
        while (head->next != nullptr) {
            head = head->next;
            len++;
            if (len %2 == 0) {
                result = result->next;
            }
        }
        return result;
    }
};
// @lc code=end

