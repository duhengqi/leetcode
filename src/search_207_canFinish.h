#include "god.h"

/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
class Solution {
public:
    bool canFinishRecursive(int numCourses, vector<vector<int>>& prerequisites, set<int> relatedCourses, map<int,int>& courcesCanFinish){
        auto iter0 = courcesCanFinish.find(numCourses);
        if (iter0 != courcesCanFinish.end()) {
            return iter0->second;
        }
        auto iter = relatedCourses.insert(numCourses);
        if (iter.second == false) {
            courcesCanFinish[numCourses] = false;
            return false;
        }
        for (int i = 0; i < prerequisites.size();i++){
            if (prerequisites[i][0] == numCourses){
                if(canFinishRecursive(prerequisites[i][1], prerequisites, relatedCourses,courcesCanFinish) == false) {
                    return false;
                }
            }
        }
        courcesCanFinish[numCourses] = true;
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        map<int,int> courcesCanFinish;
        for(int i = 0;i<numCourses;i++) {
            set<int> relatedCourses;
            if (canFinishRecursive(i, prerequisites, relatedCourses,courcesCanFinish) == false) {
                return false;
            }
        }
        return true;
    }
};

// @lc code=end
TEST(test_problem_207, testcase2)
{
    Solution so;
    vector<vector<int>> prerequisites = {
        {2,0},{1,0},{3,1},{3,2},{1,3}
    };

    EXPECT_EQ(so.canFinish(4, prerequisites), false);
}

TEST(test_problem_207, testcase0)
{
    Solution so;
    vector<vector<int>> prerequisites = {
        {1, 0},
        {0, 1}
    };

    EXPECT_EQ(so.canFinish(2, prerequisites), false);
}

TEST(test_problem_207, testcase1)
{
    Solution so;
    vector<vector<int>> prerequisites = {
        {1, 0}
    };

    EXPECT_EQ(so.canFinish(2, prerequisites), true);
}
