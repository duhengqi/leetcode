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

struct Status {
    int lSum, rSum, mSum, iSum;
};

struct Status pushUp(struct Status l, struct Status r) {
    int iSum = l.iSum + r.iSum;
    int lSum = fmax(l.lSum, l.iSum + r.lSum);
    int rSum = fmax(r.rSum, r.iSum + l.rSum);
    int mSum = fmax(fmax(l.mSum, r.mSum), l.rSum + r.lSum);
    return (struct Status){lSum, rSum, mSum, iSum};
};

struct Status get(int* a, int l, int r) {
    if (l == r) {
        return (struct Status){a[l], a[l], a[l], a[l]};
    }
    int m = (l + r) >> 1;
    struct Status lSub = get(a, l, m);
    struct Status rSub = get(a, m + 1, r);
    return pushUp(lSub, rSub);
}

int maxSubArray(int* nums, int numsSize) {
    return get(nums, 0, numsSize - 1).mSum;
}
/*
作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/maximum-subarray/solution/zui-da-zi-xu-he-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#endif
