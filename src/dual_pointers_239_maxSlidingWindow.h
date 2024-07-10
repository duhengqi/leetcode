#include "god.h"

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution {
public:
    void updateBigestNum(vector<int>& nums, int index, int k, int &fBig, int &fBigIndex){
        fBig = nums[index];
        for (int i = index; i < index + k;i++) {
            if (nums[index] > fBig) {
                fBig = nums[index];
                fBigIndex = i;
            }
        }
    }
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        /** 边界条件/特殊情况
         * 1， k > nums
         * 2,
        */
        if (nums.size() == 1 || k == 1) {
            return nums;
        }

        int fBig = nums[0];
        int fBigIndex = 0;
        int sBig;
        int sBigIndex = 0;
        bool sFlag = false;
        vector<int> result;
        int len = (k < nums.size() ? k : nums.size());
        for (int i = 0; i < len; i++) {
            if (fBig < nums[i]) {
                fBig = nums[i];
                fBigIndex = i;
                sFlag = false;
            } else if (sFlag == false || sBig < nums[i]) {
                    sBig = nums[i];
                    sBigIndex = i;
                    sFlag = true;
            }
        }
        result.push_back(fBig);
        if (nums.size() <= k) {
            return result;
        }
        int left = 1;
        int right = k;
        while (right < nums.size()) {
            if (fBigIndex == left-1) {
                    fBig = sBig;
                    fBigIndex = sBigIndex;
                    // TO DO
                    updateBigestNum(nums, left, k, sBig, sBigIndex);
            } else {
                if (fBig < nums[right]) {
                    fBig = nums[right];
                    fBigIndex = right;
                    sFlag = false;
                } else if (sFlag == false || sBig < nums[right]) {
                        sBig = nums[right];
                        sBigIndex = right;
                        sFlag = true;
                }
            }
            result.push_back(fBig);
            right++;
        }

    }
};
// @lc code=end

TEST(test_problem_239, testcase1)
{
    Solution so;
    vector<int> testcase = {1,3,-1,-3,5,3,6,7};
    vector<int> result = so.maxSlidingWindow(testcase,3);
    vector<int> exceptResult = {3,3,5,5,6,7};

    EXPECT_EQ(is_vector_equal(result,exceptResult), true);
}