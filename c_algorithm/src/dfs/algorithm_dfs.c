#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "algorithm_dfs.h"
#include "algorithm_utils.h"
#if ALGORITHM_DESCRIPTION("77 组合1")
/* 链接：https://leetcode-cn.com/problems/combinations/ */
/* 题目描述：给定两个整数 n 和 k，返回范围 [1, n] 中所有可能的 k 个数的组合。你可以按 任何顺序 返回答案 */
/*示例 1：输入：n = 4, k = 2
输出：
[ [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],]*/
/* 解题思路：回溯法 */
void dfsCombinePrint(int n, int k, int startIndex, int dep)
{
    if (dep == k) {
        printf("\n");
        return;
    }
    for (int loopI = startIndex+1; loopI <= n; loopI++) {
        printf("%d ", loopI);
        startIndex++;
        dfsCombinePrint(n, k, startIndex,dep+1);
    }
}
void combinePrint(int n, int k)
{
    int startIndex = 0;
    int dep = 1;
    for (int loopI = 1; loopI <= n; loopI++) {
        printf("%d ", loopI);
        startIndex++;
        dfsCombinePrint(n, k, startIndex, dep);
    }
    return;
}
#endif
#if ALGORITHM_DESCRIPTION("216 组合3")
/* 链接：https://leetcode-cn.com/problems/combination-sum-iii/ */
/* 题目描述：找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。
说明：所有数字都是正整数。解集不能包含重复的组合。 */
/* 示例: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]] */
/* 解题思路：回溯法 */
void dfsCombine3Print(int n, int k, int startIndex, int dep, int *arr, int sum)
{
    if (dep == k) {
        if (sum != n) {
            return;
        }
        for (int i = 0; i < k; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    for (int i = startIndex + 1; i <= 9; i++) {
        if (sum + i > n) {
            continue;
        }
        arr[dep] = i;
        startIndex++;
        sum += i;
        dfsCombine3Print(n, k, startIndex, dep+1, arr, sum);
        sum -= i;
    }
}
void combine3Print(int n, int k)
{
    int startIndex = 0;
    int arr[10] = {0};
    for (int loopI = 1; loopI <= 9; loopI++) {
        arr[0] = loopI;
        startIndex++;
        dfsCombine3Print(n, k, startIndex, 1, arr, loopI);
    }
    return;
}
#endif
#if ALGORITHM_DESCRIPTION("46 全排列")
/* 链接：https://leetcode-cn.com/problems/permutations/ */
/* 题目描述：给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。 */
/* 示例 1：输入：nums = [1,2,3] 输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]] */
/* 解题思路：下面的代码算法不合适，应该用dfs+回溯法 */

bool permute_isRepeat(int *arr, int size, int value) 
{
    for (int loop = 0; loop < size; loop++) {
        if (arr[loop] == value) {
            return true;
        }
    }
    return false;
}
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes)
{
    *returnSize = Algorithm_Get_Gactorial(numsSize);
    int **returnArr = NULL;
    returnArr = (int **)malloc(sizeof(int *) * (*returnSize));
    int *columnSizes = (int*)malloc(sizeof(int)*(*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        columnSizes[i] = numsSize;
    }
    *returnColumnSizes = columnSizes;
    int *tempArr = NULL;
    for (int loop = 0; loop < *returnSize; loop++) {
        tempArr = (int *)malloc(sizeof(int) * numsSize);
        for (int loopJ = 0; loopJ < numsSize; loopJ++) {
            tempArr[loopJ] = 100;
        }
        returnArr[loop] = tempArr;
    }
    for (int round = 0; round < numsSize; round++) {
        int rLen = Algorithm_Get_Gactorial(numsSize - round - 1);
        int value = nums[0];
        for (int loop = 0, counter = 0, numsCounter = 0; loop < *returnSize; loop++, counter++)
        {   
            if (counter == rLen) {
                counter = 0;
                numsCounter++;
                if (numsCounter == numsSize) {
                    numsCounter = 0;
                }
                value = nums[numsCounter];
            }
            while (permute_isRepeat(returnArr[loop], round, value)) {
                numsCounter++;
                if (numsCounter == numsSize) {
                    numsCounter = 0;
                }
                value = nums[numsCounter];
            }
            returnArr[loop][round] = value;
        }
    }

    return returnArr;
}

int testPermutations()
{
    int nums[] = {1,2,3,5,4,6,7};
    int numsSize = 7;
    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **returnArr = permute(nums, numsSize, &returnSize, &returnColumnSizes);

    printf("%d\n", returnSize);
    printf("%d\n", *returnColumnSizes);
    for (int i = 0; i < Algorithm_Get_Gactorial(numsSize); i++) {
        for (int j = 0; j < numsSize; j++)
        {
            printf("%d ", returnArr[i][j]);
        }
        printf(" \n");
    }

    for (int j = 0; j < returnSize; j++) {
        free(returnArr[j]);
    }
    free(returnArr);
    return 0;
}
#endif

#if ALGORITHM_DESCRIPTION("151 翻转字符串里的单词")
/* 链接：https://leetcode-cn.com/problems/reverse-words-in-a-string/ */
/* 题目描述：给定一个字符串，逐个翻转字符串中的每个单词。说明： 无空格字符构成一个 单词 。
输入字符串可以在前面或者后面包含多余的空格，但是反转后的字符不能包括。
如果两个单词间有多余的空格，将反转后单词间的空格减少到只含一个。
示例 1： 输入："the sky is blue" 输出："blue is sky the" */

char * reverseWords(char * s){
    int sLen = strlen(s);
    char *resArr = (char*)malloc(sizeof(int)*sLen);
    int resPoint = 0;
    int pointHead = sLen - 1;
    int pointTail = sLen - 1;
    int isSpace = 0;

    memset(resArr, 0, sizeof(int) * sLen);

    while (pointHead > 0) {
        if (s[pointHead - 1] != ' ' && s[pointTail] == ' ') {
            pointHead--;
            pointTail = pointHead;
            continue;
        }

        if (s[pointHead - 1] == ' ' && s[pointTail] != ' ') {
            memcpy(&resArr[resPoint], &s[pointHead], pointTail - pointHead + 1);
            resPoint += pointTail - pointHead + 1;
            resArr[resPoint] = ' ';
            resPoint += 1;
            pointHead--;
            pointTail = pointHead;
            continue;
        }
        if (pointHead != 0) {
            pointHead--;
        }
    }
    if (isSpace == 0) {
        memcpy(&resArr[resPoint], &s[pointHead], pointTail - pointHead + 1);
    }
    if (isSpace == 1) {
        resArr[resPoint-1] = '\0';
    }
    return resArr;
}

int reverseWords_main() {
    char *s = "the sky is blue";
    char *result = NULL;

    result = reverseWords(s);
    printf("result %s", result);

    system("pause");
    return 0;
}
#endif