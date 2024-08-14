#ifndef _LEETCODE_NUMS_39_COMBINATIONSUM_H
#define _LEETCODE_NUMS_39_COMBINATIONSUM_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=39 lang=cpp
 * 
 * Category	Difficulty	Likes	Dislikes
 * algorithms	Medium (72.33%)	2535	-
 * Tags: array | backtracking
 * 
 * 给你一个 无重复元素 的整数数组 candidates 和一个目标整数 target ，
 * 找出candidates 中可以使数字和为目标数 target 的所有不同组合 ，并以列表形式返回。你可以按 任意顺序 返回这些组合。
 * candidates 中的 同一个 数字可以 无限制重复被选取 。如果至少一个数字的被选数量不同，则两种组合是不同的。 
 * 
 * 对于给定的输入，保证和为 target 的不同组合数少于 150 个。
 * 示例 1：
 * 输入：candidates = [2,3,6,7], target = 7      输出：[[2,2,3],[7]]
 * 解释：
 * 2 和 3 可以形成一组候选，2 + 2 + 3 = 7 。注意 2 可以使用多次。
 * 7 也是一个候选， 7 = 7 。
 * 仅有这两种组合。

 * 示例 2：
 * 输入: candidates = [2,3,5], target = 8
 * 输出: [[2,2,2,2],[2,3,3],[3,5]]

 * 示例 3：
 * 输入: candidates = [2], target = 1
 * 输出: []
  * 提示：
 * 1 <= candidates.length <= 30
 * 2 <= candidates[i] <= 40
 * candidates 的所有元素 互不相同
 * 1 <= target <= 40
 * [39] 组合总和
 */
/**
 * 数组不重复，无需排序，难点在于如何去重：
 * 按照递归，不去重的情况下。举例：[2,3,6,7], target = 7 
 * 应该是 
 * 1， 从2往下遍历 2 2 3 2 3 2
 * 2， 从3往下遍历 3,2,2  
 * 3, 7
 * 只需要从 3遍历的时候，不遍历 2即可去重，应为前面2已经遍历了所有的可能
 * 即同一层遍历时，前一个元素不能遍历
 *
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
        for (int i = 0; i < candidates.size();i++) {
            if (candidates[i] == 0xFF) {
                continue;
            }
            items.push_back(candidates[i]);
            combinationSumRecursive(result, candidates, target, sum + candidates[i], items);
            items.pop_back();
            candidates[i] = 0xFF;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> items;
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

#endif /*_LEETCODE_NUMS_39_COMBINATIONSUM_H*/
