#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "algorithm_dp.h"
#include "algorithm_utils.h"
#if ALGORITHM_DESCRIPTION("53 最大子数组和")
/* 链接 https://leetcode-cn.com/problems/maximum-subarray/ */
/* 题目描述：给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。子数组 是数组中的一个连续部分。*/
/* 示例 输入：nums = [-2,1,-3,4,-1,2,1,-5,4] 输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。*/
/*解题思路：确定dp数组（dp table）以及下标的含义，确定递推公式，dp数组如何初始化，确定遍历顺序，举例推导dp数组 */
int maxSubRecursion(int* nums, int numsSize, int *maxSum){
    if (numsSize == 0) {
        return nums[0];
    }
    int maxPoint;
    int pre = nums[numsSize] + maxSubRecursion(nums, numsSize - 1, maxSum);
    if (nums[numsSize] > pre) {
        maxPoint = nums[numsSize];
    } else {
        maxPoint = pre;
    }
    if (maxPoint > *maxSum) {
        *maxSum = maxPoint;
    }
    return maxPoint;
}
int maxSubArrayRecursion(int* nums, int numsSize){
    int maxSum = nums[0];
    maxSubRecursion(nums, numsSize-1, &maxSum);
     return maxSum;
}
int maxSubArray(int* nums, int numsSize){
    int maxSum = nums[0];
    int pre = nums[0];
    for (int i = 1; i < numsSize; i++) {
        if (pre > 0) {
            pre = pre + nums[i];
        } else {
            pre = nums[i];
        }
        if (pre > maxSum) {
            maxSum = pre;
        }
        
    }
    return maxSum;
}
/* 暴力法 */
int maxSumArray_way_violence(int* nums, int numsSize, int index){
    int maxSum = nums[index];
    int tempSum = 0;
    for (int i = index; i < numsSize; i++) {
        tempSum += nums[i];
        if (maxSum < tempSum) {
            maxSum = tempSum;
        }
    }
    ALGORITHM_INFO_LOG("index %d maxSum %d \n", index, maxSum);
    return maxSum;
}
int maxSubArray_way_violence(int* nums, int numsSize){
    int maxSum = nums[0];
    int tmp = 0;
    for (int i = 0; i < numsSize; i++) {
        tmp = maxSumArray_way_violence(nums, numsSize, i);
        if (maxSum < tmp) {
            maxSum = tmp;
        }
    }
    return maxSum;
}
int testMaxSubArray()
{
    int testArr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4 };
    int maxSum = maxSubArrayRecursion(testArr, sizeof(testArr)/sizeof(int));
    ALGORITHM_INFO_LOG("maxSum %d \n", maxSum);
    return maxSum;
}

#endif
#if ALGORITHM_DESCRIPTION("343 整数拆分")
/* 链接 https://leetcode-cn.com/problems/integer-break/ */
/* 题目描述：给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。*/
/* 给定一个正整数 n，将其拆分为至少两个正整数的和，并使这些整数的乘积最大化。 返回你可以获得的最大乘积。*/
/* 示例 2: 输入: 10 输出: 36
解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。*/
/*解题思路：确定dp数组（dp table）以及下标的含义，确定递推公式，dp数组如何初始化，确定遍历顺序，举例推导dp数组 */
int integerBreak(int n){
    int dp[100] = {0};
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 2;
    dp[4] = 4;
    dp[5] = 6;
    dp[6] = 9;
    for (int loop = 7; loop <= n;loop++)
    {
        if (loop%3 == 1) {
            dp[loop] = dp[loop - 1] * 2;
        }
        if (loop%3 == 2) {
            dp[loop] = dp[loop - 2] * 2;
        }
        
        if (loop%3 == 0) {
            dp[loop] = dp[loop - 3] * 3;
        }
    }
    return dp[n];
}

#endif
#if ALGORITHM_DESCRIPTION("416 分割等和子集")
/* 链接 https://leetcode-cn.com/problems/partition-equal-subset-sum/ */
/* 题目描述：给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。*/
/*示例 1： 输入：nums = [1,5,11,5] 输出：true [2,2,3,5]
解释：数组可以分割成 [1, 5, 5] 和 [11] 。*/
/*解题思路：确定dp数组（dp table）以及下标的含义，确定递推公式，dp数组如何初始化，确定遍历顺序，举例推导dp数组 */
bool canPartition(int* nums, int numsSize){
    int dp[10001] = {0};
    int target = nums[0];
    int maxNum = nums[0];
    for (int i = 1; i < numsSize; i++) {
        target += nums[i];
        if (nums[i] > maxNum) {
            maxNum = nums[i];
        }
    }
    if (target % 2 != 0 || maxNum > target/2) {
        return false;
    }
    target /= 2;
    dp[nums[0]] = true;
    dp[0] = true;
    for (int i = 1; i < numsSize; i++) {
        for (int j = target; j >= 1; j--) {
            if (nums[i] <= j) {
                dp[j] = dp[j] | dp[j - nums[i]];
            }
        }
    }
    return dp[target];
}

int canPartition_main()
{
    int nums[] = {3,3,3,4,5};
    bool res;
    res = canPartition(nums, 5);
    printf("Hello World\n");
    printf("res: %d.\n", res);
    system("pause");
    return 0;
}
#endif
#if ALGORITHM_DESCRIPTION("62&63 不同路径")
/* 题目链接 https://leetcode-cn.com/problems/unique-paths-ii/ */
/* 题目描述 62&63 不同路径
一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
问总共有多少条不同的路径？ */
/*
确定dp数组（dp table）以及下标的含义
确定递推公式
dp数组如何初始化
确定遍历顺序
举例推导dp数组

dp[i][j] 到达坐标i,j的不同路径和
dp[i][j] = dp[i-1][j] + dp[i][j-1] 
dp[0][0] = 0;
dp[1][0] = 1;
dp[0][1] = 1;
dp[1][1] = dp[1][0] + dp[0][1] = 2
*/
int uniquePaths(int m, int n){
    int dp[101][101] = {0};
    dp[0][0] = 1;
    int loopI = 1;
    int loopJ = 1;
    for (loopJ = 1; loopJ < m; loopJ++) {
        dp[loopJ][0] = 1;
    }
    for (loopI = 1; loopI < n; loopI++) {
        dp[0][loopI] = 1;
    }
    for (loopJ = 1; loopJ < m; loopJ++) {
        for (loopI = 1; loopI < n; loopI++) {
            dp[loopJ][loopI] = dp[loopJ - 1][loopI] + dp[loopJ][loopI - 1];
        }
    }
    return dp[m-1][n-1];
}

int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int dp[101][101] = {0};
    dp[0][0] = 1;
    int loopI = 1;
    int loopJ = 1;
    for (loopJ = 1; loopJ < obstacleGridSize; loopJ++) {
        if(obstacleGrid[loopJ][0] == 1) {
            dp[loopJ][0] = 0;
        }
        dp[loopJ][0] = 1;
    }
    for (loopI = 1; loopI < *obstacleGridColSize; loopI++) {
        if(obstacleGrid[0][loopI] == 1) {
            dp[0][loopI] = 0;
        }
        dp[0][loopI] = 1;
    }
    for (loopJ = 1; loopJ < obstacleGridSize; loopJ++) {
        for (loopI = 1; loopI < *obstacleGridColSize; loopI++) {
            if(obstacleGrid[loopJ][loopI] == 1) {
                dp[loopJ][loopI] = 0;
                continue;
            }
            dp[loopJ][loopI] = dp[loopJ - 1][loopI] + dp[loopJ][loopI - 1];
        }
    }
    return dp[obstacleGridSize-1][*obstacleGridColSize-1];
}

#endif
#if ALGORITHM_DESCRIPTION("91 解码方法")
/* 链接 https://leetcode-cn.com/problems/decode-ways/ */
/* 题目描述：编码 ：'A' -> 1 'B' -> 2 ... 'Z' -> 26
要 解码 已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。
例如，"11106" 可以映射为："AAJF" ，将消息分组为 (1 1 10 6) 也可以映射为"KJF" ，将消息分组为 (11 10 6)
注意，消息不能分组为  (1 11 06) ，因为 "06" 不能映射为 "F" ，这是由于 "6" 和 "06" 在映射中并不等价。
给你一个只含数字的 非空 字符串 s ，请计算并返回 解码 方法的 总数 。题目数据保证答案肯定是一个 32 位 的整数。
示例 1：输入：s = "226" 输出：3 解释：它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。*/
/*解题思路：确定dp数组（dp table）以及下标的含义，确定递推公式，dp数组如何初始化，确定遍历顺序，举例推导dp数组 */
/* f(x,y) =  */
#define DECODEWAYS_CAN_BE_NUM 0
#define DECODEWAYS_CANNOT_BE_NUM 1
#define DECODEWAYS_EQUALL_PRE_NUM 2
#define DECODEWAYS_EQUALL_PRE_PRE_NUM 3
int DecodeWays_isBeNum(char * s, int index)
{
    if (index == 0) {
        return DECODEWAYS_CANNOT_BE_NUM;
    }
    if (s[index] == '0') {
        if (s[index-1] > '2' || s[index-1] == '0') {
            return DECODEWAYS_CANNOT_BE_NUM;
        }
        return DECODEWAYS_EQUALL_PRE_PRE_NUM;
    } else if (s[index - 1] > '2'|| s[index-1] == '0') {
        return DECODEWAYS_EQUALL_PRE_NUM;
        
    } else if (s[index - 1] == '2' && s[index] > '6') {
        return DECODEWAYS_EQUALL_PRE_NUM;
    } else {
        return DECODEWAYS_CAN_BE_NUM;
    }
}
int DecodeWays_numDecodings(char * s){
    int sLen = strlen(s);
    if (sLen == 0 || s[0] == '0') {
        return 0;
    }
    int tmpArr[1000] = {0};
    tmpArr[0] = 1;
    tmpArr[1] = 1;
    for (int i = 1; i < sLen; i++) {
        int tmp = DecodeWays_isBeNum(s, i);
        switch (tmp) 
        {
        case DECODEWAYS_CANNOT_BE_NUM:
            return 0;
        case DECODEWAYS_CAN_BE_NUM:
            tmpArr[i + 1] = tmpArr[i]+tmpArr[i-1];
            break;
        case DECODEWAYS_EQUALL_PRE_NUM:
            tmpArr[i + 1] = tmpArr[i];
            break;
        case DECODEWAYS_EQUALL_PRE_PRE_NUM:
            tmpArr[i + 1] = tmpArr[i-1];
            break;
        default:
            break;
        }
    }
    return tmpArr[sLen];
}
int testDecodeWays_numDecodings()
{
    char *s = "226";
    int result = DecodeWays_numDecodings(s);
    ALGORITHM_INFO_LOG("result %d \n", result);
    return result;
}

#endif

#if ALGORITHM_DESCRIPTION("152 乘积最大子数组")
/* 链接 https://leetcode-cn.com/problems/maximum-product-subarray/ */
/* 题目描述：给你一个整数数组 nums ，请你找出数组中乘积最大的连续子数组（该子数组中至少包含一个数字），并返回该子数组所对应的乘积。
示例 1: 输入: [2,3,-2,4] 输出: 6 解释: 子数组 [2,3] 有最大乘积 6。*/
/*解题思路：因为存在负数，所以同时保存最大值和最小值 */
int MaxProductSubArr_getMaxValue(int preMax, int preMin, int value) 
{
    int tempMax = preMax * value;
    int tempMin = preMin * value;
    if (tempMax > value) {
        if (tempMax > tempMin) {
            return tempMax;
        } else {
            return tempMin;
        }
    } else {
        if (value > tempMin) {
            return value;
        } else {
            return tempMin;
        }
    }
}
int MaxProductSubArr_getMinValue(int preMax, int preMin, int value) 
{
    int tempMax = preMax * value;
    int tempMin = preMin * value;
    if (tempMax > value) {
        if (value > tempMin) {
            return tempMin;
        } else {
            return value;
        }
    } else {
        if (tempMax > tempMin) {
            return tempMin;
        } else {
            return tempMax;
        }
    }
}

int maxProduct(int* nums, int numsSize){
    if (numsSize == 0) {
        return 0;
    }
    int result = nums[0];
    int maxProduct = nums[0];
    int minProduct = nums[0];
    int tmpMaxArray;
    int tmpMinArray;
    for (int i = 1; i < numsSize; i++) {
        tmpMaxArray = MaxProductSubArr_getMaxValue(maxProduct, minProduct, nums[i]);
        tmpMinArray = MaxProductSubArr_getMinValue(maxProduct, minProduct, nums[i]);
        maxProduct = tmpMaxArray;
        minProduct = tmpMinArray;
        if (result < tmpMaxArray) {
            result = tmpMaxArray;
        }
    }
    return result;
}

#endif