#ifndef _LEETCODE_NUMS_135_CANDY_H_
#define _LEETCODE_NUMS_135_CANDY_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 * n 个孩子站成一排。给你一个整数数组 ratings 表示每个孩子的评分。
 * 你需要按照以下要求，给这些孩子分发糖果：
 * 每个孩子至少分配到 1 个糖果。
 * 相邻两个孩子评分更高的孩子会获得更多的糖果。
 * 请你给每个孩子分发糖果，计算并返回需要准备的 最少糖果数目 。
 * 
 * 示例 1：
 * 输入：ratings = [1,0,2]
 * 输出：5
 * 解释：你可以分别给第一个、第二个、第三个孩子分发 2、1、2 颗糖果。
 * 
 * 示例 2：
 * 输入：ratings = [1,2,2]
 * 输出：4
 * 解释：你可以分别给第一个、第二个、第三个孩子分发 1、2、1 颗糖果。
 *      第三个孩子只得到 1 颗糖果，这满足题面中的两个条件。
 * 
 * 提示：
 * n == ratings.length
 * 1 <= n <= 2 * 10^4
 * 0 <= ratings[i] <= 2 * 10^4
 */

// @lc code=start
class Solution_135 {
public:
   void setCandy(vector<int>& candy, int start, int end, bool flag) {
        if (flag) {
            for (int i = start + 1; i <= end;i++) {
                if (candy[i] <= candy[i - 1]) {
                    candy[i] = candy[i - 1] + 1;
                }
            }
        } else {
            for (int i = end-1; i >= start; i--) {
                if (candy[i] <= candy[i + 1]) {
                    candy[i] = candy[i + 1] + 1;
                }
            }
        }
   }
    int candy(vector<int>& ratings) {
        vector<int> candy(ratings.size(),1);
        int index = 0;
        int result = 0;
        while(index+1 < candy.size()) {
            int end = index;
            if (ratings[index] > ratings[index+1]) {
                for (end = index; end+1 < ratings.size(); end++) {
                    if (ratings[end] <= ratings[end+1]) {
                        break;
                    }
                }
                setCandy(candy, index, end, false);
                index = end;
            } else if(ratings[index] < ratings[index+1]) {
                for (end = index; end+1 < ratings.size(); end++) {
                    if (ratings[end] >= ratings[end+1]) {
                        break;
                    }
                }
                setCandy(candy, index, end, true);
                index = end;
            } else {
                index++;
            }
        }
        for (int i = 0; i < candy.size(); i++) {
            result += candy[i];
        }
        return result;
    }

};
// @lc code=end

TEST(test_problem_135, testcase0)
{
    Solution_135 so;
    vector<int> ratings = {1,0,2};
    int result = so.candy(ratings);
    EXPECT_EQ(result, 5);;
}

TEST(test_problem_135, testcase1)
{
    Solution_135 so;
    vector<int> ratings = {1,2,2};
    int result = so.candy(ratings);
    EXPECT_EQ(result, 4);;
}

TEST(test_problem_135, testcase2)
{
    Solution_135 so;
    vector<int> ratings = {1,6,10,8,7,3,2};
    int result = so.candy(ratings);
    EXPECT_EQ(result, 18);
}

#endif /*_LEETCODE_NUMS_135_CANDY_H_*/
