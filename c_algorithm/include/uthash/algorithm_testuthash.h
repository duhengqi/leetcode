#ifndef LEARN_ALGORITHM_TEST_UTHASH
#define LEARN_ALGORITHM_TEST_UTHASH

#include "algorithm_utils.h"

typedef struct testListNode {
    int num;
    struct testListNode *prev;
    struct testListNode *next;
} testUtistNode;

void testUtarry();
void testUtlist();
#endif