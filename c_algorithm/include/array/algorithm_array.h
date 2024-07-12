#ifndef ALGORITHM_ARR
#define ALGORITHM_ARR

#include "algorithm_utils.h"

#if ALGORITHM_DESCRIPTION("测试数组实现队列")
/* 数组实现队列数据结构 */
#define CYCLE_QUEUE_MAX_SIZE 100
typedef struct CycleQueue {
    int data[CYCLE_QUEUE_MAX_SIZE];
    int usedBuffer;
    int head;
    int tail;
} CycleQueue;
int CycleQueue_IsEmpty(CycleQueue *queue);
int CycleQueue_IsFull(CycleQueue *queue);
int CycleQueue_Size(CycleQueue *queue);
int CycleQueue_POP(CycleQueue *queue, int* value);
int CycleQueue_PUSH(CycleQueue *queue, int value);
void CycleQueue_PrintQueue(CycleQueue *queue);
#endif
/* 长度最小的子数组 */
int minSubArrayLen(int target, int *nums, int numsSize);

int testRemoveElement();
void testSubSet();

#endif