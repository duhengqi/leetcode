#include "algorithm_hashtable.h"
#include "algorithm_utils.h"
#include "stdbool.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "algorithm_list.h"

/* 哈希表适合查找与给定值相等记录，不适合范围查找和一对多的数据。 */
#if ALGORITHM_DESCRIPTION("哈希算法，与哈希表类型无关")

unsigned int HashTable_StrHashFunc(char* key, unsigned int tableSize)
{
    char *tmp = key;
    unsigned int sLen = strlen(tmp);
    /* 注意：位运算使用unsigned int，否则出现错误 left shift of by 1 places cannot be represented in type int*/
    unsigned int hashResult = tmp[0];
    for (int i = 0; i < sLen; i++) {
        hashResult = (hashResult << 5) - hashResult + tmp[i];
    }
    return hashResult % tableSize;
}

unsigned int HashTable_IntHashFunc(int key, unsigned int tableSize)
{
    /* 避免负数越界 */
    if(key < 0) {
        key = 0-key;
    }
    return key % tableSize;
}

#endif

#if ALGORITHM_DESCRIPTION ("哈希表 数据接口")

unsigned int Algorithm_HASH_GetHashKey(void* data, int size)
{
    return 0;
}

int Algorithm_HASH_CompareKey(void* dataA, void *dataB)
{
    return 0;
}

#endif

#if ALGORITHM_DESCRIPTION("哈希表 操作接口, 不关心数据类型")
/* 初始化哈希表，不关心哈希表数据，只关心表类型和表大小 */
int Algorithm_HASH_InitTable(HashTable *hashTable, unsigned int tableSize, AlgorithmHashGetHashFunc hashFunc)
{
    if (tableSize == 0 || hashFunc == NULL || hashTable == NULL) {
        return -1;
    }

    hashTable->tableSize = tableSize;
    hashTable->table = (HashTableNode *)malloc(sizeof(HashTableNode) * (tableSize));
    memset(hashTable->table, 0, sizeof(HashTableNode) * (tableSize));
    hashTable->hashFunc = hashFunc;

    return 0;
}

HashDataNode* Algorithm_HASH_CreateHashNode(void* data, unsigned int dataSize)
{
    HashDataNode *node = NULL;

    node = (HashDataNode *)malloc(sizeof(HashDataNode));
    memset(node, 0, sizeof(HashDataNode));
    node->data = (void *)malloc(dataSize);
    memcpy(node->data, data, dataSize);

    return node;
}

int Algorithm_HASH_FrontInsert(HashTable *hashTable,  void *data, unsigned int dataSize)
{
    unsigned int key;
    HashDataNode *newNode = NULL;

    key = (hashTable->hashFunc)(data, hashTable->tableSize);

    newNode = Algorithm_HASH_CreateHashNode(data, dataSize);

    /* 节点插入方式 前插 */
    newNode->next = hashTable->table[key];
    hashTable->table[key] = newNode;

    return 0;
}

int Algorithm_HASH_RearInsert(HashTable *hashTable,  void *data, unsigned int dataSize)
{
    unsigned int key;
    HashDataNode *newNode = NULL;
    HashDataNode *pHead = NULL;

    key = (hashTable->hashFunc)(data, hashTable->tableSize);
    newNode = Algorithm_HASH_CreateHashNode(data, dataSize);

    if (hashTable->table[key] == NULL) {
        hashTable->table[key] = newNode;
    } else {
        pHead = hashTable->table[key];
        while (pHead->next != NULL) {
            pHead = pHead->next;
        }
        pHead->next = newNode;
    }

    return 0;
}

int Algorithm_HASH_SpecifyInsert(HashTable *hashTable, void* data, unsigned int dataSize, AlgorithmHashCompareFunc compare)
{
    unsigned int key;
    HashDataNode *newNode = NULL;
    HashDataNode *pHead = NULL;
    HashDataNode *pre = NULL;

    key = (hashTable->hashFunc)(data, hashTable->tableSize);
    newNode = Algorithm_HASH_CreateHashNode(data, dataSize);

    if (hashTable->table[key] == NULL) {
        hashTable->table[key] = newNode;
        return 0;
    } 
    
    pHead = hashTable->table[key];
    while (pHead != NULL) {
        if (compare(pHead->data, data)) {
            if (pre == NULL) {
                newNode->next = pHead;
                hashTable->table[key] = newNode;
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

    return 0;
}


int Algorithm_HASH_RemoveHashNode(HashTable *hashTable, void *data, AlgorithmHashCompareFunc compare)
{
    int key;
    HashDataNode *curNode = NULL;
    HashDataNode *preNode = NULL;
    HashDataNode *rmNode = NULL;

    key = (hashTable->hashFunc)(data, hashTable->tableSize);

    if (hashTable->table[key] == NULL) {
        ALGORITHM_INFO_LOG("[HASHTABLE]hashtable is null, key is not exist.");
        return -1;
    }

    curNode = hashTable->table[key];
    while (curNode) {
        if (compare(curNode->data, data)) {
            rmNode = curNode;
            break;
        }
        preNode = curNode;
        curNode = curNode->next;
    }

    if (rmNode == NULL) {
        ALGORITHM_INFO_LOG("[HASHTABLE]key is not exist in hashtable.");
        return -1;
    }

    if (preNode == NULL) {
        hashTable->table[key] = hashTable->table[key]->next;
    } else {
        preNode->next = rmNode->next;
    }

    Algorithm_HASH_FreeHashNode(rmNode);

    return 0;
}

HashTableNode Algorithm_HASH_GetTableNode(HashTable *hashTable, void *data)
{
    int key;

    key = (hashTable->hashFunc)(data, hashTable->tableSize);

    return hashTable->table[key];
}

HashDataNode *Algorithm_HASH_FindHashNode(HashTable *hashTable, void *data, AlgorithmHashCompareFunc compare)
{
    int key;

    key = (hashTable->hashFunc)(data, hashTable->tableSize);
    if (hashTable->table[key] == NULL) {
        ALGORITHM_INFO_LOG("[HASHTABLE]hashtable is null,find hash node failed by key.\n");
        return NULL;
    }

    HashDataNode *curNode = hashTable->table[key];
    while (curNode != NULL) {
        if (compare(curNode->data, data)) {
            break;
        }
        curNode = curNode->next;
    }

    return curNode;
}

void Algorithm_HASH_FreeHashNode(HashDataNode *node)
{
    if(node->data != NULL) {
        free(node->data);
        node->data = NULL;
    }
    if (node != NULL) {
        free(node);
        node = NULL;
    }
}

void Algorithm_HASH_Release(HashTable *hashTable)
{
    HashDataNode *rmNode;

    for (int i = 0; i < hashTable->tableSize; i++) {
        if (hashTable->table[i] == NULL) {
            continue;
        }
        HashDataNode *head = hashTable->table[i];
        // 注意：表置NULL，否则print接口访问非法内存
        hashTable->table[i] = NULL; 

        while (head != NULL) {
            rmNode = head;
            head = head->next;
            Algorithm_HASH_FreeHashNode(rmNode);
        }
    }
    return;
}

#endif

#if ALGORITHM_DESCRIPTION("哈希表接口 打印哈希表信息")

void Algorithm_HASH_PrintKVNode(void* node)
{
}

void HashTable_Debug_PrintHashTable(HashTable *hashTable, int key, int flag)
{
    int begin = 0;
    int end = hashTable->tableSize;
    if (flag == HASH_TABLE_PRINTTABLE)
    {
        begin = key;
        end = key + 1;
    }
    for (int i = begin; i < end; i++)
    {
        if (hashTable->table[i] == NULL)
        {
            //ALGORITHM_INFO_LOG("[HASHTABLE]hashtable id %d is null,print hash node failed.", i);
            continue;
        }
        HashDataNode *curNode = hashTable->table[i];
        ALGORITHM_INFO_LOG("[HASHTABLE] print table id %d begin.\n", i);
        while (curNode != NULL)
        {
            //Algorithm_HASH_PrintKVNode(&curNode->kv);
            curNode = curNode->next;
        }
        ALGORITHM_INFO_LOG("[HASHTABLE] print table id %d end.\n", i);
    }
    return;
}
/* 打印HASH表地址 */
void HashTable_Debug_PrintHashTableAddress(HashTable *hashTable)
{
    int begin = 0;
    int end = hashTable->tableSize;
    ALGORITHM_INFO_LOG("[HASHTABLE] print table address %p.\n", hashTable->table);
    for (int i = begin; i < end; i++)
    {
        ALGORITHM_INFO_LOG("[HASHTABLE] print table id %d, address %p.\n", i, hashTable->table[i]);
        if (hashTable->table[i] == NULL)
        {
            continue;
        }
        HashDataNode *curNode = hashTable->table[i];
        while (curNode != NULL)
        {
            ALGORITHM_INFO_LOG("[HASHTABLE] print table id %d, node address %p.\n", i, curNode);
            curNode = curNode->next;
        }
    }
    return;
}
#endif

#if ALGORITHM_DESCRIPTION("1912 设计电影租借系统 困难")

/* 链接：https://leetcode-cn.com/problems/design-movie-rental-system/ */
/* 题目：1912. 设计电影租借系统 
描述：你有一个电影租借公司和 n 个电影商店。你想要实现一个电影租借系统，它支持查询、预订和返还电影的操作。同时系统还能生成一份当前被借出电影的报告。
所有电影用二维整数数组 entries 表示，其中 entries[i] = [shopi, moviei, pricei] 表示商店 shopi 有一份电影 moviei 的拷贝，租借价格为 pricei 。每个商店有 至多一份 编号为 moviei 的电影拷贝。
系统需要支持以下操作：
Search：找到拥有指定电影且 未借出 的商店中 最便宜的 5 个 。商店需要按照 价格 升序排序，如果价格相同，则 shopi 较小 的商店排在前面。如果查询结果少于 5 个商店，则将它们全部返回。如果查询结果没有任何商店，则返回空列表。
Rent：从指定商店借出指定电影，题目保证指定电影在指定商店 未借出 。 
Drop：在指定商店返还 之前已借出 的指定电影。
Report：返回 最便宜的 5 部已借出电影 （可能有重复的电影 ID），将结果用二维列表 res 返回，其中 res[j] = [shopj, moviej] 表示第 j 便宜的已借出电影是从商店 shopj 借出的电影 moviej 。
       res 中的电影需要按 价格 升序排序；如果价格相同，则 shopj 较小 的排在前面；如果仍然相同，则 moviej 较小 的排在前面。如果当前借出的电影小于 5 部，则将它们全部返回。如果当前没有借出电影，则返回一个空的列表。
注意：测试数据保证 rent 操作中指定商店拥有 未借出 的指定电影，且 drop 操作指定的商店 之前已借出 指定电影。*/
/* 解题思路： 理解题目的难度在于快速响应 search 和report接口。 
1，search接口：纯链表是n，可以采用hash表，key是movies，同时有序插入，降低时间复杂度。
2，report接口：使用hash表，也是需要全部遍历。所以需要单独一个链表存放已借出电影。
*/

typedef struct movieInfo{
    int shopID;
    int moveID;
    int price;
    bool isRent;
} MovieInfo;

typedef struct {
    int n;
    HashTable moviesTable;
    AlgorithmList rentMovies;
} MovieRentingSystem;

#define MOVIESYSTEM_MOVIE_MAX 10000

unsigned int movieRentingSystemGetHashFunc(void* data, unsigned int size)
{
    MovieInfo *movieInfo = (MovieInfo *)data;
    return HashTable_IntHashFunc(movieInfo->moveID, size);
}

int movieRentingSystemInsertCompare(const void* a, const void* b) {
    MovieInfo *A = (MovieInfo *)a;
    MovieInfo *B = (MovieInfo *)b;
    if (A->moveID != B->moveID) {
        return 0;
    }

    if (A->price != B->price) {
        return A->price > B->price;
    } else {
        return A->shopID > B->shopID;
    }
}

MovieRentingSystem* movieRentingSystemCreate(int n, int** entries, int entriesSize, int* entriesColSize) {
    MovieInfo movieInfo;
    MovieRentingSystem *movieSystem = (MovieRentingSystem *)malloc(sizeof(MovieRentingSystem));

    memset(movieSystem, 0, sizeof(MovieRentingSystem));
    Algorithm_HASH_InitTable(&movieSystem->moviesTable, MOVIESYSTEM_MOVIE_MAX, movieRentingSystemGetHashFunc);
    Algorithm_List_Init(&movieSystem->rentMovies);

    for (int i = 0; i < entriesSize; i++) {
        movieInfo.shopID = entries[i][0];
        movieInfo.moveID = entries[i][1];
        movieInfo.price = entries[i][2];
        movieInfo.isRent = false;
        Algorithm_HASH_SpecifyInsert(&movieSystem->moviesTable, &movieInfo, sizeof(MovieInfo), movieRentingSystemInsertCompare);
    }
    return movieSystem;
}

int* movieRentingSystemSearch(MovieRentingSystem* obj, int movie, int* retSize) {
    MovieInfo tmpData;
    int *resArr = NULL;
    MovieInfo *movieInfo = NULL;
    HashDataNode *head = NULL;

    tmpData.moveID = movie;
    head = Algorithm_HASH_GetTableNode(&obj->moviesTable, &tmpData);

    *retSize = 0;
    resArr = (int *)malloc(sizeof(int) * 5);

    while (head != NULL) {
        movieInfo = (MovieInfo *)head->data;
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

int movieRentingSystemRentCompare(const void* a, const void* b) {
    MovieInfo *A = (MovieInfo *)a;
    MovieInfo *B = (MovieInfo *)b;

    if (A->price != B->price) {
        return A->price > B->price;
    } else if (A->shopID != B->shopID){
        return A->shopID > B->shopID;
    } else {
        return A->moveID > B->moveID;
    }
}

void movieRentingSystemRent(MovieRentingSystem* obj, int shop, int movie) {
    MovieInfo tmpData;
    MovieInfo *movieInfo = NULL;
    HashDataNode *head = NULL;
    
    tmpData.moveID = movie;
    head = Algorithm_HASH_GetTableNode(&obj->moviesTable, &tmpData);

    while(head != NULL) {
        movieInfo = (MovieInfo *)head->data;
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

    Algorithm_List_SpecifyInsert(&obj->rentMovies, movieInfo, sizeof(MovieInfo), movieRentingSystemRentCompare);

}

int movieRentingSystemSameCompare(const void* a, const void* b) {
    MovieInfo *A = (MovieInfo *)a;
    MovieInfo *B = (MovieInfo *)b;

    return (A->shopID == B->shopID) && (A->moveID == B->moveID);
}

void movieRentingSystemDrop(MovieRentingSystem* obj, int shop, int movie) {
    MovieInfo tmpData;
    MovieInfo *movieInfo = NULL;
    HashDataNode *head = NULL;
    
    tmpData.moveID = movie;
    head = Algorithm_HASH_GetTableNode(&obj->moviesTable, &tmpData);

    while(head != NULL) {
        movieInfo = (MovieInfo *)head->data;
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
    Algorithm_List_DeleteNode(&obj->rentMovies, movieInfo, movieRentingSystemSameCompare);
}

int** movieRentingSystemReport(MovieRentingSystem* obj, int* retSize, int** retColSize) {
    int **resArr = NULL;
    MovieInfo *movieInfo;
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
        movieInfo = (MovieInfo *)head->data;
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

void movieRentingSystemFree(MovieRentingSystem* obj) {
    Algorithm_HASH_Release(&obj->moviesTable);
    Algorithm_List_Release(&obj->rentMovies);
    free(obj);
}

#endif


#if ALGORITHM_DESCRIPTION("1 两数之和")
/* 链接 https://leetcode-cn.com/problems/two-sum/ */
/* 题目描述：给定一个整数数组 nums 和一个整数目标值 target，
请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。你可以按任意顺序返回答案。
示例 1： 输入：nums = [2,7,11,15], target = 9 输出：[0,1] 
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] */
/*解题思路：哈希表 */
typedef struct twoSumData {
    int iKey;
    int value;
} TwoSumData;

unsigned int TwoSumHashFunc(void* data, unsigned int size)
{
    TwoSumData *twoSumData = (TwoSumData *)data;
    return HashTable_IntHashFunc(twoSumData->iKey, size);
}

int TwoSumCompareFunc(const void *dataA, const void *dataB)
{
    TwoSumData *twoSumDataA = (TwoSumData *)dataA;
    TwoSumData *twoSumDataB = (TwoSumData *)dataB;
    return twoSumDataA->iKey == twoSumDataB->iKey;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
    HashTable table = {0};
    HashDataNode *targetNode = NULL;
    int *resultArr = (int*)malloc(sizeof(int)*2);
    *returnSize = 2;

    Algorithm_HASH_InitTable(&table, numsSize, TwoSumHashFunc);
    TwoSumData data = { 0 };

    for (int i = 0; i < numsSize; i++) {
        data.iKey = target - nums[i];
        ALGORITHM_INFO_LOG("[TWOSUM]find key %d.\n", data.iKey);
        targetNode = Algorithm_HASH_FindHashNode(&table, &data, TwoSumCompareFunc);
        if (targetNode == NULL) {
            data.value = i;
            data.iKey = nums[i];
            Algorithm_HASH_RearInsert(&table, &data, sizeof(TwoSumData));
        } else {
            ALGORITHM_INFO_LOG("[TWOSUM]find key %d, result key %d value %d.\n", data.iKey, ((TwoSumData*)targetNode->data)->iKey, ((TwoSumData*)targetNode->data)->value);
            resultArr[0] = i;
            resultArr[1] = ((TwoSumData*)targetNode->data)->value;
            break;
        }
    }
    Algorithm_HASH_Release(&table);
    return resultArr;
}

void testTwoSum()
{
    int nums[] = {0,4,3,0};
    int target = 0;
    int *result = NULL;
    int resultSize = 0;
    result = twoSum(nums, sizeof(nums)/sizeof(int), target, &resultSize);
    if (result == NULL) {
        ALGORITHM_INFO_LOG("[TWOSUM]no result.\n");
        return;
    }
    ALGORITHM_INFO_LOG("[TWOSUM]result[0]:%d, result[1]:%d.\n", result[0],result[1]);
    return;
}

#endif

#if ALGORITHM_DESCRIPTION("15 三数之和")
/* 链接 https://leetcode.cn/problems/3sum/ */
/* 题目描述：15. 三数之和
给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
注意：答案中不可以包含重复的三元组。
示例 1：输入：nums = [-1,0,1,2,-1,-4] 输出：[[-1,-1,2],[-1,0,1]] 
示例 2：输入：nums = [] 输出：[]
示例 3：输入：nums = [0] 输出：[] */
int threeSumCompare(const void* a, const void* b)
{
    return (*(int *)a) > (*(int *)b);
}
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    int a = 0;
    int b = 1;
    int c = numsSize - 1;
    qsort(nums, numsSize, sizeof(int),threeSumCompare);
    if (nums[0] > 0 || numsSize < 3) {
        return NULL;
    }
    for (; a < numsSize - 2 && nums[a] <= 0; a++) {
        for (b = a+1; b < numsSize - 1; b++) {
            if (nums[b] == nums[b+1]) {
                continue;
            }
            for (c =   - 1; c > b; c--) {
                printf("a: %d, b: %d, c: %d.\n", nums[a], nums[b], nums[c]);
                if (nums[a] + nums[b] + nums[c] == 0) {
                    printf("result: a: %d, b: %d, c: %d.\n", nums[a], nums[b], nums[c]);
                    break;
                }
            }
        }
    }

    return NULL;
}

void testThreeSum()
{
    int nums[] = {-1,0,1,2,-1,-4};
    int **result = NULL;
    int resultSize = 0;
    int *returnColumnSizes = NULL;
    result = threeSum(nums, sizeof(nums)/sizeof(int), &resultSize,&returnColumnSizes);
    if (result == NULL) {
        ALGORITHM_INFO_LOG("[threeSum]no result.\n");
        return;
    }
    ALGORITHM_INFO_LOG("[threeSum]result[0]:%d, result[1]:%d.\n", result[0],result[1]);
    return;
}

#endif