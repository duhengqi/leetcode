#ifndef _LUOGU_P1028_CALCULATION_OF_THE_NUMBER_H
#define _LUOGU_P1028_CALCULATION_OF_THE_NUMBER_H

#include "god.h"
/**
 * https://www.luogu.com.cn/problem/P1028
*/
class P1028_CalculationNumber {
public:
    int calculateNumber(int n)
    {
        vector<int> dp = {0, 1, 2};
        vector<int> sum = {0, 1, 3};
        for (int i = 3; i <= n; i++) {
            dp.push_back(1 + sum[i / 2]);
            sum.push_back(sum[i - 1] + dp[i]);
        }
        return dp[n];
    }
};

TEST(test_luogu_P1028, testcase0)
{
    P1028_CalculationNumber so;

    EXPECT_EQ(so.calculateNumber(6), 6);
}

#endif /*_LUOGU_P1028_CALCULATION_OF_THE_NUMBER_H*/
