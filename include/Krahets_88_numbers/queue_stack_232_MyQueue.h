#ifndef _LEETCODE_NUMS_232_MYQUEUE_H
#define _LEETCODE_NUMS_232_MYQUEUE_H

#include "god.h"
/*
 * @lc app=leetcode.cn id=232 lang=cpp
 * https://leetcode.cn/problems/implement-queue-using-stacks/description
 * [232] 用栈实现队列
 */

// @lc code=start
class MyQueue_232 {
public:
    MyQueue_232() {

    }

    void push(int x) { lStk.push(x); }

    int pop() {
        if (lStk.empty()) {
            return -1;
        }
        while (!lStk.empty()) {
            rStk.push(lStk.top());
            lStk.pop();
        }
        int res = rStk.top();
        rStk.pop();
        while(!rStk.empty()) {
            lStk.push(rStk.top());
            rStk.pop();  
        }
        return res;
    }
    
    int peek() {
        if (lStk.empty()) {
            return -1;
        }
        while (!lStk.empty()) {
            rStk.push(lStk.top());
            lStk.pop();
        }
        int res = rStk.top();
        while(!rStk.empty()) {
            lStk.push(rStk.top());
            rStk.pop();  
        }
        return res;
    }

    bool empty() { return lStk.empty(); }

private:
    stack<int> lStk;
    stack<int> rStk;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end

#endif /*_LEETCODE_NUMS_232_MYQUEUE_H*/
