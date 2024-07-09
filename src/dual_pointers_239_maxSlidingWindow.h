#include "god.h"

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

    }
};
// @lc code=end

TEST(test_problem_239, testcase1)
{
    Solution so;
    vector<int> testcase = {1,3,-1,-3,5,3,6,7};
    vector<int> result = so.maxSlidingWindow(testcase,3);
    vector<int> exceptResult = {3,3,5,5,6,7};

    EXPECT_EQ(is_vector_equal(result,exceptResult), true);
}