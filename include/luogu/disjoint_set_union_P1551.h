#ifndef _LUOGU_P1551_H
#define _LUOGU_P1551_H

#include "god.h"
/**
 * https://www.luogu.com.cn/problem/P1551
*/
class P1551 {
public:
    int UnionFind(int n)
    {
        vector<int> dp = {0, 1, 2};
        vector<int> sum = {0, 1, 3};
        for (int i = 3; i <= n; i++) {
            dp.push_back(1 + sum[i / 2]);
            sum.push_back(sum[i - 1] + dp[i]);
        }
        return dp[n];
    }
    void merge() {

    }
    bool find(int x, int y) {

    }
};

TEST(test_luogu_P1551, testcase0)
{
    P1551 so;

}

#endif /*_LUOGU_P1551_H*/
