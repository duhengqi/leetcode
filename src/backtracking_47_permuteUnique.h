#include "god.h"

/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
class Solution_47 {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {

    }
};
// @lc code=end



TEST(test_problem_47, testcase0)
{
    Solution_47 so;
    vector<int> nums = {1,2,3};
    vector<vector<int>> result = so.permute(nums);
    vector<vector<int>> exceptResult = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_47, testcase1)
{
    Solution_47 so;
    vector<int> nums = {1,2};
    vector<vector<int>> result = so.permute(nums);
    vector<vector<int>> exceptResult = {{1,2},{2,1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_47, testcase2)
{
    Solution_47 so;
    vector<int> nums = {1};
    vector<vector<int>> result = so.permute(nums);
    vector<vector<int>> exceptResult = {{1}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}
