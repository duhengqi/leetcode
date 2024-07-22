#include "god.h"

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution_47 {
public:
    void permuteUniqueRecursive(vector<vector<int>>& result, vector<int> nums, vector<int>items, int index)
    {
        if (index >= nums.size()) {
            return;
        }
        int before = 0xFF;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0xFF || nums[i] == before) {
                continue;
            }
            items[index] = nums[i];
            if (index == nums.size()-1) {
                result.push_back(items);
                return;
            }
            nums[i] = 0xFF;
            permuteUniqueRecursive(result, nums, items, index+1);
            nums[i] = items[index];
            before = nums[i];
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        vector<int> items(nums.size());
        permuteUniqueRecursive(result, nums, items, 0);
        return result;
    }
};
// @lc code=end

TEST(test_problem_47, testcase00)
{
    Solution_47 so;
    vector<int> nums = {1,1,2};
    vector<vector<int>> result = so.permuteUnique(nums);
    vector<vector<int>> exceptResult = {{1,1,2},{1,2,1},{2,1,1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_47, testcase0)
{
    Solution_47 so;
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = so.permuteUnique(nums);
    vector<vector<int>> exceptResult = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_47, testcase1)
{
    Solution_47 so;
    vector<int> nums = {1,2};
    vector<vector<int>> result = so.permuteUnique(nums);
    vector<vector<int>> exceptResult = {{1,2},{2,1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_47, testcase2)
{
    Solution_47 so;
    vector<int> nums = {1};
    vector<vector<int>> result = so.permuteUnique(nums);
    vector<vector<int>> exceptResult = {{1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}
