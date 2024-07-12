#ifndef ALGORITHM_HASHTABLE
#define ALGORITHM_HASHTABLE

#include "algorithm_utils.h"

typedef struct hashDataNode {
    void *data;
    struct hashDataNode *next;
} HashDataNode;

typedef HashDataNode *HashTableNode; //hash表的表节点

/* 比较key是否相等的函数指针，可自定义比较函数 */
typedef int (*AlgorithmHashCompareFunc)(const void *dataA, const void *dataB);
typedef unsigned int (*AlgorithmHashGetHashFunc)(void* data, unsigned int size);

typedef struct hashTable {
    unsigned int tableSize;
    HashTableNode *table;
    AlgorithmHashGetHashFunc hashFunc;
} HashTable;

#if ALGORITHM_DESCRIPTION ("哈希表接口")

int Algorithm_HASH_InitTable(HashTable *hashTable, unsigned int tableSize, AlgorithmHashGetHashFunc hashFunc);
HashDataNode *Algorithm_HASH_CreateHashNode(void *data, unsigned int dataSize);
int Algorithm_HASH_FrontInsert(HashTable *hashTable, void *data, unsigned int dataSize);
int Algorithm_HASH_RearInsert(HashTable *hashTable, void *data, unsigned int dataSize);
int Algorithm_HASH_SpecifyInsert(HashTable *hashTable, void *data, unsigned int dataSize, AlgorithmHashCompareFunc compare);
int Algorithm_HASH_RemoveHashNode(HashTable *hashTable, void *data, AlgorithmHashCompareFunc compare);
HashDataNode *Algorithm_HASH_FindHashNode(HashTable *hashTable, void *data, AlgorithmHashCompareFunc compare);
void Algorithm_HASH_FreeHashNode(HashDataNode *node);
void Algorithm_HASH_Release(HashTable *hashTable);

#endif

#if ALGORITHM_DESCRIPTION("哈希算法")

unsigned int HashTable_StrHashFunc(char* key, unsigned int tableSize);
unsigned int HashTable_IntHashFunc(int key, unsigned int tableSize);

#endif

#if ALGORITHM_DESCRIPTION("哈希表打印接口 打印哈希表信息")

#define HASH_TABLE_PRINTALL 1
#define HASH_TABLE_PRINTTABLE 0
void HashTable_Debug_PrintHashTable(HashTable *hashTable, int pos, int flag);
/* 打印哈希表内容， flag：HASH_TABLE_PRINTALL 打印整个hashtable，HASH_TABLE_PRINTTABLE打印指定表 */
void HashTable_Debug_PrintHashTableAddress(HashTable *hashTable);

#endif


#if ALGORITHM_DESCRIPTION ("哈希表 其他非公共接口")
void testTwoSum();
void testThreeSum();
#endif


#endif