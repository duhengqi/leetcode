#include "algorithm_greedy.h"
#include "algorithm_utils.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#if ALGORITHM_DESCRIPTION("122 买卖股票的最佳时机 II")
/* 链接 https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/ */
/* 题目描述： 给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
示例 1: 输入: prices = [7,1,5,3,6,4] 输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。*/
/* 解题思路：根据单调性来做，获取最大收益，就是获取单调递增最大值 */
int maxProfit(int* prices, int pricesSize){
    int sum = 0;

    for (int loop = 1; loop < pricesSize; loop++) {
        if (prices[loop] - prices[loop-1] > 0) {
            sum += prices[loop] - prices[loop-1];
        }
    }
    return sum;
}

#endif

#if ALGORITHM_DESCRIPTION("135 分发糖果 困难")
/* 链接 https://leetcode-cn.com/problems/candy/ */
/* 题目描述：老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
你需要按照以下要求，帮助老师给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？
示例 1： 输入：[1,0,2] 输出：5 解释：你可以分别给这三个孩子分发 2、1、2 颗糖果。 */

int candy(int* ratings, int ratingsSize){
    int sum = 0;
    int *retArry = (int*)malloc(sizeof(int)*ratingsSize);
    for (int loop = 0; loop < ratingsSize; loop++) {
        retArry[loop] = 1;
    }
    for (int loop = 1; loop < ratingsSize; loop++) {
        if (ratings[loop] > ratings[loop-1]) {
            retArry[loop] = retArry[loop - 1] + 1;
        }
    }
    for (int loop = ratingsSize - 2; loop >= 0; loop--) {
        if (ratings[loop] > ratings[loop+1]) {
            if (retArry[loop] <= retArry[loop+1])
            retArry[loop] = retArry[loop+1] + 1;
        }
    }
    for (int loop = 0; loop < ratingsSize; loop++) {
        sum += retArry[loop];
    }
    return sum;
}

int testCandy() 
{
    int fen[] = {1, 0, 2};
    int sum = candy(fen, 3);
    printf("%d\n", sum);
    return 0;
}
#endif

#if ALGORITHM_DESCRIPTION("45 跳跃游戏 II")
/* 链接 https://leetcode-cn.com/problems/jump-game-ii/ */
/* 题目描述：给定一个非负整数数组，你最初位于数组的第一个位置。
数组中的每个元素代表你在该位置可以跳跃的最大长度。你的目标是使用最少的跳跃次数到达数组的最后一个位置。
假设你总是可以到达数组的最后一个位置。
示例 1:输入: [2,3,1,1,4] 输出: 2
解释: 跳到最后一个位置的最小跳跃数是 2。
     从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
思路：1，如果当前位置，是跳跃的覆盖范围变大，设置成跳跃点
      2，判断上一个跳跃点是否可以删除 */
int jump(int* nums, int numsSize){
    if (numsSize == 1) {
        return 0;
    }
    int jumpTimes = 0;
    int sJumpPoint = nums[0];
    int nJumpPoint = nums[0];

    for (int loop = 1; loop < numsSize - 1; loop++) {
        sJumpPoint--;
        nJumpPoint--;
        if (nJumpPoint < 0) {
            return 0;
        }
        if (nums[loop] > nJumpPoint) {
            nJumpPoint = nums[loop];
            if (nJumpPoint >= (numsSize - 1 - loop)) {
                jumpTimes += 2;
                return jumpTimes;
            }
        }

        if (sJumpPoint == 0) {
            sJumpPoint = nJumpPoint;
            jumpTimes++;
        }
    }
    return jumpTimes;
}
#endif

#if ALGORITHM_DESCRIPTION("55 跳跃游戏")
/* 链接 https://leetcode-cn.com/problems/jump-game/ */
/* 题目描述： 给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 。
数组中的每个元素代表你在该位置可以跳跃的最大长度。 判断你是否能够到达最后一个下标。
示例 1：输入：nums = [2,3,1,1,4] 输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标
思路：将能够到达最后一个下标，转换成能够跳跃的范围。*/
bool canJump(int* nums, int numsSize){
    if (numsSize == 1) {
        return true;
    }
    int area = nums[0];
    for (int loop = 1; loop < numsSize - 1; loop++) {
        area--;
        if (area < 0) {
            return false;
        }
        if (nums[loop] > area) {
            area = nums[loop];
            if (area >= (numsSize - 1 - loop)) {
                return true;
            }
        }

    }
    if (area > 0) {
        return true;
    } else {
        return false;
    }
}
#endif

#if ALGORITHM_DESCRIPTION("53 最大子数组和")
/* 链接 https://leetcode-cn.com/problems/maximum-subarray/ */
/* 题目描述：给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
示例 1： 输入：nums = [-2,1,-3,4,-1,2,1,-5,4] 输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
1 <= nums.length <= 3 * 104
-105 <= nums[i] <= 105
进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
*/
int maxSubArray(int* nums, int numsSize){
    if (numsSize == 1) {
        return nums[0];
    }

    int maxSum = nums[0];
    int nSum = nums[0];

    for (int loop = 1; loop < numsSize; loop++) {
        if (nums[loop] >= 0) {
            if (nSum > 0) {
                nSum += nums[loop];
            } else {
                nSum = nums[loop];
            }
            if (nSum > maxSum) {
                maxSum = nSum;
            }
        } else {
            if (nums[loop] >= nSum) {
                nSum = nums[loop];
            } else {
                nSum += nums[loop];
            }
            if (nSum > maxSum) {
                maxSum = nSum;
            }
        }
    }
    return maxSum;
}

#endif

#if ALGORITHM_DESCRIPTION("376 摆动序列")
/* 题目链接 https://leetcode-cn.com/problems/wiggle-subsequence/ */
/* 题目描述：如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。
仅有一个元素或者含两个不等元素的序列也视作摆动序列。 例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。
示例 1：输入：nums = [1,7,4,9,2,5]  输出：6 解释：整个序列均为摆动序列，各元素之间的差值为 (6, -3, 5, -7, 3) 。
示例 3：输入：nums = [1,2,3,4,5,6,7,8,9] 输出：2
如果连续数字之间的差严格地在正数和负数之间交替，则数字序列称为 摆动序列 。第一个差（如果存在的话）可能是正数或负数。仅有一个元素或者含两个不等元素的序列也视作摆动序列。
例如， [1, 7, 4, 9, 2, 5] 是一个 摆动序列 ，因为差值 (6, -3, 5, -7, 3) 是正负交替出现的。
相反，[1, 4, 7, 2, 5] 和 [1, 7, 4, 5, 5] 不是摆动序列，第一个序列是因为它的前两个差值都是正数，第二个序列是因为它的最后一个差值为零。
子序列 可以通过从原始序列中删除一些（也可以不删除）元素来获得，剩下的元素保持其原始顺序。
给你一个整数数组 nums ，返回 nums 中作为 摆动序列 的 最长子序列的长度 。 

提示： 1 <= nums.length <= 1000  0 <= nums[i] <= 1000
输入：nums = [1,17,5,10,13,15,10,5,16,8]
输出：7
解释：这个序列包含几个长度为 7 摆动序列。
其中一个是 [1, 17, 10, 13, 10, 16, 8] ，各元素之间的差值为 (16, -7, 3, -3, 6, -8) 。
*/
int wiggleMaxLength(int* nums, int numsSize){
    if (numsSize <= 1 ) {
        return numsSize;
    }
    if (numsSize == 2) {
        if (nums[0] == nums[1]) {
            return 1;
        } else {
            return 2;
        }
    }

    unsigned int pStat = 0;
    unsigned int nStat = 0;
    unsigned int result = 1;

    for (int loop = 1; loop < numsSize; loop++) {
        if (nums[loop] - nums[loop-1] == 0) {
            continue;
        }
        nStat = (nums[loop] - nums[loop-1]) > 0 ? 1 : -1;
        if (nStat != pStat) {
            result++;
            pStat = nStat;
            continue;
        }
        if (nStat == pStat) {
            pStat = nStat;
            continue;
        }
    }
    return result;
}

#endif