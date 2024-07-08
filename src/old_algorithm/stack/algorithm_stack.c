/* 栈算法 */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdbool.h"
#include "algorithm_stack.h"
#include "algorithm_utils.h"
#if ALGORITHM_DESCRIPTION("基本计算器 栈接口")

#define BASIC_CALCULATOR_STACKSIZE 10000

typedef struct basicCalculatorStack{
    int data[BASIC_CALCULATOR_STACKSIZE];
    int top;
} BasicCalculatorStack;

int BasicCalculator_StackPush(BasicCalculatorStack* stack, int vlaue)
{
    if (stack->top == BASIC_CALCULATOR_STACKSIZE - 1) {
        ALGORITHM_INFO_LOG("[BasicCalculatorStack]%s stack is full.\n", __func__);
        return -1;
    }
    stack->top++;
    stack->data[stack->top] = vlaue;
    return 0;
}

int BasicCalculator_StackPOP(BasicCalculatorStack* stack, int *vlaue)
{
    if (stack->top == - 1) {
        ALGORITHM_INFO_LOG("[BasicCalculatorStack]%s stack is empty \n", __func__);
        return -1;
    }
    *vlaue = stack->data[stack->top];
    stack->top--;
    return 0;
}

int BasicCalculator_StackTOP(BasicCalculatorStack* stack, int *value)
{
    if (stack->top == - 1) {
        ALGORITHM_INFO_LOG("[BasicCalculatorStack]%s stack is empty \n", __func__);
        return -1;
    }
    *value = stack->data[stack->top];
    return 0;
}

#endif
#if ALGORITHM_DESCRIPTION("150. 逆波兰表达式求值")

/* 链接 https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/ */
/* 题目描述：根据 逆波兰表示法，求表达式的值。
有效的算符包括 +、-、*、/ 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
说明：整数除法只保留整数部分。给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。*/
/*示例：示例 1：输入：tokens = ["2","1","+","3","*"] 输出：9
解释：该算式转化为常见的中缀算术表达式为：((2 + 1) * 3) = 9 */
/*解题思路：栈*/

int BasicCalculator_isCamputeSymbol(char* symbol)
{
    if (symbol == NULL || strlen(symbol) != 1) {
        return 0;
    }
    if (strncmp(symbol,"+", 1) == 0 || strncmp(symbol,"-", 1) == 0 || strncmp(symbol,"*", 1) == 0 || strncmp(symbol,"/", 1) == 0) {
        return 1;
    }
    return 0;
}

int BasicCalculator_campute(int leftValue, int rightValue, char* symbol) {
    if (strncmp(symbol,"+", 1) == 0) {
        return leftValue + rightValue;
    }
    if (strncmp(symbol,"-", 1) == 0) {
        return leftValue - rightValue;
    }
    if (strncmp(symbol,"*", 1) == 0) {
        return leftValue * rightValue;
    }
    if (strncmp(symbol,"/", 1) == 0) {
        return leftValue / rightValue;
    }
    ALGORITHM_INFO_LOG("[BasicCalculatorStack]something is wrong.\n");
    return 0;
}

int evalRPN(char ** tokens, int tokensSize){
    BasicCalculatorStack stack;
    stack.top = -1;
    int leftValue;
    int rightValue;
    int temp;
    int ret = 0;
    for (int i = 0; i < tokensSize; i++) {
        if (BasicCalculator_isCamputeSymbol(tokens[i])) {
            ret |= BasicCalculator_StackPOP(&stack, &rightValue);
            ret |= BasicCalculator_StackPOP(&stack, &leftValue);
            if (ret == -1) {
                ALGORITHM_INFO_LOG("%s BasicCalculator StackPOP is wrong.\n", __func__);
                return 0;
            }
            temp = BasicCalculator_campute(leftValue, rightValue, tokens[i]);
            BasicCalculator_StackPush(&stack, temp);
            continue;
        }
        temp = atoi(tokens[i]);
        BasicCalculator_StackPush(&stack, temp);
    }
    ret |= BasicCalculator_StackPOP(&stack, &temp);
    if (ret == -1) {
        ALGORITHM_INFO_LOG("BasicCalculatorStack get result wrong.\n");
        return 0;
    }
    return temp;
}

#endif

#if ALGORITHM_DESCRIPTION("224 基本计算器 困难")
/* 链接 https://leetcode-cn.com/problems/basic-calculator/ */
/* 题目描述：给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。*/
/*示例：输入：s = "(1+(4+5+2)-3)+(6+8)" 输出：23 */
/*解题思路：栈*/

int BasicCalculator_GetOperateData(char* s, int *index)
{
    return 0;
}

int BasicCalculator_isNeedPOPDataByCurSymbol(BasicCalculatorStack* operateSymbolStack, char symbol)
{
    int ret;
    int topSymbol;
    ret = BasicCalculator_StackTOP(operateSymbolStack, &topSymbol);
    if (ret == -1) {
        return 0;
    }
    if (symbol == '*' || symbol == '/') {
        if (topSymbol == '*' || topSymbol == '/') {
            return 1;
        }
        return 0;
    } else if (symbol == '+' || symbol == '-') {
        if (topSymbol != '(') {
            return 1;
        }
        return 0;
    }
    return 0;
}

int BasicCalculator_ComputeDataAndPush(BasicCalculatorStack* operateDataStack, BasicCalculatorStack* operateSymbolStack)
{
    int leftValue = 0;
    int rightValue = 0;
    int ch;
    char symbol[2];
    int result;
    int ret = 0;

    ret |= BasicCalculator_StackPOP(operateDataStack, &rightValue);
    ret |= BasicCalculator_StackPOP(operateDataStack, &leftValue);
    ret |= BasicCalculator_StackPOP(operateSymbolStack, &ch);
    if (ret == -1) {
        ALGORITHM_INFO_LOG("ComputeDataAndPush pop data failed.\n");
        return ret;
    }
    symbol[0] = (char)ch;

    result = BasicCalculator_campute(leftValue, rightValue, symbol);
    ret |= BasicCalculator_StackPush(operateDataStack, result);
    if (ret == -1) {
        ALGORITHM_INFO_LOG("ComputeDataAndPush push data failed.\n");
        return ret;
    }
    return 0;
}

int BasicCalculator_POPAllDataUntilLeftBrackets(BasicCalculatorStack* operateDataStack, BasicCalculatorStack* operateSymbolStack)
{
    int ch;
    int topSymbol = 0;

    BasicCalculator_StackTOP(operateSymbolStack, &topSymbol);

    while (topSymbol != '(') {
        BasicCalculator_ComputeDataAndPush(operateDataStack, operateSymbolStack);
        BasicCalculator_StackTOP(operateSymbolStack, &topSymbol);
    }
    /* POP '('*/
    BasicCalculator_StackPOP(operateSymbolStack, &ch);
    return 0;
}

int calculate(char * s)
{
    int sLen = strlen(s);
    int operateData;
    int result;
    int ch;
    /* 定义两个栈，一个操作符，一个操作数 */
    BasicCalculatorStack operateSymbolStack;
    BasicCalculatorStack operateDataStack;
    memset(&operateSymbolStack, 0, sizeof(BasicCalculatorStack));
    memset(&operateDataStack, 0, sizeof(BasicCalculatorStack));
    operateSymbolStack.top = -1;
    operateDataStack.top = -1;

    for (int i = 0; i < sLen; i++) {
        if (s[i] == '-' && (i == 0 || s[i-1] == '(')) {
            BasicCalculator_StackPush(&operateDataStack, 0);
            BasicCalculator_StackPush(&operateSymbolStack, s[i]);
            continue;
        }
        if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') {
            while(BasicCalculator_isNeedPOPDataByCurSymbol(&operateSymbolStack, s[i])) {
                BasicCalculator_ComputeDataAndPush(&operateDataStack, &operateSymbolStack);
            }
            BasicCalculator_StackPush(&operateSymbolStack, s[i]);
            continue;
        }
        
        if (s[i] == '(') {
            BasicCalculator_StackPush(&operateSymbolStack, s[i]);
            continue;
        }
        
        if (s[i] == ')') {
            BasicCalculator_POPAllDataUntilLeftBrackets(&operateDataStack, &operateSymbolStack);
            continue;
        }

        if (s[i] == ' ') {
            continue;
        }
        
        operateData = atoi(s+i);
        BasicCalculator_StackPush(&operateDataStack, operateData);
        i += Algorithm_GetNumberOfDigits(operateData) - 1;
    }
    while(BasicCalculator_StackTOP(&operateSymbolStack, &ch) != -1) {
        BasicCalculator_ComputeDataAndPush(&operateDataStack, &operateSymbolStack);
    }
    BasicCalculator_StackPOP(&operateDataStack, &result);
    

    return result;
}
/* 先写测试用例，把特殊情况理出来，会影响代码逻辑。找出关键点：比如 负号，括号，然后思考这些点有哪些情况。
然后考虑一些为0的情况，比如操作符为空，操作数只要一个或者没有的情况 */
void testCalculate()
{
    // char *s = "(1+(4+5+2)-3)+(6+8)";
    char s[] = "1-(-2)";
    int result = calculate(s);
    ALGORITHM_INFO_LOG("expression %s, result: %d.\n", s, result);

}

#endif