#include "god.h"
/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
class Solution_724 {
public:
    int pivotIndex(vector<int>& nums) {
        int sumLeft = 0;
        int sumRight = 0;

        for (int i = 0; i < nums.size();i ++) {
            sumRight += nums[i];
        }
        for (int i = 0; i < nums.size();i ++) {
            sumLeft += nums[i];
            if (sumLeft == sumRight) {
                return i;
            } else {
                sumRight -= nums[i];
            }
        }
        return -1;
    }
};
// @lc code=end


TEST(test_problem_724, testcase0)
{
    Solution_724 so;
    vector<int> nums = {1, 7, 3, 6, 5, 6};
    EXPECT_EQ(so.pivotIndex(nums), 3);
}

TEST(test_problem_724, testcase1)
{
    Solution_724 so;
    vector<int> nums = {1};
    EXPECT_EQ(so.pivotIndex(nums), 0);
}

TEST(test_problem_724, testcase2)
{
    Solution_724 so;
    vector<int> nums = {1, 2, 3};
    EXPECT_EQ(so.pivotIndex(nums), -1);
}

TEST(test_problem_724, testcase3)
{
    Solution_724 so;
    vector<int> nums = {2, 1, -1};
    EXPECT_EQ(so.pivotIndex(nums), 0);
}

TEST(test_problem_724, testcase4)
{
    Solution_724 so;
    vector<int> nums = {2, -2, -1};
    EXPECT_EQ(so.pivotIndex(nums), 2);
}
