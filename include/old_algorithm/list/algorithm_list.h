#ifndef ALGORITHM_LIST
#define ALGORITHM_LIST

#include "algorithm_utils.h"

#if ALGORITHM_DESCRIPTION("链表公共接口")

typedef struct algorithmListNode
{
    void* data;
    struct  algorithmListNode *next;
    struct  algorithmListNode *pre; //不用
} AlgorithmListNode;

typedef struct algorithmList
{
    unsigned int usedBuff;
    AlgorithmListNode *head;
} AlgorithmList;

typedef int (*AlgorithmListCompareFunc)(const void *dataA, const void *dataB);

void Algorithm_List_Init(AlgorithmList *list);
AlgorithmListNode* Algorithm_List_CreateListNode(void* data, unsigned int dataSize);
void Algorithm_List_FrontInsert(AlgorithmList *list, void* data, unsigned int dataSize);
void Algorithm_List_RearInsert(AlgorithmList *list, void* data, unsigned int dataSize);
void Algorithm_List_SpecifyInsert(AlgorithmList *list, void* data, unsigned int dataSize, AlgorithmListCompareFunc compare);
int Algorithm_List_DeleteNode(AlgorithmList *list, void* data, AlgorithmListCompareFunc compare);
AlgorithmListNode* Algorithm_List_SearchListNodeByData(AlgorithmList *list, void* data, AlgorithmListCompareFunc compare);
void Algorithm_List_Release(AlgorithmList *list);

#endif

/* 1912. 设计电影租借系统 */
void testMovieRentingSystem_ByList();

#endif