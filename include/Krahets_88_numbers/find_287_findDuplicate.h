#include "god.h"
/*
 * @lc app=leetcode.cn id=287 lang=cpp
 *
 * [287] 寻找重复数
 */

// @lc code=start

/**
 * 循环链表
*/
class Solution_287_dual_pointers {
public:
    int findDuplicate(vector<int>& nums) {
        return 0;
    }
};

/**
 * bit map 解法
*/
class Solution_287_bitmap {
public:
    int findDuplicate(vector<int>& nums) {
        int bit[32] = {0};
        int bit2[32] = {0};
        int len = nums.size();
        for (int i = 1;i<len;i++) {
            for (int j = 0; j < 32; j++) {
                if (i & (0x1<<j)) {
                    bit[j]++;
                }
            }
        }

        for (int i = 0;i<len;i++) {
            for (int j = 0; j < 32; j++) {
                if (nums[i] & (0x1<<j)) {
                    bit2[j]++;
                }
            }
        }
        int res = 0;
        for (int j = 0; j < 32; j++) {
                if (bit2[j]>bit[j]) {
                    res |= (0x1 << j);
                }
        }      
        return res;
    }
};

/**
 * 二分法解法
 * 假设target是重复数，cnt[i]为数组中小于等于i的个数 则有 [1~target-1] cnt[i] <= i
 * [target,n] cnt[i] > i
*/
class Solution_287_binary_search {
public:
    int findDuplicate(vector<int>& nums) {
        if (nums.size() <= 2) {
            return nums[0];
        }
        int left = 1;
        int right = nums.size()-1;

        while(left<=right) {
            int cnt = 0;
            int mid = left+(right - left)/2;
            for (int i = 0; i < nums.size();i++) {
                if (nums[i] <= mid) {
                    cnt++;
                }
            }
            if (cnt > mid) {
                right = mid;
            } else {
                left = mid+1;
            }
            if (left == right) {
                return left;
            }
        }
        return left;
    }
};
// @lc code=end



TEST(test_problem_287, testcase0)
{
    Solution_287_binary_search so;
    vector<int> nums = {1,3,4,2,2};
    EXPECT_EQ(so.findDuplicate(nums), 2);
}

TEST(test_problem_287, testcase1)
{
    Solution_287_binary_search so;
    vector<int> nums = {3, 1, 3, 4, 2};
    EXPECT_EQ(so.findDuplicate(nums), 3);
}

TEST(test_problem_287, testcase2)
{
    Solution_287_binary_search so;
    vector<int> nums = {3,3,3,3,3};
    EXPECT_EQ(so.findDuplicate(nums), 3);
}

TEST(test_problem_287, testcase3)
{
    Solution_287_binary_search so;
    vector<int> nums = {1,3,4,2,2,5,6};
    EXPECT_EQ(so.findDuplicate(nums), 2);
}

TEST(test_problem_287, testcase4)
{
    Solution_287_binary_search so;
    vector<int> nums = {1,1,3,2,4,5};
    EXPECT_EQ(so.findDuplicate(nums), 1);
}

TEST(test_problem_287, testcase5)
{
    Solution_287_binary_search so;
    vector<int> nums = {1,3,4,5,6,2,1};
    EXPECT_EQ(so.findDuplicate(nums), 1);
}