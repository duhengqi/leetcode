#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "algorithm_list.h"
#include "algorithm_utils.h"
#if ALGORITHM_DESCRIPTION("链表公共接口")

void Algorithm_List_Init(AlgorithmList *list)
{
    list->usedBuff = 0;
    list->head = NULL;
}

AlgorithmListNode* Algorithm_List_CreateListNode(void* data, unsigned int dataSize)
{
    AlgorithmListNode *node = NULL;

    node = (AlgorithmListNode *)malloc(sizeof(AlgorithmListNode));
    memset(node, 0, sizeof(AlgorithmListNode));
    node->data = (void *)malloc(dataSize);
    memcpy(node->data, data, dataSize);

    return node;
}

void Algorithm_List_FrontInsert(AlgorithmList *list, void* data, unsigned int dataSize)
{
    AlgorithmListNode *newNode = NULL;

    newNode = Algorithm_List_CreateListNode(data, dataSize);

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        newNode->next = list->head;
        list->head = newNode;
    }
    list->usedBuff++;
    return;
}

void Algorithm_List_RearInsert(AlgorithmList *list, void* data, unsigned int dataSize)
{
    AlgorithmListNode *newNode = NULL;
    AlgorithmListNode *pHead = NULL;

    newNode = Algorithm_List_CreateListNode(data, dataSize);

    if (list->head == NULL) {
        list->head = newNode;
    } else {
        pHead = list->head;
        while (pHead->next != NULL) {
            pHead = pHead->next;
        }
        pHead->next = newNode;
    }

    list->usedBuff++;
    return;
}

void Algorithm_List_SpecifyInsert(AlgorithmList *list, void* data, unsigned int dataSize, AlgorithmListCompareFunc compare)
{
    AlgorithmListNode *newNode = NULL;
    AlgorithmListNode *pHead = NULL;
    AlgorithmListNode *pre = NULL;

    newNode = Algorithm_List_CreateListNode(data, dataSize);

    if (list->head == NULL) {
        list->head = newNode;
        list->usedBuff++;
        return;
    } 
    
    pHead = list->head;
    while (pHead != NULL) {
        if (compare(pHead->data, data)) {
            if (pre == NULL) {
                newNode->next = pHead;
                list->head = newNode;
            } else {
                newNode->next = pHead;
                pre->next = newNode;
            }
            break;
        }
        pre = pHead;
        pHead = pHead->next;
    }

    if (pHead == NULL) {
        pre->next = newNode;
    }
    list->usedBuff++;

    return;
}

int Algorithm_List_DeleteNode(AlgorithmList *list, void* data, AlgorithmListCompareFunc compare)
{
    AlgorithmListNode *pHead = NULL;
    AlgorithmListNode *pre = NULL;
    pHead = list->head;

    if (pHead == NULL) {
        ALGORITHM_INFO_LOG("[LIST] list is empty.\n");
        return -1;
    }
 
    while (pHead != NULL) {
        if (compare(pHead->data, data)) {
            break;
        }
        pre = pHead;
        pHead = pHead->next;
    }

    if (pHead == NULL) {
        ALGORITHM_INFO_LOG("[LIST] data not exist in list.\n");
        return -1;
    } 

    if (pre == NULL) {
        list->head = pHead->next;
    } else {
        pre->next = pHead->next;
    }
    
    free(pHead);
    pHead = NULL;

    list->usedBuff--;
    return 0;
}

AlgorithmListNode* Algorithm_List_SearchListNodeByData(AlgorithmList *list, void* data, AlgorithmListCompareFunc compare)
{
    AlgorithmListNode *pHead = NULL;

    pHead = list->head;
    while (pHead != NULL) {
        if (compare(pHead->data, data)) {
            return pHead;
        }
        pHead = pHead->next;
    }

    return NULL;
}

void Algorithm_List_Release(AlgorithmList *list)
{
    AlgorithmListNode *pHead = NULL;
    AlgorithmListNode *freeNode = NULL;

    pHead = list->head;
    while (pHead != NULL) {
        freeNode = pHead;
        pHead = pHead->next;
        free(freeNode);
        freeNode = NULL;
    }
    list->usedBuff = 0;
    return;
}

#endif

#if ALGORITHM_DESCRIPTION("1912 设计电影租借系统 链表实现")
/* 链接：https://leetcode-cn.com/problems/design-movie-rental-system/ */
/* 题目：1912. 设计电影租借系统 
描述：你有一个电影租借公司和 n 个电影商店。你想要实现一个电影租借系统，它支持查询、预订和返还电影的操作。同时系统还能生成一份当前被借出电影的报告。
所有电影用二维整数数组 entries 表示，其中 entries[i] = [shopi, moviei, pricei] 表示商店 shopi 有一份电影 moviei 的拷贝，租借价格为 pricei 。每个商店有 至多一份 编号为 moviei 的电影拷贝。
系统需要支持以下操作：
Search：找到拥有指定电影且 未借出 的商店中 最便宜的 5 个 。商店需要按照 价格 升序排序，如果价格相同，则 shopi 较小 的商店排在前面。如果查询结果少于 5 个商店，则将它们全部返回。如果查询结果没有任何商店，则返回空列表。
Rent：从指定商店借出指定电影，题目保证指定电影在指定商店 未借出 。
Drop：在指定商店返还 之前已借出 的指定电影。
Report：返回 最便宜的 5 部已借出电影 （可能有重复的电影 ID），将结果用二维列表 res 返回，其中 res[j] = [shopj, moviej] 表示第 j 便宜的已借出电影是从商店 shopj 借出的电影 moviej 。res 中的电影需要按 价格 升序排序；如果价格相同，则 shopj 较小 的排在前面；如果仍然相同，则 moviej 较小 的排在前面。如果当前借出的电影小于 5 部，则将它们全部返回。如果当前没有借出电影，则返回一个空的列表。
请你实现 MovieRentingSystem_list 类： 
MovieRentingSystem_list(int n, int[][] entries) 将 MovieRentingSystem_list 对象用 n 个商店和 entries 表示的电影列表初始化。
List<Integer> search(int movie) 如上所述，返回 未借出 指定 movie 的商店列表。
void rent(int shop, int movie) 从指定商店 shop 借出指定电影 movie 。
void drop(int shop, int movie) 在指定商店 shop 返还之前借出的电影 movie 。
List<List<Integer>> report() 如上所述，返回最便宜的 已借出 电影列表。
注意：测试数据保证 rent 操作中指定商店拥有 未借出 的指定电影，且 drop 操作指定的商店 之前已借出 指定电影。*/
/* 示例 1：输入：["MovieRentingSystem_list", "search", "rent", "rent", "report", "drop", "search"]
[[3, [[0, 1, 5], [0, 2, 6], [0, 3, 7], [1, 1, 4], [1, 2, 7], [2, 1, 5]]], [1], [0, 1], [1, 2], [], [1, 2], [2]]
输出： [null, [1, 0, 2], null, null, [[0, 1], [1, 2]], null, [0, 1]] */
typedef struct {
    int shopID;
    int moveID;
    int price;
    bool isRent;
} MovieInfo_list;
typedef struct {
    AlgorithmList allMovies;
    AlgorithmList rentMovies;
} MovieRentingSystem_list;

int movieRentingSystemInsertCompare_list(const void* a, const void* b) {
    MovieInfo_list *A = (MovieInfo_list *)a;
    MovieInfo_list *B = (MovieInfo_list *)b;
    if (A->moveID != B->moveID) {
        return 0;
    }

    if (A->price != B->price) {
        return A->price > B->price;
    } else {
        return A->shopID > B->shopID;
    }
}

MovieRentingSystem_list* movieRentingSystemCreate_list(int n, int** entries, int entriesSize, int* entriesColSize) {
    MovieInfo_list movieInfo;
    MovieRentingSystem_list *movieSystem = (MovieRentingSystem_list *)malloc(sizeof(MovieRentingSystem_list));

    memset(movieSystem, 0, sizeof(MovieRentingSystem_list));
    Algorithm_List_Init(&movieSystem->allMovies);
    Algorithm_List_Init(&movieSystem->rentMovies);

    for (int i = 0; i < entriesSize; i++) {
        movieInfo.shopID = entries[i][0];
        movieInfo.moveID = entries[i][1];
        movieInfo.price = entries[i][2];
        movieInfo.isRent = false;
        Algorithm_List_SpecifyInsert(&movieSystem->allMovies, &movieInfo, sizeof(MovieInfo_list), movieRentingSystemInsertCompare_list);
    }
    return movieSystem;
}

int* movieRentingSystemSearch_list(MovieRentingSystem_list* obj, int movie, int* retSize) {
    int *resArr = NULL;
    MovieInfo_list *movieInfo;
    AlgorithmList *movieList = NULL;
    AlgorithmListNode *head = NULL;
    
    movieList = &obj->allMovies;
    head = movieList->head;

    *retSize = 0;
    resArr = (int *)malloc(sizeof(int) * 5);

    while (head != NULL) {
        movieInfo = (MovieInfo_list *)head->data;
        if (movieInfo->moveID == movie && movieInfo->isRent == false) {
            resArr[(*retSize)] = movieInfo->shopID;
            (*retSize)++;            
        }
        if ((*retSize) == 5) {
            break;
        }
        head = head->next;
    }

    if(*retSize == 0) {
        free(resArr);
        resArr = NULL;
    }
    return resArr;
}

int movieRentingSystemRentCompare_list(const void* a, const void* b) {
    MovieInfo_list *A = (MovieInfo_list *)a;
    MovieInfo_list *B = (MovieInfo_list *)b;

    if (A->price != B->price) {
        return A->price > B->price;
    } else if (A->shopID != B->shopID){
        return A->shopID > B->shopID;
    } else {
        return A->moveID > B->moveID;
    }
}

void movieRentingSystemRent_list(MovieRentingSystem_list* obj, int shop, int movie) {
    MovieInfo_list *movieInfo;
    AlgorithmList *movieList = NULL;
    AlgorithmListNode *head = NULL;
    
    movieList = &obj->allMovies;
    head = movieList->head;
    while(head != NULL) {
        movieInfo = (MovieInfo_list *)head->data;
        if (movieInfo->shopID == shop && movieInfo->moveID == movie) {
            movieInfo->isRent = true;
            break;
        }
        head = head->next;
    }
    if (head == NULL) {
        ALGORITHM_INFO_LOG("[list]movesystem not exist this movie.\n");
        return;
    }
    Algorithm_List_SpecifyInsert(&obj->rentMovies, movieInfo, sizeof(MovieInfo_list), movieRentingSystemRentCompare_list);

}

int movieRentingSystemSameCompare_list(const void* a, const void* b) {
    MovieInfo_list *A = (MovieInfo_list *)a;
    MovieInfo_list *B = (MovieInfo_list *)b;

    return (A->shopID == B->shopID) && (A->moveID == B->moveID);
}

void movieRentingSystemDrop_list(MovieRentingSystem_list* obj, int shop, int movie) {
    MovieInfo_list *movieInfo = NULL;
    AlgorithmList *movieList = NULL;
    AlgorithmListNode *head = NULL;
    
    movieList = &obj->allMovies;
    head = movieList->head;
    while(head != NULL) {
        movieInfo = (MovieInfo_list *)head->data;
        if (movieInfo->shopID == shop && movieInfo->moveID == movie) {
            movieInfo->isRent = false;
            break;
        }
        head = head->next;
    }
    if (head == NULL) {
        ALGORITHM_INFO_LOG("[list]shop %d not exist this movie %d.\n", shop, movie);
        return;
    }
    Algorithm_List_DeleteNode(&obj->rentMovies, movieInfo, movieRentingSystemSameCompare_list);
}

int** movieRentingSystemReport_list(MovieRentingSystem_list* obj, int* retSize, int** retColSize) {
    int **resArr = NULL;
    MovieInfo_list *movieInfo;
    AlgorithmList *movieList = NULL;
    AlgorithmListNode *head = NULL;
    
    movieList = &obj->rentMovies;
    head = movieList->head;

    *retSize = 0;
    resArr = (int **)malloc(sizeof(int*) * 5);
    memset(resArr, 0, sizeof(int *) * 5);

    *retColSize = (int*)malloc(sizeof(int)*5);
    for (int j = 0; j < 5; j++) {
        (*retColSize)[j] = 2;
    }

    while (head != NULL) {
        movieInfo = (MovieInfo_list *)head->data;
        resArr[(*retSize)] = (int *)malloc(sizeof(int)*2);
        resArr[(*retSize)][0] = movieInfo->shopID;
        resArr[(*retSize)][1] = movieInfo->moveID;
        (*retSize)++;

        if ((*retSize) == 5) {
            break;
        }
        head = head->next;
    }

    if(*retSize == 0) {
        free(resArr);
        resArr = NULL;
    }

    return resArr;
}

void movieRentingSystemFree_list(MovieRentingSystem_list* obj) {
    Algorithm_List_Release(&obj->allMovies);
    Algorithm_List_Release(&obj->rentMovies);
    free(obj);
}

void testMovieRentingSystem_ByArray()
{
    /*
    MovieInfo_list *movieInfo;
    AlgorithmList *movieList = NULL;
    AlgorithmListNode *head = NULL;
    int testDataSize1 = 6;
    int testData[6][3] = {{0, 1, 5}, {0, 2, 6}, {0, 3, 7}, {1, 1, 4}, {1, 2, 7}, {2, 1, 5}};
    int testDataSize2 = 19;
    int testData2[19][3] = {{0, 418, 3}, {9, 5144, 46}, {2, 8986, 29}, {6, 1446, 28}, {3, 8215, 97}, {7, 9105, 34}, {6, 9105, 30}, {5, 1722, 94}, {9, 528, 40}, {3, 850, 77}, {3, 7069, 40}, {8, 1997, 42}, {0, 8215, 28}, {7, 4050, 80}, {4, 7100, 97}, {4, 9686, 32}, {4, 2566, 93}, {2, 8320, 12}, {2, 5495, 56}};

    int **entries = NULL;
    int entrySize = testDataSize2;

    entries = (int **)malloc(sizeof(int *) * entrySize);
    for (int i = 0; i < entrySize; i++) {
        entries[i] = (int *)malloc(sizeof(int) * 3);
        memcpy(entries[i], testData2[i], sizeof(int) * 3);
    }
    MovieRentingSystem_list *moveSystem = movieRentingSystemCreate(3, entries, entrySize, NULL);
    movieList = &moveSystem->allMovies;
    head = movieList->head;
    while (head != NULL) {
        movieInfo = (MovieInfo_list *)head->data;
        ALGORITHM_INFO_LOG("moveSystem movies shopId %d, moveID %d, price %d.\n", movieInfo->shopID, movieInfo->moveID, movieInfo->price);
        head = head->next;
    }

    int *retColSize;
    int retSize = 0;
    int **retArr = NULL;
    int *result = NULL;
    result = movieRentingSystemSearch(moveSystem, 7837, &retSize);
    for (int i = 0; i < retSize; i++) {
        ALGORITHM_INFO_LOG("Search result: num %d, shopId %d.\n", i, result[i]);
    }
    result = movieRentingSystemSearch(moveSystem, 5495, &retSize);
    for (int i = 0; i < retSize; i++) {
        ALGORITHM_INFO_LOG("Search result: num %d, shopId %d.\n", i, result[i]);
    }

    movieRentingSystemRent(moveSystem, 4, 7100);

    result = movieRentingSystemSearch(moveSystem, 9105, &retSize);
    for (int i = 0; i < retSize; i++) {
        ALGORITHM_INFO_LOG("Search result: num %d, shopId %d.\n", i, result[i]);
    }
    result = movieRentingSystemSearch(moveSystem, 1446, &retSize);
    for (int i = 0; i < retSize; i++) {
        ALGORITHM_INFO_LOG("Search result: num %d, shopId %d.\n", i, result[i]);
    }

    retArr = movieRentingSystemReport(moveSystem, &retSize, &retColSize);
    for (int i = 0; i < retSize; i++) {
        ALGORITHM_INFO_LOG("report result: num %d, shopId %d, movies %d.\n", i, retArr[i][0], retArr[i][1]);
    }

    result = movieRentingSystemSearch(moveSystem, 9869, &retSize);
    for (int i = 0; i < retSize; i++) {
        ALGORITHM_INFO_LOG("Search result: num %d, shopId %d.\n", i, result[i]);
    }

    movieRentingSystemDrop(moveSystem, 4, 7100);

    //movieRentingSystemFree(moveSystem);
*/
}

#endif
