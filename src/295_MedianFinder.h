#include "god.h"

/*
 * @lc app=leetcode.cn id=295 lang=cpp
 *
 * [295] 数据流的中位数
 */

// @lc code=start

class MedianFinder {
public:
    MedianFinder() {

    }

    void addNum(int num) { medianSet.insert(num); }

    double findMedian() {
        int size = medianSet.size();
        // cout << "debug: size :" << size << endl;
        if (size%2 != 0) {
            // cout << "1debug: size :" << size << "size%2 "<< size%2<< endl;
            auto iter = medianSet.begin();
            advance(iter, size / 2);
            return double(*iter);
        } else {
            // cout << "0debug: size :" << size << "size%2 "<< size%2<< endl;
            auto iter1 = medianSet.begin();
            auto iter2 = medianSet.begin();
            advance(iter1, size / 2 - 1);
            advance(iter2, size / 2);
            return (double((*iter1)) + double((*iter2)))/2;
        }
    }

private:
    set<int> medianSet;
};
static void Problem_295_testcase1()
{
    /*["MedianFinder","addNum","addNum","findMedian","addNum","findMedian"] */
    double result;
    bool testResult = true;
    MedianFinder medianfinder;
    

    medianfinder.addNum(1);
    result = medianfinder.findMedian();

    medianfinder.addNum(2);
    result = medianfinder.findMedian();
    if (result != double(1.5)) {
        testResult = false;
    }
    // cout << result << endl;

    medianfinder.addNum(3);
    result = medianfinder.findMedian();
    // cout << result << endl;
    if (result != double(2)) {
        testResult = false;
    }

    if (testResult == false) {
        cout << "TEST CASE1 FAILED" << endl;
    } else {
        cout << "TEST CASE1 PASSED" << endl;
    }

    return;
}
static void Problem_295_testcase2()
{
    double result;
    bool testResult = true;
    MedianFinder medianfinder;
    medianfinder.addNum(6);
    result = medianfinder.findMedian();
    if (result != double(6)) {
        testResult = false;
        cout << __func__<<"() lines "<< __LINE__ <<" : wrong result : " << result << endl;
    }

    // cout << result << endl;

    medianfinder.addNum(10);
    result = medianfinder.findMedian();
    if (result != double(8)) {
        testResult = false;
        cout << __func__<<"() lines "<< __LINE__ <<" : wrong result : " << result << endl;
    }
    // cout << result << endl;

    medianfinder.addNum(2);
    result = medianfinder.findMedian();
    if (result != double(6)) {
        testResult = false;
        cout << __func__<<"() lines "<< __LINE__ <<" : wrong result : " << result << endl;
    }
    // cout << result << endl;

    medianfinder.addNum(6);
    result = medianfinder.findMedian();
    if (result != double(6)) {
        testResult = false;
        cout << __func__<<"() lines "<< __LINE__ <<" : wrong result : " << result << endl;
    }
    // cout << result << endl;

    medianfinder.addNum(5);
    result = medianfinder.findMedian();
    if (result != double(6)) {
        testResult = false;
        cout << __func__<<"() lines "<< __LINE__ <<" : wrong result : " << result << endl;
    }

    print_test_result(testResult, __func__);
    return;
}
static void Problem_295_test()
{
    Problem_295_testcase1();
    Problem_295_testcase2();
    return;
}
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
// @lc code=end

