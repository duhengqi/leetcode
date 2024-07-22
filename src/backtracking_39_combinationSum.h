#include "god.h"

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
class Solution_39 {
public:
    void combinationSumRecursive(vector<vector<int>>& result, vector<int> candidates, int target, int sum,vector<int> items){
        if (sum > target) {
            return;
        }
        if (sum == target) {
            result.push_back(items);
            return;
        }
        int before = 0xFF;
        for (int i = 0; i < candidates.size();i++) {
            if (candidates[i] == 0xFF) {
                continue;
            }
            if (candidates[i] == before) {
                candidates[i] = 0xFF;
                continue;
            }
            items.push_back(candidates[i]);
            combinationSumRecursive(result, candidates, target, sum + candidates[i], items);
            items.pop_back();
            before = candidates[i];
            candidates[i] = 0xFF;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> items;
        sort(candidates.begin(), candidates.end());
        combinationSumRecursive(result, candidates, target, 0,items);
        return result;
    }
};
// @lc code=end


TEST(test_problem_39, testcase0)
{
    Solution_39 so;
    vector<int> candidates = {2,3,6,7};
    vector<vector<int>> result = so.combinationSum(candidates,7);
    vector<vector<int>> exceptResult = {{2,2,3},{7}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_39, testcase1)
{
    Solution_39 so;
    vector<int> candidates = {2,3,5};
    vector<vector<int>> result = so.combinationSum(candidates,8);
    vector<vector<int>> exceptResult = {{2,2,2,2},{2,3,3},{3,5}};

    EXPECT_EQ(is_two_dim_vector_equal(result,exceptResult), true);
}

TEST(test_problem_39, testcase2)
{
    Solution_39 so;
    vector<int> candidates = {2};
    vector<vector<int>> result = so.combinationSum(candidates,1);

    EXPECT_EQ(result.empty(), true);
}