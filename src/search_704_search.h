#include "god.h"

/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

// @lc code=start
class Solution_704 {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size()-1;

        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return -1;
    }
};

// @lc code=end

TEST(test_problem_704, testcase0)
{
    Solution_704 so;
    vector<int> nums = {-1,0,3,5,9,12};
    EXPECT_EQ(so.search(nums,9), 4);
}


TEST(test_problem_704, testcase1)
{
    Solution_704 so;
    vector<int> nums = {-1,0,3,5,9,12};
    EXPECT_EQ(so.search(nums,2), -1);
}

TEST(test_problem_704, testcase2)
{
    Solution_704 so;
    vector<int> nums = {-1};
    EXPECT_EQ(so.search(nums,9), -1);
}

TEST(test_problem_704, testcase3)
{
    Solution_704 so;
    vector<int> nums = {-1};
    EXPECT_EQ(so.search(nums,-2), -1);
}

TEST(test_problem_704, testcase4)
{
    Solution_704 so;
    vector<int> nums = {-1};
    EXPECT_EQ(so.search(nums,-1), 0);
}