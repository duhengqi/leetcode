#include "stdio.h"
#include "stdlib.h"
#include "stdbool.h"
#include "algorithm_utils.h"

/* 获取阶乘结果 */
int Algorithm_Get_Gactorial(int value)
{
    if (value < 2) {
        return 1;
    }
    int result = 1;
    for (int loop = 1; loop <= value; loop++ ) {
        result *= loop;
    }
    return result;
}

/* 获取这个数是几位数，8是1位，18是两位 */
int Algorithm_GetNumberOfDigits(int value)
{
    int result = 1;
    while (value/10 != 0) {
        value = value / 10;
        result++;
    }
    //ALGORITHM_INFO_LOG("%d NumberOfDigits is %d.\n",value, result);
    return result;
}