#include "god.h"
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
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
