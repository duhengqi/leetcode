#include "god.h"

/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 * 给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。
 * 请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 * 你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。
 * 示例 1:
 * 输入: [3,2,1,5,6,4], k = 2  输出: 5
 * 
 * 示例 2:
 * 输入: [3,2,3,1,2,4,5,5,6], k = 4 输出: 4
 * 
 * 提示：
 * 1 <= k <= nums.length <= 105
 * -104 <= nums[i] <= 104
 */

// @lc code=start

class Solution_215_deque {
public:
    int findKthLargest(vector<int>& nums, int k) {
        
    }
};

class Solution_215_priority_queue {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // 没有这样的构造函数 priority_queue<int,greater<int>>que;
        priority_queue<int, deque<int>, greater<int>>que(nums.begin(),nums.begin()+k);
        for (int i = k; i < nums.size();i++) {
            if (nums[i]>que.top()) {
                que.pop();
                que.push(nums[i]);
            }
        }
        return que.top();
    }
};
// @lc code=end


TEST(test_problem_215, testcase0)
{
    Solution_215_priority_queue so;
    vector<int> nums = {3,2,1,5,6,4};

    EXPECT_EQ(so.findKthLargest(nums,2),5);

}

TEST(test_problem_215, testcase1)
{
    Solution_215_priority_queue so;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};

    EXPECT_EQ(so.findKthLargest(nums,4),4);

}
