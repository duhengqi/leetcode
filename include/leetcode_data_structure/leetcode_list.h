#ifndef  _LEETCODE_BINARY_LIST_H_
#define  _LEETCODE_BINARY_LIST_H_

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#endif /* _LEETCODE_BINARY_LIST_H_ */