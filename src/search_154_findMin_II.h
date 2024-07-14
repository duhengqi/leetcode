
#include "god.h"

/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int result = nums[0];
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                bool flag = false;
                for (int i = mid+1; i < right; i++) {
                    if (nums[i]>nums[mid]) {
                        flag = true;
                        left = i;
                        break;
                    } else if (nums[i]<nums[mid]) {
                        return nums[i];
                    }
                }
                if (flag == false) {
                    right = mid;
                }
            }
            if (nums[left] < nums[right]) {
                return nums[left];
            }
            if (left == right) {
                return nums[left];
            }
        }
        return result;
    }
};
// @lc code=end


TEST(test_problem_154, testcaseI00)
{
    Solution so;
    vector<int> nums = {1,1,2,0,1,1,1,1,1,1};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcaseII0)
{
    Solution so;
    vector<int> nums = {0};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcaseII1)
{
    Solution so;
    vector<int> nums = {0,0};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcaseII2)
{
    Solution so;
    vector<int> nums = {2,0,0};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcaseII3)
{
    Solution so;
    vector<int> nums = {0,2,0};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcaseII4)
{
    Solution so;
    vector<int> nums = {0,1,1,1,1,1,1,2};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcaseII5)
{
    Solution so;
    vector<int> nums = {2,0,1,1,1,1,1,1};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcase0)
{
    Solution so;
    vector<int> nums = {0,1,2,3,4,5,6};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcase1)
{
    Solution so;
    vector<int> nums = {6,0,1,2,3,4,5};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcase2)
{
    Solution so;
    vector<int> nums = {5,6,0,1,2,3,4};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcase3)
{
    Solution so;
    vector<int> nums = {4,5,6,0,1,2,3};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcase4)
{
    Solution so;
    vector<int> nums = {3,4,5,6,0,1,2};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcase5)
{
    Solution so;
    vector<int> nums = {2,3,4,5,6,0,1};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcase6)
{
    Solution so;
    vector<int> nums = {1,2,3,4,5,6,0};
    EXPECT_EQ(so.findMin(nums), 0);
}

TEST(test_problem_154, testcase7)
{
    Solution so;
    vector<int> nums = {2,0};
    EXPECT_EQ(so.findMin(nums), 0);
}