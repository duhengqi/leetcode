#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "algorithm_binarytree.h"
#include "algorithm_utils.h"
#if ALGORITHM_DESCRIPTION("二叉树 栈接口")
int TreeNodeStack_POP(TreeNodeStack* stack, void **node)
{
    if (stack->top == -1) {
        return -1;
    }
    *node = stack->node[stack->top];
    stack->top--;
    return 0;
}

int TreeNodeStack_PUSH(TreeNodeStack* stack, void *node)
{
    if (stack->top == TreeNodeStack_MAXSIZE-1) {
        return -1;
    }

    stack->top++;
    stack->node[stack->top] = node;
    return 0;
}

int TreeNodeStack_isEmpty(TreeNodeStack* stack)
{
    return stack->top == -1;
}

void* TreeNodeStack_TOP(TreeNodeStack* stack)
{
    if (stack->top == -1) {
        return NULL;
    }
    return stack->node[stack->top];
}

#endif

#if ALGORITHM_DESCRIPTION("二叉树 队列(数组)接口")
int TreeNodeQueue_POP(TreeNodeQueue* queue, void **node)
{
    if (queue->usedBuffer == 0) {
        return -1;
    }
    /* 数据拷贝，可以提取出来 */
    *node = queue->node[queue->tail];
    queue->usedBuffer--;
    queue->tail++;
    if (queue->tail == TreeNodeQueue_MAXSIZE) {
        queue->tail = 0;
    }
    return 0;
}

int TreeNodeQueue_PUSH(TreeNodeQueue* queue, void *node)
{
    if (queue->usedBuffer == TreeNodeQueue_MAXSIZE) {
        return -1;
    }
    queue->node[queue->head] = node;
    queue->usedBuffer++;
    queue->head++;
    if (queue->head == TreeNodeQueue_MAXSIZE) {
        queue->head = 0;
    }
    return 0;
}

int TreeNodeQueue_isEmpty(TreeNodeQueue* queue)
{
    return queue->usedBuffer == 0;
}

int TreeNodeQueue_QueueUsedSize(TreeNodeQueue* queue)
{
    return queue->usedBuffer;
}

#endif

#if ALGORITHM_DESCRIPTION("二叉树公共接口")

#define BINTREE_SPLITSTR_MAXSIZE 10000
char** BinTree_SplitStringArray(char* s, int *subStrSize)
{
    unsigned int sLen = strlen(s);
    char *token;
    const char* delim = ",";
    int subStrLen;
    char *subStr = NULL;
    char **result = NULL;
    
    if (s == NULL) {
        ALGORITHM_INFO_LOG("[BINARYTREE] Input string is null.");
        return NULL;
    }
    if (s[0] != '[' || s[sLen - 1] != ']' || s[1] == ']') {
        ALGORITHM_INFO_LOG("[BINARYTREE] Input string is invalid.");
        return NULL;
    }

    char *tmpS = (char *)malloc(sizeof(char) * sLen);
    memset(tmpS, 0, sizeof(char) * sLen);
    /* 开始的'['，和结尾的']'不拷贝*/
    strncpy(tmpS, s+1, sLen - 2);

    (*subStrSize) = 0;
    result = (char **)malloc(sizeof(char *) *BINTREE_SPLITSTR_MAXSIZE);
    memset(result, 0, sizeof(char *) * BINTREE_SPLITSTR_MAXSIZE);
    token = strtok(tmpS, delim);
    subStrLen = strlen(token);
    subStr = (char *)malloc(sizeof(char) * (subStrLen + 1));
    strcpy(subStr, token);
    result[(*subStrSize)] = subStr;
    (*subStrSize)++;
    while (token != NULL) {
        token = strtok(NULL, delim);
        if (token == NULL) {
            break;
        }
        subStrLen = strlen(token);
        subStr = (char *)malloc(sizeof(char) * (subStrLen + 1));
        strcpy(subStr, token);
        result[(*subStrSize)] = subStr;
        (*subStrSize)++;
    }
    free(tmpS);
    return result;
}

void BinTree_TestSplitStringArray()
{
    /* 不能是char *s = "";因为 */
    char *s = "[3,9,20,null,null,15,7,null,1]";
    
    char **resultArr = NULL;
    int subStrSize = 0;

    resultArr = BinTree_SplitStringArray(s, &subStrSize);
    if (resultArr == NULL) {
        ALGORITHM_INFO_LOG("[BINARYTREE] Split String Arrary failed.");
    }
    for (int i = 0; i < subStrSize; i++) {
        ALGORITHM_INFO_LOG("[BINARYTREE]resultArr index: %d, str: %s.\n", i, resultArr[i]);
    }
    for (int i = 0; i < subStrSize; i++) {
        free(resultArr[i]);
    }
    free(resultArr);
    return;
}

void BinTree_CreateTree_FillTreeNode(struct TreeNode **node, char* s)
{
    if (strncmp(s, "null", 4) == 0) {
        *node = NULL;
        return;
    } 
    struct TreeNode *tmpNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    memset(tmpNode, 0, sizeof(struct TreeNode));
    tmpNode->val = atoi(s);
    *node = tmpNode;
    return;
}

/* 根据字符串创建二叉树 形如："[3,9,20,null,null,15,7,null,1]"*/
struct TreeNode* BinTree_CreateTreeByArray(char* s)
{
    int ret = 0;
    char **resultArr = NULL;
    /* subStrSize字符串子串的个数，subStrIndex遍历字符串的索引 */
    int subStrSize = 0;
    int subStrIndex = 0;
    struct TreeNode *root = NULL;
    struct TreeNode *node = NULL;
    /* levelNodeNums表示每层的节点数 */
    int levelNodeNums = 0;
    TreeNodeQueue treeQueue;
    memset(&treeQueue, 0, sizeof(TreeNodeQueue));

    resultArr = BinTree_SplitStringArray(s, &subStrSize);
    if (resultArr == NULL || subStrSize == 0) {
        ALGORITHM_INFO_LOG("[BINARYTREE]CreateTree Split Arrary failed.");
    }

    root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    memset(root, 0, sizeof(struct TreeNode));
    root->val = atoi(resultArr[subStrIndex]);
    subStrIndex++;
    TreeNodeQueue_PUSH(&treeQueue, root);
    while (subStrIndex < subStrSize) {
        levelNodeNums = TreeNodeQueue_QueueUsedSize(&treeQueue);
        for (int i = 0; i < levelNodeNums; i++) {
            ret = TreeNodeQueue_POP(&treeQueue, &node);
            if (subStrIndex >= subStrSize) {
                break;
            }
            BinTree_CreateTree_FillTreeNode(&(node->left), resultArr[subStrIndex]);
            subStrIndex++;
            if (node->left != NULL) {
                ret = TreeNodeQueue_PUSH(&treeQueue, node->left);
            }
            if (subStrIndex >= subStrSize) {
                break;
            }
            BinTree_CreateTree_FillTreeNode(&(node->right), resultArr[subStrIndex]);
            subStrIndex++;
            if (node->right != NULL) {
                ret = TreeNodeQueue_PUSH(&treeQueue, node->right);
            }
        }
    }

    return root;
}

/* 测试创建二叉树的接口 */
void BinTree_TestCreateTreeByArray()
{
    char *s = "[3,9,20,null,null,15,7,null,1]";
    struct TreeNode *root = BinTree_CreateTreeByArray(s);
    int **levelOrderResultArr;
    int returnSize;
    int *returnColumnSizes;
    /* 通过层序遍历测试创建二叉树的接口 */
    levelOrderResultArr = levelOrderTraversalIterateWay(root, &returnSize, &returnColumnSizes);
    if (levelOrderResultArr == NULL) {
        ALGORITHM_INFO_LOG("[BINARYTREE] tree is null.");
    }
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            ALGORITHM_INFO_LOG("[BINARYTREE]level: %d, order %d, value %d.\n", i, j, levelOrderResultArr[i][j]);
        }
    }
    return;
}
/* 获取二叉树的最大深度 */
int BinTree_GetTreeMaxDeepLenth(BinTreeNode* root)
{
    if (root == NULL) {
      return 0;
    }
    BinTreeNode *left = root->left;
    BinTreeNode *right = root->right;
    return (BinTree_GetTreeMaxDeepLenth(left) > BinTree_GetTreeMaxDeepLenth(right) ? BinTree_GetTreeMaxDeepLenth(left) :BinTree_GetTreeMaxDeepLenth(right)) + 1;
}
/* 根据数组创建二叉树 */
BinTreeNode* BinTree_CreateCompleteTreeByArray(int *arr, int arrLen)
{
    BinTreeNode *root = (BinTreeNode *)malloc(sizeof(BinTreeNode) * arrLen);
    for (int i = 0; i < arrLen; i++) {
        root[i].val = arr[i];
        root[i].left = NULL;
        root[i].right = NULL;
    }

    for (int i = 0; i < arrLen / 2; i++) {
        if (2*i+1 <= arrLen-1) {
            root[i].left = &root[2 * i + 1];
        }
        if (2*i+2 <= arrLen-1) {
            root[i].right = &root[2 * i + 2];
        }
    }
    return root;
}
#endif

#if ALGORITHM_DESCRIPTION("二叉树的遍历 递归法")
/* 层序遍历 链接 https://leetcode-cn.com/problems/binary-tree-level-order-traversal/ */
/*解题思路：1, 首先理解传参的含义，返回值是二维数组。传入参数 returnSize是层数，returnColumnSizes 是数组，每层有几个数。返回值是二维数组，就是层序遍历的结果。传参的后两个，都是描述返回值的。*/
#define levelOrderTraversal_TREENODEMAXSIZE 10001
#define levelOrderTraversal_TREELEVELMAXSIZE 1001
void levelOrderTraversalRecursive(struct TreeNode* root, int **resultArr, int *returnSize, int level, int* returnColumnSizes)
{
    if (root == NULL) {
        return;
    }
    if (resultArr[level] == NULL) {
        resultArr[level] = (int*)malloc(sizeof(int) * levelOrderTraversal_TREENODEMAXSIZE);
    }
    if (*returnSize < level) {
        /* 只保存最大的level，避免层数层层累加 */
        *returnSize = level;
    }
    resultArr[level][returnColumnSizes[level]] = root->val;
    returnColumnSizes[level]++;
    levelOrderTraversalRecursive(root->left, resultArr, returnSize, level+1, returnColumnSizes);
    levelOrderTraversalRecursive(root->right, resultArr, returnSize, level+1, returnColumnSizes);
}
int** levelOrderTraversal(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        /* 参数检查不能遗漏，并且层数计为0 */
        *returnSize = 0;
        return NULL;
    }

    int **resultArr = NULL;
    resultArr = (int **)malloc(sizeof(int *) *levelOrderTraversal_TREELEVELMAXSIZE);
    memset(resultArr, 0, sizeof(int *) * levelOrderTraversal_TREELEVELMAXSIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int) *levelOrderTraversal_TREELEVELMAXSIZE);
    memset((*returnColumnSizes), 0, sizeof(int) * levelOrderTraversal_TREELEVELMAXSIZE);
    *returnSize = 0;
    levelOrderTraversalRecursive(root, resultArr, returnSize, 0, *returnColumnSizes);
    /* 层数从0开始，最后要加一 */
    (*returnSize) ++;
    return resultArr;
}
/* 前序遍历 https://leetcode-cn.com/problems/binary-tree-preorder-traversal/ */
#define preorderTraversal_TREENODEMAXSIZE 101
void preorderTraversalRecursive(struct TreeNode* root, int *resultArr, int* returnSize) 
{
    if (root == NULL) {
        return;
    }
    resultArr[(*returnSize)] = root->val;
    (*returnSize)++;
    preorderTraversalRecursive(root->left, resultArr, returnSize);
    preorderTraversalRecursive(root->right, resultArr, returnSize);
}
int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (root == NULL ) {
        *returnSize = 0;
        return NULL;
    }
    int *resultArr = NULL;

    resultArr = (int *)malloc(sizeof(int) * preorderTraversal_TREENODEMAXSIZE);
    *returnSize = 0;
    preorderTraversalRecursive(root, resultArr, returnSize);
    return resultArr;
}
/* 中序遍历 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/ */
#define InorderTraversal_TREENODEMAXSIZE 101
void inorderTraversalRecursive(struct TreeNode* root, int *resultArr, int* returnSize) 
{
    if (root == NULL) {
        return;
    }
    inorderTraversalRecursive(root->left, resultArr, returnSize);
    resultArr[(*returnSize)] = root->val;
    (*returnSize)++;
    inorderTraversalRecursive(root->right, resultArr, returnSize);
}
int* inorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (root == NULL ) {
        *returnSize = 0;
        return NULL;
    }
    int *resultArr = NULL;

    resultArr = (int *)malloc(sizeof(int) * InorderTraversal_TREENODEMAXSIZE);
    *returnSize = 0;
    inorderTraversalRecursive(root, resultArr, returnSize);
    return resultArr;
}
/* 后序遍历 https://leetcode-cn.com/problems/binary-tree-postorder-traversal/ */
#define postorderTraversal_TREENODEMAXSIZE 101
void postorderTraversalRecursive(struct TreeNode* root, int *resultArr, int* returnSize) 
{
    if (root == NULL) {
        return;
    }
    postorderTraversalRecursive(root->left, resultArr, returnSize);
    postorderTraversalRecursive(root->right, resultArr, returnSize);
    resultArr[(*returnSize)] = root->val;
    (*returnSize)++;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize)
{
    if (root == NULL ) {
        *returnSize = 0;
        return NULL;
    }
    int *resultArr = NULL;

    resultArr = (int *)malloc(sizeof(int) * postorderTraversal_TREENODEMAXSIZE);
    *returnSize = 0;
    postorderTraversalRecursive(root, resultArr, returnSize);
    return resultArr;
}
#endif

#if ALGORITHM_DESCRIPTION("二叉树的遍历 迭代法")

/* 链接 https://leetcode-cn.com/problems/binary-tree-level-order-traversal/ */
/*解题思路：1, 首先理解传参的含义，返回值是二维数组。传入参数 returnSize是层数，returnColumnSizes 是数组，每层有几个数。
返回值是二维数组，就是层序遍历的结果。传参的后两个，都是描述返回值的。*/
#define levelOrderTraversal_IterateWay_TREENODEMAXSIZE 10001
#define levelOrderTraversal_IterateWay_TREELEVELMAXSIZE 1001
int** levelOrderTraversalIterateWay(struct TreeNode* root, int* returnSize, int** returnColumnSizes)
{
    if (root == NULL) {
        /* 参数检查不能遗漏，并且层数计为0 */
        *returnSize = 0;
        return NULL;
    }
    int ret;
    /* levelNodeNums表示每层的节点数 */
    int levelNodeNums = 0;
    /* levelNodeIndex用于遍历每层的索引 */
    int levelNodeIndex = 0;
    TreeNodeQueue levelOrderQueue;
    memset(&levelOrderQueue, 0, sizeof(TreeNodeQueue));

    int **resultArr = NULL;
    resultArr = (int **)malloc(sizeof(int *) *levelOrderTraversal_IterateWay_TREELEVELMAXSIZE);
    memset(resultArr, 0, sizeof(int *) * levelOrderTraversal_IterateWay_TREELEVELMAXSIZE);
    *returnColumnSizes = (int*)malloc(sizeof(int) *levelOrderTraversal_IterateWay_TREELEVELMAXSIZE);
    memset((*returnColumnSizes), 0, sizeof(int) * levelOrderTraversal_IterateWay_TREELEVELMAXSIZE);

    TreeNodeQueue_PUSH(&levelOrderQueue, root);
    *returnSize = -1;

    while (!TreeNodeQueue_isEmpty(&levelOrderQueue)) {
        if (levelNodeNums == 0) {
            levelNodeNums = TreeNodeQueue_QueueUsedSize(&levelOrderQueue);
            (*returnSize)++;
            (*returnColumnSizes)[(*returnSize)] = levelNodeNums;
            levelNodeIndex = 0;
            resultArr[(*returnSize)] = (int *)malloc(sizeof(int) * levelNodeNums);
            memset(resultArr[(*returnSize)], 0, sizeof(int) * levelNodeNums);
        }
        //ALGORITHM_INFO_LOG("usedBuffer %d, returnSize %d, levelNodeNums %d, levelNodeIndex %d.\n", TreeNodeQueue_QueueUsedSize(&levelOrderQueue), (*returnSize),levelNodeNums,levelNodeIndex);
        ret = TreeNodeQueue_POP(&levelOrderQueue, &root);
        resultArr[(*returnSize)][levelNodeIndex] = root->val;
        levelNodeIndex++;
        levelNodeNums--;
        if (root->left != NULL) {
            TreeNodeQueue_PUSH(&levelOrderQueue, root->left);
        }
        if (root->right != NULL) {
            TreeNodeQueue_PUSH(&levelOrderQueue, root->right);
        }
    }

    /* 层数从0开始，最后要加一 */
    (*returnSize) ++;
    return resultArr;
}
/* 前序遍历 https://leetcode-cn.com/problems/binary-tree-preorder-traversal/ */
#define preorderTraversal_IterateWay_TREENODEMAXSIZE 101
int* preorderTraversalIterateWay(struct TreeNode* root, int* returnSize)
{
    if (root == NULL ) {
        *returnSize = 0;
        return NULL;
    }

    int ret;
    int *resultArr = NULL;
    struct TreeNode *tmpTreeNode = NULL;

    TreeNodeStack preorderStack;
    memset(&preorderStack, 0, sizeof(TreeNodeStack));
    preorderStack.top = -1;
    resultArr = (int *)malloc(sizeof(int) * preorderTraversal_IterateWay_TREENODEMAXSIZE);
    *returnSize = 0;

    TreeNodeStack_PUSH(&preorderStack, root);
    while (!TreeNodeStack_isEmpty(&preorderStack)) {
        ret = TreeNodeStack_POP(&preorderStack, &tmpTreeNode);
        if (ret == -1) {
            ALGORITHM_INFO_LOG("STACK POP FAILED.\n");
            free(resultArr);
            *returnSize = 0;
            return NULL;
        }
        resultArr[(*returnSize)] = tmpTreeNode->val;
        (*returnSize)++;
        /* 注意顺序，因为栈的性质，所以前序遍历先放右节点 */
        if (tmpTreeNode->right != NULL) {
            ret |= TreeNodeStack_PUSH(&preorderStack, tmpTreeNode->right);
        }
        if (tmpTreeNode->left != NULL) {
            ret |= TreeNodeStack_PUSH(&preorderStack, tmpTreeNode->left);
        } 
        if (ret == -1) {
            ALGORITHM_INFO_LOG("STACK PUSH FAILED.\n");
            free(resultArr);
            *returnSize = 0;
            return NULL;
        }
    }

    return resultArr;
}
/* 中序遍历 https://leetcode-cn.com/problems/binary-tree-inorder-traversal/ */
#define InorderTraversal_IterateWay_TREENODEMAXSIZE 101
int* inorderTraversalIterateWay(struct TreeNode* root, int* returnSize)
{
    if (root == NULL ) {
        *returnSize = 0;
        return NULL;
    }
    int ret;
    int *resultArr = NULL;
    TreeNodeStack preorderStack;

    resultArr = (int *)malloc(sizeof(int) * InorderTraversal_IterateWay_TREENODEMAXSIZE);
    *returnSize = 0;
    memset(&preorderStack, 0, sizeof(TreeNodeStack));
    preorderStack.top = -1;

    //TreeNodeStack_PUSH(&preorderStack, root);
    while (root != NULL || !TreeNodeStack_isEmpty(&preorderStack)) {
        while (root != NULL) {
            ret = TreeNodeStack_PUSH(&preorderStack, root);
            root = root->left;
        }
        ret = TreeNodeStack_POP(&preorderStack, &root);
        resultArr[(*returnSize)] = root->val;
        (*returnSize)++;
        root=root->right;
    }
    return resultArr;
}
/* 后序遍历 https://leetcode-cn.com/problems/binary-tree-postorder-traversal/ */
#define postorderTraversal_IterateWay_TREENODEMAXSIZE 101
int* postorderTraversalIterateWay(struct TreeNode* root, int* returnSize)
{
    int *resultArr = NULL;

    resultArr = (int *)malloc(sizeof(int) * postorderTraversal_IterateWay_TREENODEMAXSIZE);
    *returnSize = 0;

    return resultArr;
}
#endif

#if ALGORITHM_DESCRIPTION("101 对称二叉树")
/* 链接 https://leetcode-cn.com/problems/symmetric-tree/ */
/*题目描述：给定一个二叉树，检查它是否是镜像对称的*/
/*例如，二叉树 [1,2,2,3,4,4,3] 是对称的。*/
bool isisSymmetricByRecursion(BinTreeNode* leftTree, BinTreeNode* rightTree)
{
    bool resultOutSide;
    bool resultInSide;
    if (leftTree == NULL || rightTree == NULL) {
        return false;
    }
    if (leftTree->val != rightTree->val) {
        return false;
    }
    /* 先比较外侧 */
    if (leftTree->left == NULL && rightTree->right == NULL) {
        resultOutSide = true;
    }
    else if (leftTree->left != NULL && rightTree->right != NULL) {
        resultOutSide = isisSymmetricByRecursion(leftTree->left, rightTree->right);
        if (resultOutSide == false) {
            return false;
        }
    } else {
        return false;
    }
    /* 再比较里侧 */
    if (leftTree->right == NULL && rightTree->left == NULL) {
        resultInSide = true;
    } else if (leftTree->right != NULL && rightTree->left != NULL) {
        resultInSide = isisSymmetricByRecursion(leftTree->right, rightTree->left);
        if (resultInSide == false) {
            return false;
        }
    } else {
        return false;
    }

    return true;
}

bool isSymmetric(BinTreeNode* root)
{
    if (root->left == NULL && root->right == NULL) {
        return true;
    }
    if (root->left == NULL || root->right == NULL) {
        return false;
    }

    return isisSymmetricByRecursion(root->left, root->right);
}
#endif

#if ALGORITHM_DESCRIPTION("测试二叉树")
void testlevelOrderTraversalIterateWay()
{
    struct TreeNode root = {0};
    root.val = 3;
    struct TreeNode node1 = {0};
    node1.val = 9;
    struct TreeNode node2 = {0};
    node2.val = 20;
    struct TreeNode node3 = {0};
    node3.val = 15;
    struct TreeNode node4 = {0};
    node4.val = 7;
    root.left = &node1;
    root.right = &node2;
    node2.left = &node3;
    node2.right = &node4;
    int *returnColumnSizes = NULL;
    int **returnArr = NULL;
    int returnSize = 0;
    returnArr = levelOrderTraversalIterateWay(&root, &returnSize, &returnColumnSizes);
} 
void testBinaryTree()
{
        int arr[] = {3, 9, 20, -1, -1, 15, 7};
        int arrLen = sizeof(arr) / sizeof(int);

        /* 创建二叉树 */
        BinTreeNode *root = BinTree_CreateCompleteTreeByArray(arr, arrLen);
        if (root == NULL)
        {
            ALGORITHM_INFO_LOG("create tree failed.\n");
            return;
        }
        /* 测试二叉树的中序遍历 */

        /* 测试 对称二叉树 */
        bool issytric = true;
        issytric = isSymmetric(root);
        ALGORITHM_INFO_LOG("isSymmetric result is %d.\n", issytric);
        free(root);
}

#endif

#if ALGORITHM_DESCRIPTION("打印二叉树")

PrintTreeNode* BinTree_CreatePrintNode(void *node)
{
    PrintTreeNode* printNode = (PrintTreeNode *)malloc(sizeof(PrintTreeNode));
    memset(printNode, 0, sizeof(PrintTreeNode));
    printNode->node = node;
    return printNode;
}
void* BinTree_PrintNode(PrintTreeNode *printNode, int *printedSpace)
{
    if (*printedSpace >= printNode->printPos) {
        ALGORITHM_INFO_LOG("[PRINT BINTREE]printedSpace out.");
        return;
    }
    for (int i = 0; i < printNode->printPos - *printedSpace; i++) {
        ALGORITHM_INFO_LOG(" ");
    }
    *printedSpace = printNode->printPos;
    *printedSpace += 16;
    /* 可以考虑写指定文件 */
    ALGORITHM_INFO_LOG("%p", printNode->node);
}

void BinTree_PrintBinaryTreeByTree(struct TreeNode *root)
{
    if (root == NULL) {
        return;
    }
    int ret;
    /* levelNodeNums表示每层的节点数 */
    int levelNodeNums = 0;
    /* levelNodeIndex用于遍历每层的索引 */
    int levelNodeIndex = 0;
    int level;
    /* 记录每层已经打印了多少空间 */
    int printedSpace = 0;
    PrintTreeNode *printNode;
    TreeNodeQueue levelOrderQueue;
    memset(&levelOrderQueue, 0, sizeof(TreeNodeQueue));

    printNode = BinTree_CreatePrintNode(root);
    printNode->printPos = PrintBinaryTree_STARTPOS;
    TreeNodeQueue_PUSH(&levelOrderQueue, printNode);
    level = -1;

    while (!TreeNodeQueue_isEmpty(&levelOrderQueue)) {
        if (levelNodeNums == 0) {
            ALGORITHM_INFO_LOG("\n");
            levelNodeNums = TreeNodeQueue_QueueUsedSize(&levelOrderQueue);
            level++;
            levelNodeIndex = 0;
            printedSpace = 0;
        }
        ret = TreeNodeQueue_POP(&levelOrderQueue, &printNode);
        BinTree_PrintNode(printNode, &printedSpace);
        levelNodeIndex++;
        levelNodeNums--;
        if (((struct TreeNode*)printNode->node)->left != NULL) {
            PrintTreeNode *tmpNode = BinTree_CreatePrintNode(((struct TreeNode*)printNode->node)->left);
            tmpNode->printPos = printNode->printPos - PrintBinaryTree_INTERVALPOS;
            TreeNodeQueue_PUSH(&levelOrderQueue, tmpNode);
        }
        if (((struct TreeNode*)printNode->node)->right != NULL) {
            PrintTreeNode *tmpNode = BinTree_CreatePrintNode(((struct TreeNode*)printNode->node)->right);
            tmpNode->printPos = printNode->printPos + PrintBinaryTree_INTERVALPOS;
            TreeNodeQueue_PUSH(&levelOrderQueue, tmpNode);
        }
    }
    ALGORITHM_INFO_LOG("\n");
    return;
}
void BinTree_PrintBinaryTreeByString(char* s)
{
    struct TreeNode *root = BinTree_CreateTreeByArray(s);
    BinTree_PrintBinaryTreeByTree(root);
}
void BinTree_TestPrintBinaryTreeByString()
{
    char *s = "[3,9,20,null,null,15,7,null,1]";
    BinTree_PrintBinaryTreeByString(s);
    return;
}
#endif

#if ALGORITHM_DESCRIPTION("105 从前序与中序遍历序列构造二叉树")
/* 链接 https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/ */
/*题目描述：给定一棵树的前序遍历 preorder 与中序遍历  inorder。请构造二叉树并返回其根节点。 */
/*例如，Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7] Output: [3,9,20,null,null,15,7] */
void buildTreeFromPreAndOrderRecursive(struct TreeNode** root, int* preorder, int preorderSize, int* inorder, int inorderSize)
{
    if (preorder == NULL || inorder == NULL || preorderSize == 0 || inorderSize == 0) {
        return;
    }
    (*root) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    memset((*root), 0, sizeof(struct TreeNode));
    (*root)->val = preorder[0];
    if (preorderSize == 1 || inorderSize == 1) {
        return;
    }
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == preorder[0]) {
            buildTreeFromPreAndOrderRecursive(&(*root)->left, preorder + 1, i, inorder, i);
            buildTreeFromPreAndOrderRecursive(&(*root)->right, preorder+1+i, preorderSize-1-i, inorder+1+i, inorderSize-1-i);
            break;
        }
    }
}
struct TreeNode *buildTreeFromPreAndOrder(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
    struct TreeNode *root = NULL;
    if (preorder == NULL || inorder == NULL || preorderSize == 0 || inorderSize == 0) {
        return NULL;
    }
    buildTreeFromPreAndOrderRecursive(&root, preorder, preorderSize, inorder, inorderSize);
    return root;
}
#endif

#if ALGORITHM_DESCRIPTION("106 从中序与后序遍历序列构造二叉树")
/* 链接 https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/ */
/*题目描述：给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树。 */
/*例如，输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7] */
void buildTreeFromInAndPostorderRecursive(struct TreeNode** root,int* inorder, int inorderSize, int* postorder, int postorderSize) {
    if (inorder == NULL || postorder == NULL || inorderSize == 0 || postorderSize == 0) {
        return;
    }
    (*root) = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    memset((*root), 0, sizeof(struct TreeNode));
    (*root)->val = postorder[postorderSize - 1];
    if (inorderSize == 1 || postorderSize == 1) {
        return;
    }
    for (int i = 0; i < inorderSize; i++) {
        if (inorder[i] == postorder[postorderSize-1]) {
            buildTreeFromInAndPostorderRecursive(&((*root)->left), inorder, i, postorder, i);
            buildTreeFromInAndPostorderRecursive(&((*root)->right), inorder+i+1, inorderSize - i-1, postorder+i, postorderSize- i-1);
            break;
        }
    }
}
struct TreeNode* buildTreeFromInAndPostoder(int* inorder, int inorderSize, int* postorder, int postorderSize){
    struct TreeNode *root = NULL;
    buildTreeFromInAndPostorderRecursive(&root, inorder, inorderSize, postorder, postorderSize);
    return root;
}
#endif