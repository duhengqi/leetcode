#include "god.h"
/*
 * @lc app=leetcode.cn id=278 lang=cpp
 *
 * [278] 第一个错误的版本
 */

// @lc code=start
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
extern bool isBadVersion(int version);
class Solution_278 {
public:
    int firstBadVersion(int n) {
        int left = 1;
        int right = n-1;
        if (n == 1 || isBadVersion(1)) {
            return 1;
        }

        while (left <= right) {
            int mid = (left + right) / 2;
            if (isBadVersion(mid)) {
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }

        return left;        
    }
};
// @lc code=end
