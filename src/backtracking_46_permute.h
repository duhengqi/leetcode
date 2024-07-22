#include "god.h"
/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
class Solution_46 {
public:
    vector<vector<int>> permute(vector<int>& nums) {

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
