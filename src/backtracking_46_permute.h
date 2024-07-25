#ifndef _LEETCODE_NUMS_46_PREMUTE_H
#define _LEETCODE_NUMS_46_PREMUTE_H

#include "god.h"
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 * Category	Difficulty	Likes	Dislikes
 * algorithms	Medium (78.93%)	2928	-
 * 
 * 给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。
 * 
 * 示例 1：
 * 输入：nums = [1,2,3]  输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 * 示例 2：
 * 输入：nums = [0,1]  输出：[[0,1],[1,0]]
 * 
 * 示例 3：
 * 输入：nums = [1] 输出：[[1]]
 * 提示：
 * 1 <= nums.length <= 6
 * -10 <= nums[i] <= 10
 * nums 中的所有整数 互不相同
 */

// @lc code=start
class Solution_46 {
public:
    void permuteRecursive(vector<vector<int>>& result, vector<int> nums, vector<int>items, int index)
    {
        if (index >= nums.size()) {
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0xFF) {
                continue;
            }
            items[index] = nums[i];
            if (index == nums.size()-1) {
                result.push_back(items);
                return;
            }
            nums[i] = 0xFF;
            permuteRecursive(result, nums, items, index+1);
            nums[i] = items[index];
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> items(nums.size());
        permuteRecursive(result, nums, items, 0);
        return result;
    }
};
// @lc code=end

TEST(test_problem_46, testcase0)
{
    Solution_46 so;
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = so.permute(nums);
    vector<vector<int>> exceptResult = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_46, testcase1)
{
    Solution_46 so;
    vector<int> nums = {1,2};
    vector<vector<int>> result = so.permute(nums);
    vector<vector<int>> exceptResult = {{1,2},{2,1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_46, testcase2)
{
    Solution_46 so;
    vector<int> nums = {1};
    vector<vector<int>> result = so.permute(nums);
    vector<vector<int>> exceptResult = {{1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

#endif /*_LEETCODE_NUMS_46_PREMUTE_H*/
