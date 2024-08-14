#ifndef _LEETCODE_NUMS_8_PARTITION_H
#define _LEETCODE_NUMS_8_PARTITION_H

#include "god.h"
#include "leetcode_list.h"

/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 * https://leetcode.cn/problems/partition-list/description/
 * 给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，
 * 使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。
 * 你应当 保留 两个分区中每个节点的初始相对位置
 */

// @lc code=start

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

#endif /*_LEETCODE_NUMS_8_PARTITION_H*/
