#ifndef _TEST_MERGE_SORT_H_
#define _TEST_MERGE_SORT_H_

#include <iostream>
#include <vector>
#include "gtest.h"
#include <algorithm>
using namespace std;

/**
 * https://www.geeksforgeeks.org/merge-sort/
 */

/**
 * 合并排序，从小到大
 * 合并排序的复杂性分析：
 * 时间复杂度：
 * 
 * 最佳情况： O（n log n），当数组已经排序或即将排序时。
 * 平均情况： O（n log n），当数组随机排序时。
 * 最坏情况： O（n log n），当数组以相反的顺序排序时。
 * 空间复杂度： O（n），合并期间使用的临时数组需要额外的空间。
 * 
 * Merge Sort的应用：
 * 对大型数据集进行排序
 * 外部排序（当数据集太大而无法放入内存时）
 * 反转计数（计算数组中的反转次数）
 * 求数组的中位数
 * 合并排序的优点：
 * 稳定性 ：合并排序是一种稳定的排序算法，这意味着它保持输入数组中相等元素的相对顺序。
 * 保证最坏情况的性能： 合并排序的最坏情况时间复杂度为 O（N logN） ，这意味着即使在大型数据集上也能很好地执行。
 * 易于实施： 分而治之的方法很简单。
 * 合并排序的缺点：
 * 空间复杂性： 在排序过程中，合并排序需要额外的内存来存储合并的子数组。
 * 非就地： 合并排序不是就地排序算法，这意味着它需要额外的内存来存储排序的数据。在关注内存使用率的应用程序中，这可能是一个缺点。
*/
// code=start
class test_merge_sort {
public:
    void merge_sort_iterative(vector<int>& nums, int begin, int end)
    {
        int step = 1;
        while(step <= (end - begin)) {
            for (int i = 0; i < nums.size(); i+=2*step) {
                if(i+step > nums.size() - 1){
                    continue;
                } else if(i+step <= nums.size() - 1 && i+2*step > nums.size() - 1 ){
                    inplace_merge(nums.begin()+i, nums.begin()+i + step,nums.end());
                } else {
                    inplace_merge(nums.begin()+i, nums.begin()+i + step,nums.begin()+i+2*step);
                }
            }
            step *= 2;
        }
    }
    void merge_sort_recursive(vector<int>& nums, int begin, int end)
    {
        if (begin >= end) {
            return; 
        }

        merge_sort_recursive(nums, begin, begin+(end-begin)/2);
        merge_sort_recursive(nums, begin+(end-begin)/2+1, end);
        vector<int> tmpVct(nums.begin() + begin, nums.begin() + end);
        int startIndexLeft = 0;
        int endIndexLeft = (end-begin)/2;
        int startIndexRight = (end-begin)/2+1;
        int endIndexRight = end-begin;
        int index = 0;
        while (startIndexLeft <= endIndexLeft 
        && startIndexRight<=endIndexRight) {
            if (tmpVct[startIndexLeft] <= tmpVct[startIndexRight]) {
                nums[begin + index] = tmpVct[startIndexLeft];
                index++;
                startIndexLeft++;
                continue;
            } else {
                nums[begin + index] = tmpVct[startIndexRight];
                index++;
                startIndexRight++;
                continue;
            }
        }
        while(startIndexLeft <= endIndexLeft) {
            nums[begin + index] = tmpVct[startIndexLeft];
            index++;
            startIndexLeft++;
        }
        while(startIndexRight <= endIndexRight) {
            nums[begin + index] = tmpVct[startIndexRight];
            index++;
            startIndexRight++;
        }
    }

    /* 不适用额外空间 */
    void merge_sort_recursive_no_extra_space(vector<int>& nums, int begin, int end)
    {
        if (begin >= end) {
            return; 
        }

        merge_sort_recursive(nums, begin, begin+(end-begin)/2);
        merge_sort_recursive(nums, begin+(end-begin)/2+1, end);

        int startIndexLeft = begin;
        int endIndexLeft = begin+(end-begin)/2;
        int startIndexRight = begin+(end-begin)/2+1;
        int endIndexRight = end;

        while (startIndexLeft <= endIndexLeft 
        && startIndexRight<=endIndexRight) {
            if (nums[startIndexLeft] <= nums[startIndexRight]) {
                startIndexLeft++;
                continue;
            }
            int tmp = nums[startIndexRight];
            for (int i = endIndexLeft; i >= startIndexLeft; i--) {
                swap(nums[i],nums[i+1]);
            }
            nums[startIndexLeft] = tmp;
            startIndexLeft++;
            endIndexLeft++;
            startIndexRight++;
        }
    }

};

// code=end

// testcase=start

TEST(test_sort_merge_sort, testcase0)
{
    // {1,2,3,4,5,6,7,9,10};
    vector<int> nums = {7,6,9,3,1,5,2,4,10};
    test_merge_sort so;
    so.merge_sort_iterative(nums, 0, nums.size()-1);

    EXPECT_EQ(is_sorted(nums.begin(),nums.end()),true);
}

TEST(test_sort_merge_sort, testcase1)
{
    vector<int> nums = {1,2,3,4,5,6,7,9,10};
    test_merge_sort so;
    so.merge_sort_iterative(nums, 0, nums.size()-1);
    EXPECT_EQ(is_sorted(nums.begin(),nums.end()),true);
}


TEST(test_sort_merge_sort, testcase2)
{
    vector<int> nums = {1};
    test_merge_sort so;
    so.merge_sort_iterative(nums, 0, nums.size()-1);
    EXPECT_EQ(is_sorted(nums.begin(),nums.end()),true);
}

TEST(test_sort_merge_sort, testcase3)
{
    vector<int> nums = {2,1};
    test_merge_sort so;
    so.merge_sort_iterative(nums, 0, nums.size()-1);

    EXPECT_EQ(is_sorted(nums.begin(),nums.end()),true);
}

TEST(test_sort_merge_sort, testcase4)
{
    vector<int> nums = {5,4,3,2,1,1,2,3,4,5};
    test_merge_sort so;
    so.merge_sort_iterative(nums, 0, nums.size()-1);
    EXPECT_EQ(is_sorted(nums.begin(),nums.end()),true);
}

// testcase=end
#endif /* _TEST_MERGE_SORT_H_ */
