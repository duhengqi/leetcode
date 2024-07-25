#ifndef _LEETCODE_NUMS_40_COMBINATIONSUM_II_H
#define _LEETCODE_NUMS_40_COMBINATIONSUM_II_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 * 给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * candidates 中的每个数字在每个组合中只能使用 一次 。
 * 注意：解集不能包含重复的组合。 
 * 示例 1:
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 输出:[[1,1,6], [1,2,5], [1,7], [2,6] ]
 * 示例 2:
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 输出: [ [1,2,2], [5] ]
 * 提示:
 * 1 <= candidates.length <= 100
 * 1 <= candidates[i] <= 50
 * 1 <= target <= 30
 * 如何去重：
 * 1，排序，同一层中，使用过的相同元素不再使用
 * 2，因为每个数字在每个组合中只能使用 一次，到下一层遍历时，使用过的元素也不能使用
 */

// @lc code=start
class Solution_40 {
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
            before = candidates[i];
            candidates[i] = 0xFF;
            combinationSumRecursive(result, candidates, target, sum + before, items);
            items.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> items;
        sort(candidates.begin(), candidates.end());
        combinationSumRecursive(result, candidates, target, 0,items);
        return result;
    }

};
// @lc code=end

#endif /*_LEETCODE_NUMS_40_COMBINATIONSUM_II_H*/
