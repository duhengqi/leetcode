#ifndef _LUOGU_P1036_CHOOSE_PRIME_H
#define _LUOGU_P1036_CHOOSE_PRIME_H

#include "god.h"

class P1036_ChoosePrime {
public:
    int choosePrime(vector<int> &nums, int k)
    {
        return 0;
    }
};

TEST(test_luogu_P1036, testcase0)
{
    P1036_ChoosePrime so;
    vector<int> nums = {3, 7, 12, 19};
    EXPECT_EQ(so.choosePrime(nums,3), 1);
}

#endif /*_LUOGU_P1036_CHOOSE_PRIME_H*/
