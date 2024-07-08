#ifndef ALGORITHM_BINARY_TREE
#define ALGORITHM_BINARY_TREE

#include "algorithm_utils.h"
#if ALGORITHM_DESCRIPTION("二叉树 基础数据结构")
typedef struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
}BinTreeNode;
typedef struct listNodeForBT {
    BinTreeNode *node;
    struct listNodeForBT *prev;
    struct listNodeForBT *next;
} listBTNode;
#endif

#if ALGORITHM_DESCRIPTION("顺序存储 双亲表示法的数据结构")
#define MAX_PARENT_TREE_SIZE 100
typedef struct ParentNode
{
    int iValue;
    int parent; /* 双亲位置 */
}ParentNode;
typedef struct ParentTree
{
    ParentNode nodes[MAX_PARENT_TREE_SIZE];
    int rootPositon;   /* 根节点位置 */
    int nodesNum;   /* 节点数目 */
}ParentTree;
#endif

#if ALGORITHM_DESCRIPTION("顺序+链式存储 孩子双亲表示法的数据结构")
#define MAX_CHILD_TREE_SIZE 100
typedef struct ChildNode {
    int iValue;
    int child; /* 孩子个数 */
    struct ChildNode *next; /* 孩子链表的开始位置 */
    struct ChildNode *parent; /* 改进，保存双亲位置 */
}ChildNode;
typedef struct ChildTree
{
    ChildNode nodes[MAX_CHILD_TREE_SIZE];
    int nodesNum;   /* 节点数目 */
}ChildTree;
#endif

#if ALGORITHM_DESCRIPTION("顺序+链式存储 孩子兄弟表示法的数据结构")
#define MAX_CHILDSIB_TREE_SIZE 100
typedef struct ChildSibNode
{
    int iValue;
    struct ChildSibNode *firstChild; /* 第一个孩子节点的位置 */
    struct ChildSibNode *rightSib; /* 右边兄弟节点的位置 */
    struct ChildSibNode *parent; /* 改进，双亲节点的位置 */
}ChildSibNode, *ChildSibTree;
#endif

#if ALGORITHM_DESCRIPTION("二叉树 数组队列和栈数据结构")
#define TreeNodeStack_MAXSIZE 100000
typedef struct treeNodeStack
{
    void *node[TreeNodeStack_MAXSIZE];
    int top;
}TreeNodeStack;
int TreeNodeStack_POP(TreeNodeStack *stack, void **node);
int TreeNodeStack_PUSH(TreeNodeStack *stack, void *node);
int TreeNodeStack_isEmpty(TreeNodeStack *stack);
void *TreeNodeStack_TOP(TreeNodeStack *stack);

#define TreeNodeQueue_MAXSIZE 100000
typedef struct treeNodeQueue
{
    void *node[TreeNodeQueue_MAXSIZE];
    int usedBuffer;
    int head;
    int tail;
}TreeNodeQueue;
int TreeNodeQueue_POP(TreeNodeQueue *queue, void **node);
int TreeNodeQueue_PUSH(TreeNodeQueue *queue, void *node);
int TreeNodeQueue_isEmpty(TreeNodeQueue *queue);
int TreeNodeQueue_QueueUsedSize(TreeNodeQueue *queue);

#endif


#if ALGORITHM_DESCRIPTION("二叉树 遍历接口")
/* 递归法接口 */
int **levelOrderTraversal(struct TreeNode *root, int *returnSize, int **returnColumnSizes);
int *preorderTraversal(struct TreeNode *root, int *returnSize);
int* inorderTraversal(struct TreeNode* root, int* returnSize);
int *postorderTraversal(struct TreeNode *root, int *returnSize);
/* 迭代法接口 */
int **levelOrderTraversalIterateWay(struct TreeNode *root, int *returnSize, int **returnColumnSizes);
int *preorderTraversalIterateWay(struct TreeNode *root, int *returnSize);
int *inorderTraversalIterateWay(struct TreeNode *root, int *returnSize);
int *postorderTraversalIterateWay(struct TreeNode *root, int *returnSize);
/* 测试二叉树的层序遍历 */
void testlevelOrderTraversalIterateWay();

#endif

#if ALGORITHM_DESCRIPTION("二叉树 创建二叉树接口")
/* 根据数组创建完全二叉树 */
BinTreeNode *BinTree_CreateCompleteTreeByArray(int *arr, int arrLen);
/* 根据字符串创建二叉树 形如："[3,9,20,null,null,15,7,null,1]"*/
struct TreeNode *BinTree_CreateTreeByArray(char *s);
void BinTree_TestCreateTreeByArray();
char **BinTree_SplitStringArray(char *s, int *subStrSize);
void BinTree_TestSplitStringArray();

#endif

#if ALGORITHM_DESCRIPTION("二叉树 打印二叉树接口")
#define PrintBinaryTree_STARTPOS 50
#define PrintBinaryTree_INTERVALPOS 12
#define PrintBinaryTree_TREELEVELMAXSIZE 10001
typedef struct printTreeNode {
     void *node;
     int printPos;
}PrintTreeNode;

void BinTree_PrintBinaryTreeByTree(struct TreeNode *root);
void BinTree_PrintBinaryTreeByString(char *s);
void BinTree_TestPrintBinaryTreeByString();

#endif

/* 获取二叉树的最大深度 */
int getMaxDeepLenth(BinTreeNode *root);

/*测试镜像对称*/
void testBinaryTree();
bool isSymmetric(BinTreeNode *root);
#endif