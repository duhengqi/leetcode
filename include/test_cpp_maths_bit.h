/******************************************************************
 * File name: test_cpp_maths_bit.h
 * Description: 记录 数学 - 位运算 中的常见用法和代码
 * Others: 
******************************************************************/

#ifndef _TEST_CPP_MATHS_BIT_H_
#define _TEST_CPP_MATHS_BIT_H_

#include <iostream>
#include <vector>
#include <string>
#include "gtest.h"

using namespace std;

class TestCPPMathsBit {
public:
    /**
     * 计算 二进制数n 中 1 的个数
    */
    void BitCount(int n){
        unsigned int c =0 ; // 计数器
        while (n >0)
        {
            if((n &1) ==1) // 当前位是1
                ++c ; // 计数器加1
            n >>=1 ; // 移位
        }
    }
    /**
     * 整数转换成二进制保存到buf中
    */
    void PrintBit()
    {
        int num = 3;
        char buf[256] = {0};
        cout << _itoa(num, buf, 2) << endl;
    }
};


TEST(TestSuit_MathsBit, PrintBit)
{
    TestCPPMathsBit so;
    cout << "TestSuit_MathsBit : PrintBit start" << endl;
    so.PrintBit();
    cout << "TestSuit_MathsBit : PrintBit end" << endl;
}


#endif /*_TEST_CPP_MATHS_BIT_H_*/
