#include "god.h"
/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        multiset<int> numsSet;
        vector<vector<int>> result;
        int numLen = 0;
        for ( numLen = 0; numLen < nums.size();numLen++) {
            numsSet.insert(nums[numLen]);
        }
        numLen = 0;
        for (auto iter = numsSet.begin(); iter != numsSet.end();iter++) {
            nums[numLen] = *iter;
            numLen++;
        }
        int left = 0;
        while (left < numLen-2){
            if (left > 0 && nums[left] == nums[left-1]) {
                left++;
                continue;
            }
            int mid = left+1;
            int right = numLen-1;
            while (mid < right) {
                if (mid > left+1 && nums[mid] == nums[mid-1]) {
                    mid++;
                    continue;                    
                }
                if (nums[left] + nums[right]+nums[mid] == 0) {
                    result.push_back({nums[left],nums[mid],nums[right]});
                    mid++;
                    continue;
                } else if (nums[left] + nums[right]+nums[mid] > 0){
                    right--;
                } else {
                    mid++;
                }
            }

            left++;
        }
        return result;
    }
};
// @lc code=end
/*输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
输入：nums = [0,1,1] 输出：[]
//nums = [0,0,0]
*/
TEST(test_problem_15, testcase1)
{
    Solution so;
    vector<int> testcase = {-1,0,1,2,-1,-4};
    auto result = so.threeSum(testcase);
    for (int i = 0; i < result.size(); i++) {
        cout <<i<< " result: "<< result[i][0] << " " << result[i][1] << " " << result[i][2] << endl;
        EXPECT_EQ(result[i][0] + result[i][1] + result[i][2], 0);
    }

}
TEST(test_problem_15, testcase2)
{
    Solution so;
    vector<int> testcase = {0,1,1};
    auto result = so.threeSum(testcase);
    EXPECT_EQ(result.size(), 0);
    
}
TEST(test_problem_15, testcase3)
{
    Solution so;
    vector<int> testcase = {0,0,0,0};
    auto result = so.threeSum(testcase);
    vector<int> exceptResult = {0,0,0};

    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(is_vector_equal(result[0],exceptResult), true);
}