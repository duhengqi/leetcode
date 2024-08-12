#ifndef _LEETCODE_NUMS_768_MAX_CHUNKS_TO_SORTED_H_
#define _LEETCODE_NUMS_768_MAX_CHUNKS_TO_SORTED_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=768 lang=cpp
 *
 * [768] 最多能完成排序的块 II
 * 给你一个整数数组 arr 。
 * 将 arr 分割成若干 块 ，并将这些块分别进行排序。之后再连接起来，使得连接的结果和按升序排序后的原数组相同。
 * 返回能将数组分成的最多块数？
 * 
 * 示例 1：
 * 输入：arr = [5,4,3,2,1]   输出：1
 * 解释：
 * 将数组分成2块或者更多块，都无法得到所需的结果。 
 * 例如，分成 [5, 4], [3, 2, 1] 的结果是 [4, 5, 1, 2, 3]，这不是有序的数组。 
 * 
 * 示例 2：
 * 输入：arr = [2,1,3,4,4]    输出：4
 * 解释：
 * 可以把它分成两块，例如 [2, 1], [3, 4, 4]。 
 * 然而，分成 [2, 1], [3], [4], [4] 可以得到最多的块数。 
 * 
 * 提示：
 * 1 <= arr.length <= 2000
 * 0 <= arr[i] <= 10^8
 */

// @lc code=start
class Solution_768 {
public:
    int maxChunksToSorted(vector<int>& arr) {

    }
};
// @lc code=end

#endif /*_LEETCODE_NUMS_768_MAX_CHUNKS_TO_SORTED_H_*/
