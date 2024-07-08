#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "algorithm_string.h"
#include "algorithm_utils.h"
#if ALGORITHM_DESCRIPTION("1593 拆分字符串使唯一子字符串的数目最大")
/* 链接：https://leetcode-cn.com/problems/split-a-string-into-the-max-number-of-unique-substrings/ */
/* 题目：1593. 拆分字符串使唯一子字符串的数目最大
给你一个字符串 s ，请你拆分该字符串，并返回拆分后唯一子字符串的最大数目。
字符串 s 拆分后可以得到若干 非空子字符串 ，这些子字符串连接后应当能够还原为原字符串。但是拆分出来的每个子字符串都必须是 唯一的 。
注意：子字符串 是字符串中的一个连续字符序列。
示例 1：输入：s = "ababccc" 输出：5
解释：一种最大拆分方法为 ['a', 'b', 'ab', 'c', 'cc'] 。像 ['a', 'b', 'a', 'b', 'c', 'cc'] 这样拆分不满足题目要求，因为其中的 'a' 和 'b' 都出现了不止一次。*/
bool isRecordRepeat(char **record, int recordSize, char* s, int sLen)
{
    for (int i = 0; i < recordSize; i++) {
        if (strlen(record[i]) == sLen && strncmp(record[i],s,sLen) == 0) {
            return true;
        }
    }
    if (sLen == strlen(s) - sLen) {
        if (strncmp(s,s+sLen,sLen) == 0) {
            return true;
        }
    }
    return false;
}
int maxUniqueSplitTw(char * s){
    int sLen = strlen(s);
    if (sLen <= 1) {
        return sLen;
    }

    int result = 0;
    char **record = (char **)malloc(sizeof(char *) * sLen);
    int recordSize = 0;
    for (int i = 0; i < sLen; i ++) {
        record[i] = (char *)malloc(sizeof(char) * (sLen+1));
        memset(record[i], 0, (sLen+1));
    }
    int pointHead = 0;
    int pointTail = 0;

    for (; pointTail < sLen; pointTail++) {
        if (isRecordRepeat(record, recordSize, s+pointHead, pointTail - pointHead + 1)) {            
            continue;
        } else {
            memcpy(record[recordSize], s + pointHead, pointTail - pointHead + 1);
            recordSize++;
            result++;
            pointHead = pointTail + 1;
        }

    }
    
    for (int i = 0; i < recordSize; i++) {
        free(record[i]);
    }
    free(record);
    return result;
}
int maxUniqueSplit(char * s){
    int sLen = strlen(s);
    if (sLen <= 1) {
        return sLen;
    }
    int resultMax = 0;
    int result = 0;
    char *sAfter = (char *)malloc(sizeof(char) * (sLen+1));
    memset(sAfter, 0, sLen + 1);
    for (int i = 1; i < sLen; i++) {
        strncpy(sAfter + i, s, sLen - i);
        strncpy(sAfter, s + sLen - i, i);
        ALGORITHM_INFO_LOG("%s\n", sAfter);
        result = maxUniqueSplitTw(sAfter);
        if (result > resultMax) {
            resultMax = result;
        }
    }
    return resultMax;
}

int maxUniqueSplit_main()
{
    char s[] = "wwwzfvedwfvhsww";
    int result = maxUniqueSplit(s);
    ALGORITHM_INFO_LOG("%d\n", result);
    system("pause");
    return 0;
}
#endif

#if ALGORITHM_DESCRIPTION("字符串 C语言库函数")
/* 函数返回 str1 中第一个不在字符串 str2 中出现的字符下标。 */
int testStrSpn()
{
    int len;
    const char str1[] = "ABCDEFG019874";
    const char str2[] = "ABCD";

    len = strspn(str1, str2);

    ALGORITHM_INFO_LOG("初始段匹配长度 %d\n", len);

    return (0);
}
/* 函数返回被分解的第一个子字符串，如果没有可检索的字符串，则返回一个空指针。原字符串的改动是分隔符原位置均更改为 '\0'
 */
int testStrtok()
{
    char str[80] = "This is - www.runoob.com - website";
    const char s[2] = "-";
    char *token;

    /* 获取第一个子字符串 */
    token = strtok(str, s);

    /* 继续获取其他的子字符串 */
    while (token != NULL) {
        ALGORITHM_INFO_LOG("%s\n", token);
        token = strtok(NULL, s);
    }

    return (0);
}
/* 检索字符串 str1 中第一个匹配字符串 str2 中字符的字符，不包含空结束字符。
也就是说，依次检验字符串 str1 中的字符，当被检验字符在字符串 str2 中也包含时，则停止检验，并返回该字符位置。 */
int testStrpbrk()
{
    const char str1[] = "abcde2fghi3jk4l";
    const char str2[] = "34";
    char *ret;

    ret = strpbrk(str1, str2);
    if (ret) {
        ALGORITHM_INFO_LOG("第一个匹配的字符是： %c\n", *ret);
    } else {
        ALGORITHM_INFO_LOG("未找到字符");
    }

    return (0);
}
/* 在参数 str 所指向的字符串中搜索第一次出现字符 c（一个无符号字符）的位置。 */
int testStrchr()
{
    const char str[] = "http://www.runoob.com";
    const char ch = '.';
    char *ret;

    ret = strchr(str, ch);
    ALGORITHM_INFO_LOG("|%c| 之后的字符串是 - |%s|\n", ch, ret);

    return (0);
}
#endif