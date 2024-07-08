#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <string>
#include "gtest.h"
#include "test_stl_multiset.h"
#include "test_stl_queue.h"
#include "god.h"
#include "queue_stack_295_MedianFinder.h"
#include "hash_387_firstUniqChar.h"
#include "hash_205_isIsomorphic.h"

using namespace std;

int run_all_test(int* argc, char** argv)
{
    testing::InitGoogleTest(argc,argv);
    ::testing::InitGoogleTest(argc, argv);
    /* 测试指定用例 不执行用例可以加上DISABLE_ */
    ::testing::GTEST_FLAG(filter) = "test_problem_242*";
    /* 重复执行用例，可以上面的filter参数同时使用 */
    ::testing::GTEST_FLAG(repeat) = 1;
    /* 用例失败停止 1 开启，0关闭 */
    ::testing::GTEST_FLAG(break_on_failure) = 1;
    /* 打印每个测试用例的执行时间，默认不打印 1 开启，0关闭*/
    ::testing::GTEST_FLAG(print_time) = 0;    
    return RUN_ALL_TESTS();
}

int main(int argc, char **argv)
{
    // test_stl_priority_queue();
    (void)run_all_test(&argc, argv);

    return 0;
}