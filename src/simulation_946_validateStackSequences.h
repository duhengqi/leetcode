#include "god.h"

/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */

// @lc code=start
class Solution_946 {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> stk;
        int j = 0;
        int i = 0;
        while (i < popped.size()) {
            if (!stk.empty() && stk.top() == popped[i]) {
                stk.pop();
                i++;
                continue;
            }
            while (j < pushed.size() && pushed[j] != popped[i]) {
                stk.push(pushed[j]);
                j++;
            }
            if (j >= pushed.size()) {
                return false;
            } else {
                j++;
                i++;
            }
        }
        return true;
    }
};
// @lc code=end

TEST(test_problem_946, testcase1)
{
    Solution_946 so;
    vector<int> pushed={1,2,3,4,5};
    vector<int> popped={4,5,3,2,1};
    bool result = so.validateStackSequences(pushed,popped);
    EXPECT_EQ(result,true);
}

TEST(test_problem_946, testcase2)
{
    Solution_946 so;
    vector<int> pushed={1,2,3,4,5};
    vector<int> popped={4,3,5,1,2};
    bool result = so.validateStackSequences(pushed,popped);
    EXPECT_EQ(result,false);
}

