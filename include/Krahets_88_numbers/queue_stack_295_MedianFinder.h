#ifndef _LEETCODE_NUMS_295_MEDIANFINDER_H
#define _LEETCODE_NUMS_295_MEDIANFINDER_H

#include "god.h"

/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 * https://leetcode.cn/problems/find-median-from-data-stream
 * 
 * 中位数是有序整数列表中的中间值。如果列表的大小是偶数，则没有中间值，中位数是两个中间值的平均值。
 * 例如 arr = [2,3,4] 的中位数是 3 。
 * 例如 arr = [2,3] 的中位数是 (2 + 3) / 2 = 2.5 。
 * 实现 MedianFinder 类:
 * MedianFinder() 初始化 MedianFinder 对象。
 * void addNum(int num) 将数据流中的整数 num 添加到数据结构中。
 * double findMedian() 返回到目前为止所有元素的中位数。与实际答案相差 10-5 以内的答案将被接受。
 * 
 * 示例 1：
 * 输入
 * ["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
 * [[], [1], [2], [], [3], []]
 * 输出
 * [null, null, null, 1.5, null, 2.0]
 * 
 * 解释
 * MedianFinder medianFinder = new MedianFinder();
 * medianFinder.addNum(1);    // arr = [1]
 * medianFinder.addNum(2);    // arr = [1, 2]
 * medianFinder.findMedian(); // 返回 1.5 ((1 + 2) / 2)
 * medianFinder.addNum(3);    // arr[1, 2, 3]
 * medianFinder.findMedian(); // return 2.0
 * 提示:
 * -10^5 <= num <= 10^5
 * 在调用 findMedian 之前，数据结构中至少有一个元素
 * 最多 5 * 10^4 次调用 addNum 和 findMedian
 */

// @lc code=start

class MedianFinder {
public:
    MedianFinder() {}

    void addNum(int num) {
        nums.push_back(num);
        if(nums.size() == 1) {
            return;
        }
        for (int j = nums.size()-1; j > 0; j--) {
            if (nums[j] < nums[j - 1]) {
                swap(nums[j], nums[j - 1]);
            } else {
                break;
            }
        }
    }
    
    double findMedian() {
        if(nums.size() %2 == 0) {
            return (double(nums[nums.size() / 2 - 1]) + double(nums[nums.size() / 2]))/2;
        } else {
            return (double)nums[nums.size() / 2];
        }
    }
private:
    vector<int>nums;
};


class MedianFinder_multiset {
public:
    MedianFinder_multiset() {}

    void addNum(int num) {
        int setSize = medianSet.size();
        medianSet.insert(num);
        // cout << setSize << endl;
        if (setSize == 0) {
            left = medianSet.begin();
            right = medianSet.begin();
        } else if (setSize%2 != 0) {
            if (num >= *right) {
                right++;
            } else {
                left--;
            }
        } else {
            if (num >= *right) {
                left = right;
            } else if (num < *left) {
                right = left;
            } else {
                left++;
                right = left;
            }
        }
        // cout << "left: "<< *left  << " right " << *right << endl;
        setSize++;
    }

    double findMedian() {
            return ((*left) + (*right))/2.0;
            // return (double((*left)) + double((*right)))/2;
    }

private:
    multiset<int> medianSet;
    // int setSize = 0;
    multiset<int>::iterator left;
    multiset<int>::iterator right;
};

/* 转换成求 K大或者K小 */
class MedianFinder_priority_queue {
public:
    MedianFinder_priority_queue() {}

    void addNum(int num) {
        if (bigQ.empty()) {
            bigQ.push(num);
        } else if (num <= bigQ.top()){
            bigQ.push(num);
            if (bigQ.size() >= smallQ.size()+2) {
                smallQ.push(bigQ.top());
                bigQ.pop();
            }
        } else {
            smallQ.push(num);
            if (smallQ.size() >= bigQ.size()+2) {
                bigQ.push(smallQ.top());
                smallQ.pop();
            }
        }
    }

    double findMedian() {
        if (bigQ.size() == smallQ.size()) {
            return (smallQ.top() + bigQ.top()) / 2.0;
        } else if (bigQ.size() > smallQ.size()) {
            return (bigQ.top() + bigQ.top()) / 2.0;
        } else if (bigQ.size() < smallQ.size()) {
            return (smallQ.top() + smallQ.top()) / 2.0;
        }
        return 0;
    }

private:
    priority_queue<int> bigQ;
    priority_queue<int,vector<int>,greater<int>> smallQ;
};

TEST(test_problem_295, testcase3)
{
    MedianFinder medianfinder;

    medianfinder.addNum(10);
    EXPECT_EQ(medianfinder.findMedian(), double(10));

    medianfinder.addNum(6);
    EXPECT_EQ(medianfinder.findMedian(), double(8));

    medianfinder.addNum(14);
    EXPECT_EQ(medianfinder.findMedian(), double(10));

    // cout << result << endl;

    medianfinder.addNum(18);
    EXPECT_EQ(medianfinder.findMedian(), double(12));
    // cout << result << endl;

    medianfinder.addNum(12);
    EXPECT_EQ(medianfinder.findMedian(), double(12));
    // cout << result << endl;

    medianfinder.addNum(15);
    EXPECT_EQ(medianfinder.findMedian(), double(13));

    medianfinder.addNum(3);
    EXPECT_EQ(medianfinder.findMedian(), double(12));
    medianfinder.addNum(11);
    EXPECT_EQ(medianfinder.findMedian(), double(11.5));
    medianfinder.addNum(19);
    EXPECT_EQ(medianfinder.findMedian(), double(12));
}

TEST(test_problem_295, testcase1)
{
    MedianFinder medianfinder;

    medianfinder.addNum(1);
    medianfinder.addNum(2);
    EXPECT_EQ(medianfinder.findMedian(), double(1.5));

    medianfinder.addNum(3);
    EXPECT_EQ(medianfinder.findMedian(), double(2));

    return;
}

TEST(test_problem_295, testcase2)
{
    MedianFinder medianfinder;
    medianfinder.addNum(6);
    EXPECT_EQ(medianfinder.findMedian(), double(6));

    medianfinder.addNum(10);
    EXPECT_EQ(medianfinder.findMedian(), double(8));
    // cout << result << endl;

    medianfinder.addNum(2);
    EXPECT_EQ(medianfinder.findMedian(), double(6));
    // cout << result << endl;

    medianfinder.addNum(6);
    EXPECT_EQ(medianfinder.findMedian(), double(6));
    // cout << result << endl;

    medianfinder.addNum(5);
    EXPECT_EQ(medianfinder.findMedian(), double(6));
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

#endif /*_LEETCODE_NUMS_295_MEDIANFINDER_H*/
