#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "algorithm_array.h"
#include "algorithm_utils.h"

#if ALGORITHM_DESCRIPTION("数组实现队列")

int CycleQueue_IsEmpty(CycleQueue *queue)
{
    return queue->usedBuffer == 0;
}
int CycleQueue_IsFull(CycleQueue *queue)
{
    return queue->usedBuffer == CYCLE_QUEUE_MAX_SIZE;
}
int CycleQueue_Size(CycleQueue *queue)
{
    return queue->usedBuffer;
}
int CycleQueue_POP(CycleQueue *queue, int* value)
{
    if (CycleQueue_IsEmpty(queue)) {
        return ALGORITHM_ERR;
    }
    /* 数据拷贝，可以提取出来 */
    *value = queue->data[queue->tail];
    queue->usedBuffer--;
    queue->tail++;
    if (queue->tail == CYCLE_QUEUE_MAX_SIZE) {
        queue->tail = 0;
    }
    return ALGORITHM_OK;
}
int CycleQueue_PUSH(CycleQueue *queue, int value)
{
    if (CycleQueue_IsFull(queue)) {
        return ALGORITHM_ERR;
    }
    /* 数据拷贝，可以提取出来 */
    queue->data[queue->head] = value;
    queue->usedBuffer++;
    queue->head++;
    if (queue->head == CYCLE_QUEUE_MAX_SIZE) {
        queue->head = 0;
    }
    return ALGORITHM_OK;
}

void CycleQueue_PrintQueue(CycleQueue *queue)
{
    if (CycleQueue_IsEmpty(queue)) {
        return;
    }
    int queueSize = CycleQueue_Size(queue);
    int i, j;
    for (i = queue->tail, j = 0; j < queueSize; i++, j++) {
        if (i == CYCLE_QUEUE_MAX_SIZE ) {
            i = 0;
        }
        ALGORITHM_INFO_LOG("queue index: %d, value: %d.\n", i, queue->data[i]);
    }
}

#endif

#if ALGORITHM_DESCRIPTION("数组公共接口")
#endif

#if ALGORITHM_DESCRIPTION("长度最小的子数组")
/* 链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum/ */
/* 题目：209. 长度最小的子数组 
描述：给定一个含有 n 个正整数的数组和一个正整数 target 。
找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。
如果不存在符合条件的子数组，返回 0 。
输入：target = 7, nums = [2,3,1,2,4,3] 输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。*/
/* 解法：重点在于连续子数组，那就不能找到最大的直接相加。从暴力解法，优化到滑动窗口 */
int minSubArrayLen(int target, int* nums, int numsSize)
{
    unsigned int retSize = 0;
    unsigned int retTmp = 0;
    unsigned int loopI;
    unsigned int loopJ;
    unsigned int sum;

    for (loopI = 0; loopI < numsSize; loopI++) {
        sum = 0;
        for (loopJ = loopI; loopJ < numsSize; loopJ++) {
            sum += nums[loopJ];
            if (sum >= target) {
                retTmp = loopJ - loopI + 1;
                break;
            }
        }
        if (retSize == 0 && retTmp != 0) {
            retSize = retTmp;
        }
        if (retTmp != 0 && retTmp < retSize) {
            retSize = retTmp;
        }
    }
    return retSize;
}
#endif

#if ALGORITHM_DESCRIPTION("移除元素 双指针法")
/* 链接：https://leetcode-cn.com/problems/remove-element */
/*
题目描述：
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用 O(1) 额外空间并 原地 修改输入数组。
*/
/* 示例：输入：nums = [0,1,2,2,3,0,4,2], val = 2
输出：5, nums = [0,1,4,0,3] */
/* 解题思路： 1,双指针法：题目描述中，不关心数组最终的顺序，那么可以定义两个指针，当head指向的元素等于val时，
   从tail指针找到不等于val的填充上。*/
int removeElement(int* nums, int numsSize, int val){
    int equalValNum = 0;
    int headPoint = 0;
    int tailPoint = numsSize - 1;
    if (numsSize == 0) {
        return 0;
    }
    while (headPoint <= tailPoint) {
        if (nums[headPoint] == val) {
            if (nums[tailPoint] == val) {
                equalValNum++;
                tailPoint--;
            } else {
                nums[headPoint] = nums[tailPoint];
                headPoint++;
                tailPoint--;
                equalValNum++;
            }
        } else {
            headPoint++;
        }
        if (equalValNum == numsSize) {
            return numsSize - equalValNum;
        }
    }
    return numsSize - equalValNum;
}

int testRemoveElement() {
    int numArr[] = { 0, 1, 2, 2, 3, 0, 4, 2 };
    int numArrLen = sizeof(numArr) / sizeof(int);
    int val = 2;
    int resArrSize = 0;

    resArrSize = removeElement(numArr, numArrLen, val);
    ALGORITHM_INFO_LOG("%d \n", resArrSize);
    for (int i = 0; i < resArrSize; i++) {
        ALGORITHM_INFO_LOG("%d ", numArr[i]);
    }
    ALGORITHM_INFO_LOG("\n");
    return 0;
}
#endif

#if ALGORITHM_DESCRIPTION("洗牌算法 384 打乱数组")
/* 链接：https://leetcode-cn.com/problems/minimum-size-subarray-sum/ */
/* 题目：给你一个整数数组 nums ，设计算法来打乱一个没有重复元素的数组。
实现 Solution class:
Solution(int[] nums) 使用整数数组 nums 初始化对象
int[] reset() 重设数组到它的初始状态并返回
int[] shuffle() 返回数组随机打乱后的结果

示例：输入 ["Solution", "shuffle", "reset", "shuffle"] [[[1, 2, 3]], [], [], []]
输出 [null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]
解释
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // 打乱数组 [1,2,3] 并返回结果。任何 [1,2,3]的排列返回的概率应该相同。例如，返回 [3, 1, 2]
solution.reset();      // 重设数组到它的初始状态 [1, 2, 3] 。返回 [1, 2, 3]
solution.shuffle();    // 随机返回数组 [1, 2, 3] 打乱后的结果。例如，返回 [1, 3, 2] */
/* 解法：https://cloud.tencent.com/developer/article/1462951 */
#endif

#if ALGORITHM_DESCRIPTION("位图 78 子集")
/* 链接：https://leetcode-cn.com/problems/subsets/ */
/* 题目：给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。
示例 1： 输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]] */
int** subsetsBitMap(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    if (numsSize == 0) {
        return NULL;
    }
    int tmpResult[100] = {0};
    int tmpSize = 0;
    int **resultArr = NULL;
    int resSize = 1 << numsSize;

    resultArr = (int **)malloc(sizeof(int *) * (1 << numsSize));
    memset(resultArr, 0, sizeof(int *) * (1 << numsSize));
    (*returnColumnSizes) = (int*)malloc(sizeof(int) * (1 << numsSize));
    memset((*returnColumnSizes), 0, sizeof(int) * (1 << numsSize));

    for (int bitMap = 0; bitMap < resSize; bitMap++) {
        memset(tmpResult, 0, 100*sizeof(int));
        tmpSize = 0;
        for (int i = 0; i < numsSize; i++) {
            if ((bitMap & (1<<i)) != 0) {
                tmpResult[tmpSize] = nums[i];
                tmpSize++;
            }
        }
        (*returnColumnSizes)[bitMap] = tmpSize;
        if (tmpSize == 0) {
            continue;
        }
        resultArr[bitMap] = (int *)malloc(sizeof(int) * tmpSize);
        memcpy(resultArr[bitMap], tmpResult, sizeof(int) * tmpSize);
    }

    *returnSize = 1 << numsSize;
    return resultArr;
}
// 迭代法 动态规划
int** subsetsIteration(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **resultArr = NULL;
    int resSize = 1;

    resultArr = (int **)malloc(sizeof(int *) * (1 << numsSize));
    memset(resultArr, 0 , sizeof(int *) * (1 << numsSize));
    (*returnColumnSizes) = (int *)malloc(sizeof(int ) * (1 << numsSize));
    memset((*returnColumnSizes), 0, sizeof(int) * (1 << numsSize));

    for (int i = 0; i < numsSize; i++) {
        int tmpSize = resSize;
        for (int j = 0; j < tmpSize; j++) {
            if (resultArr[j] == NULL) {
                resultArr[resSize] = (int *)malloc(sizeof(int));
                resultArr[resSize][0] = nums[i];
                (*returnColumnSizes)[resSize] = 1;
                resSize++;
                continue;
            }
            resultArr[resSize] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[j] + 1));
            memcpy(resultArr[resSize], resultArr[j], sizeof(int)*(*returnColumnSizes)[j]);
            resultArr[resSize][((*returnColumnSizes)[j])] = nums[i];
            (*returnColumnSizes)[resSize] = (*returnColumnSizes)[j] + 1;
            resSize++;
        }
    }
    *returnSize = resSize;
    return resultArr;
}

void testSubsets()
{
    int nums[] = {1, 2, 3};
    int numsSize = sizeof(nums) / sizeof(int);

    int **resultArr = NULL;
    int returnSize;
    int *returnColumnSizes = NULL;

    resultArr = subsetsBitMap(nums, numsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            if (resultArr[i] == NULL) {
                ALGORITHM_INFO_LOG("result[%d][%d] is NULL", i, j);
                continue;
            }
            ALGORITHM_INFO_LOG("%d ", resultArr[i][j]);
        }
        ALGORITHM_INFO_LOG("\n");
    }

}
#endif

#if ALGORITHM_DESCRIPTION("90 子集II 包含重复元素")

/* 链接：https://leetcode-cn.com/problems/subsets-ii/ */
/* 题目：给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。
示例 1：输入：nums = [1,2,2] 输出：[[],[1],[1,2],[1,2,2],[2],[2,2]] */
/* 解题思路： 如果解题方法中，依赖数据是有序的或者默认数据是有序的，且确认排序对结果没有影响的，可以先排序 */
int SubsetsWithDupCompare(const void* a, const void* b)
{
    return (*(int *)a) > (*(int *)b);
}
int** subsetsWithDup(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int **resultArr = NULL;
    int resSize = 1;
    int levelIndex;
    qsort(nums, numsSize, sizeof(int),SubsetsWithDupCompare);
    resultArr = (int **)malloc(sizeof(int *) * (1 << numsSize));
    memset(resultArr, 0 , sizeof(int *) * (1 << numsSize));
    (*returnColumnSizes) = (int *)malloc(sizeof(int ) * (1 << numsSize));
    memset((*returnColumnSizes), 0, sizeof(int) * (1 << numsSize));

    for (int i = 0; i < numsSize; i++) {
        int tmpSize = resSize;
        int j = 0;
        if (i > 0 && nums[i] == nums[i - 1]) {
            j = levelIndex;
        }
        for (; j < tmpSize; j++) {
            if (resultArr[j] == NULL) {
                resultArr[resSize] = (int *)malloc(sizeof(int));
                resultArr[resSize][0] = nums[i];
                (*returnColumnSizes)[resSize] = 1;
                resSize++;
                continue;
            }

            resultArr[resSize] = (int *)malloc(sizeof(int) * ((*returnColumnSizes)[j] + 1));
            memcpy(resultArr[resSize], resultArr[j], sizeof(int)*(*returnColumnSizes)[j]);
            resultArr[resSize][((*returnColumnSizes)[j])] = nums[i];
            (*returnColumnSizes)[resSize] = (*returnColumnSizes)[j] + 1;
            resSize++;
        }
        levelIndex = tmpSize;
    }
    *returnSize = resSize;
    return resultArr;
}
void testSubsetsWithDup()
{
    int nums[] = {4,4,4,1,4};
    int numsSize = sizeof(nums) / sizeof(int);

    int **resultArr = NULL;
    int returnSize;
    int *returnColumnSizes = NULL;

    resultArr = subsetsWithDup(nums, numsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            if (resultArr[i] == NULL) {
                ALGORITHM_INFO_LOG("result[%d][%d] is NULL", i, j);
                continue;
            }
            ALGORITHM_INFO_LOG("%d ", resultArr[i][j]);
        }
        ALGORITHM_INFO_LOG("\n");
    }

}
#endif