#ifndef _LEETCODE_NUMS_155_MINSTACK_H
#define _LEETCODE_NUMS_155_MINSTACK_H

#include "god.h"
/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 * https://leetcode.cn/problems/min-stack
 */

// @lc code=start
#define MAX_STK_SIZE  (3*10*10*10*10)

class MinStack_155 {
public:
    MinStack_155() {}
    
    void push(int val) {
        if (stkHead == MAX_STK_SIZE) {
            return;
        }
        stkHead++;
        stk[stkHead] = val;
    }
    
    void pop() {
        stkHead--;
    }
    
    int top() {
        return stk[stkHead];
    }
    
    int getMin() {
        if (stkHead < 0) {
            return 0;
        }
        int res = stk[0];
        for (int i = 0; i <= stkHead; i++) {
            if (res > stk[i]) {
                res = stk[i];
            }
        }
        return res;
    }
private:
    int stk[MAX_STK_SIZE] = {0};
    int stkHead = -1;

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

#endif /*_LEETCODE_NUMS_155_MINSTACK_H*/
