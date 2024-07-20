
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wchar-subscripts"
#pragma GCC diagnostic ignored "-Wsign-compare"
#pragma GCC diagnostic ignored "-Wunused-variable"
#include <iostream>
#include <list>
#include <stack>
#include <vector>
#include <string>
#include "test_algorithm_find.h"
#include "gtest.h"
#include "god.h"
#include "test_stl_priority_queue.h"
#include "search_215_lowestCommonAncestor.h"
#include "test_stl_array.h"
#include "test_stl_deque.h"
#include "test_stl_map.h"
#include "test_stl_multimap.h"
#include "test_stl_multiset.h"
#include "test_stl_pair.h"
#include "test_stl_priority_queue.h"
#include "test_stl_queue.h"
#include "test_stl_set.h"
#include "test_stl_vector.h"
#include "test_algorithm_find.h"
#include "test_algorithm_sort.h"
#include "leetcode_list.h"
#include "leetcode_binary_tree.h"
#include "test_insertion_sort.h"
#include "test_selection_sort.h"
#include "test_bubble_sort.h"
#include "test_merge_sort.h"
#include "binary_tree_144_preorderTraversal.h"
#include "binary_tree_145_postorderTraversal.h"
#include "binary_tree_94_inorderTraversal.h"
#include "dual_pointers_142_detectCycle.h"
#include "dual_pointers_151_reverseWords.h"
#include "dual_pointers_15_threeSum.h"
#include "dual_pointers_160_getIntersectionNode.h"
#include "dual_pointers_167_twoSum.h"
#include "dual_pointers_239_maxSlidingWindow.h"
#include "dual_pointers_392_isSubsequence.h"
#include "dual_pointers_3_lengthOfLongestSubstring.h"
#include "dual_pointers_876_middleNode.h"
#include "find_153_findMin.h"
#include "find_154_findMin_II.h"
#include "find_278_firstBadVersion.h"
#include "find_287_findDuplicate.h"
#include "find_704_search.h"
#include "find_724_pivotIndex.h"
#include "hash_205_isIsomorphic.h"
#include "hash_242_isAnagram.h"
#include "hash_387_firstUniqChar.h"
#include "hash_409_longestPalindrome.h"
#include "list_206_reverseList.h"
#include "list_21_mergeTwoLists.h"
#include "list_237_deleteNode.h"
#include "list_86_partition.h"
#include "queue_stack_155_MinStack.h"
#include "queue_stack_20_isValid.h"
#include "queue_stack_232_MyQueue.h"
#include "queue_stack_295_MedianFinder.h"
#include "queue_stack_394_decodeString.h"
#include "search_102_binary_tree_levelOrder.h"
#include "search_103_binary_tree_zigzagLevelOrder.h"
#include "search_230_binary_tree_kthSmallest.h"
#include "search_235_binary_tree_lowestCommonAncestor.h"
#include "search_236_binary_tree_lowestCommonAncestor.h"
#include "simulation_415_addStrings.h"
#include "simulation_48_rotate.h"
#include "simulation_54_spiralOrder.h"
#include "simulation_59_generateMatrix.h"
#include "simulation_6_convert.h"
#include "simulation_796_rotateString.h"
#include "simulation_8_myAtoi.h"
#include "simulation_946_validateStackSequences.h"
using namespace std;

int run_all_test(int* argc, char** argv)
{
    testing::InitGoogleTest(argc,argv);
    ::testing::InitGoogleTest(argc, argv);
    /* 测试指定用例 不执行用例可以加上DISABLE_ */
    // ::testing::GTEST_FLAG(filter) = "test_problem_215.*";
    // ::testing::GTEST_FLAG(filter) = "test_stl_priority_queue1.*";
    ::testing::GTEST_FLAG(filter) = "*";
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
    // test_stl_priority_queue1();
    (void)run_all_test(&argc, argv);

    return 0;
}

#pragma GCC diagnostic pop