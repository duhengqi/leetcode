#include "god.h"

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution_153 {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0];
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] <= nums[right]) {
                right = mid;
            }
            if (nums[left] <= nums[right]) {
                return nums[left];
            }
        }
        return result;
    }
};
// @lc code=end

TEST(test_problem_153, testcase0)
{
    Solution_153 so;
    vector<int> nums = {0,1,2,3,4,5,6};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_153, testcase1)
{
    Solution_153 so;
    vector<int> nums = {6,0,1,2,3,4,5};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_153, testcase2)
{
    Solution_153 so;
    vector<int> nums = {5,6,0,1,2,3,4};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_153, testcase3)
{
    Solution_153 so;
    vector<int> nums = {4,5,6,0,1,2,3};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_153, testcase4)
{
    Solution_153 so;
    vector<int> nums = {3,4,5,6,0,1,2};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_153, testcase5)
{
    Solution_153 so;
    vector<int> nums = {2,3,4,5,6,0,1};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_153, testcase6)
{
    Solution_153 so;
    vector<int> nums = {1,2,3,4,5,6,0};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_153, testcase7)
{
    Solution_153 so;
    vector<int> nums = {2,0};
    EXPECT_EQ(so.findMin(nums), 0);
}