#ifndef _LEETCODE_NUMS_1971_VALID_PATH_H_
#define _LEETCODE_NUMS_1971_VALID_PATH_H_

#include "god.h"

/*
 * @lc app=leetcode.cn id=1971 lang=cpp
 *
 * [1971] 寻找图中是否存在路径
 * 有一个具有 n 个顶点的 双向 图，其中每个顶点标记从 0 到 n - 1（包含 0 和 n - 1）。
 * 图中的边用一个二维整数数组 edges 表示，其中 edges[i] = [ui, vi] 表示顶点 ui 和顶点 vi 之间的双向边。 
 * 每个顶点对由 最多一条 边连接，并且没有顶点存在与自身相连的边。
 * 请你确定是否存在从顶点 source 开始，到顶点 destination 结束的 有效路径 。
 * 给你数组 edges 和整数 n、source 和 destination，如果从 source 到 destination 存在 有效路径 ，则返回 true，否则返回 false 。
 * 
 * 示例 1：
 * 输入：n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
 * 输出：true
 * 解释：存在由顶点 0 到顶点 2 的路径:
 * - 0 → 1 → 2 
 * - 0 → 2
 * 
 * 示例 2：
 * 输入：n = 6, edges = [[0,1],[0,2],[3,5],[5,4],[4,3]], source = 0, destination = 5
 * 输出：false
 * 解释：不存在由顶点 0 到顶点 5 的路径.
 * 
 * 提示：
 * 1 <= n <= 2 * 10^5
 * 0 <= edges.length <= 2 * 10^5
 * edges[i].length == 2
 * 0 <= ui, vi <= n - 1
 * ui != vi
 * 0 <= source, destination <= n - 1
 * 不存在重复边
 * 不存在指向顶点自身的边
 */

// @lc code=start
class Solution_1971 {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (n == 1) {
            return true;
        } else if (edges.size() == 0) {
            return false;
        }
        vector<int> table(n,-1);
        vector<vector<int>> unionFind;
        int setNum = 0;
        for (int i = 0; i < edges.size();i++) {
            if (table[edges[i][0]] == -1 && table[edges[i][1]] == -1) {
                table[edges[i][0]] = setNum;
                table[edges[i][1]] = setNum;
                unionFind.push_back({edges[i][0], edges[i][1]});
                setNum++;
            } else if (table[edges[i][0]] != -1 && table[edges[i][1]] != -1) {
                int set0 = table[edges[i][0]];
                int set1 = table[edges[i][1]];
                if (set0 != set1) {
                    if (set0 < set1) {
                        for (int j = 0; j < unionFind[set1].size();j++) {
                            table[unionFind[set1][j]] = set0;
                            unionFind[set0].push_back(unionFind[set1][j]);
                            unionFind[set1][j] = -1;
                        }
                    } else {
                        for (int j = 0; j < unionFind[set0].size();j++) {
                            table[unionFind[set0][j]] = set1;
                            unionFind[set1].push_back(unionFind[set0][j]);
                            unionFind[set0][j] = -1;
                        }
                    }
                }
            } else if (table[edges[i][0]] != -1) {
                table[edges[i][1]] = table[edges[i][0]];
                unionFind[table[edges[i][0]]].push_back(edges[i][1]);
            } else {
                table[edges[i][0]] = table[edges[i][1]];
                unionFind[table[edges[i][1]]].push_back(edges[i][0]);
            }
        }
        if (table[source] != -1 && table[source] == table[destination]) {
            return true;
        }
        return false;
    }
};
// @lc code=end

TEST(test_problem_1971, testcase2)
{
    Solution_1971 so;
    vector<vector<int>> edges = {{31,5},{10,46},{19,31},{5,1},{31,28},{28,29},{8,26},{13,23},{16,34},{30,1},
    {16,18},{33,46},{27,35},{2,25},{49,33},{44,19},{22,26},{30,13},{27,12},{8,16},{42,13},{18,3},{21,20},{2,17},
    {5,48},{41,37},{39,37},{2,11},{20,26},{19,43},{45,7},{0,21},{44,23},{2,39},{27,36},{41,48},{17,42},{40,32},
    {2,28},{35,38},{3,9},{41,30},{5,11},{24,22},{39,5},{40,31},{18,35},{23,39},{20,24},{45,12}};
    bool result = so.validPath(50, edges,29,46);
    EXPECT_EQ(result, false);;
}

TEST(test_problem_1971, testcase0)
{
    Solution_1971 so;
    vector<vector<int>> edges = {{0,1},{1,2},{2,0}};
    bool result = so.validPath(3, edges,0,2);
    EXPECT_EQ(result, true);;
}

TEST(test_problem_1971, testcase1)
{
    Solution_1971 so;
    vector<vector<int>> edges = {{0,1},{0,2},{3,5},{5,4},{4,3}};
    bool result = so.validPath(6, edges,0,5);
    EXPECT_EQ(result, false);;
}


#endif /*_LEETCODE_NUMS_1971_VALID_PATH_H_*/
