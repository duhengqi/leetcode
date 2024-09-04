#ifndef _LUOGU_P1551_H
#define _LUOGU_P1551_H

#include "god.h"

#include <iostream>
using namespace std;
/**
 * https://www.luogu.com.cn/problem/P1551
 */
class P1551 {
public:
    void init(int n)
    {
        for (int i = 1; i <= n; i++) {
            father[i] = i;
            rank[i] = 1;
        }
    }

    int find(int x)
    {
        if (x == father[x]) {
            return x;
        } else {
            father[x] = find(father[x]);
        }
        return father[x];
    }

    void merge(int i, int j)
    {
        int x = find(i);
        int y = find(j);
        if (rank[x] <= rank[y]) {
            father[x] = y;
        } else {
            father[y] = x;
        }
        if (rank[x] == rank[y] && x != y) {
            rank[y]++;
        }
    }
    private:
    #define MAXN 5000
    int father[MAXN];
    int rank[MAXN];
};

int P1551_main()
{
    int n, m, p;
    int dataX, dataY;
    int testDataX, testDataY;

    cin >> n >> m >> p;

    P1551 so;
    so.init(n);
    for (int i = 1; i <= m; i++) {
        cin >> dataX >> dataY;
        so.merge(dataX,dataY);
    }

    for (int i = 1; i <= p; i++) {
        cin >> testDataX >> testDataY;
        if (so.find(testDataX) == so.find(testDataY)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    }
    return 0;
}

TEST(test_luogu_P1551, testcase0)
{
    P1551 so;
    so.init(6);

    vector<vector<int>> data = {{1,2},{1,5},{3,4},{5,2},{1,3}};
    vector<vector<int>> testData = {{1,4},{2,3},{5,6}};

    for (int i = 0; i < data.size();i++) {
        so.merge(data[i][0], data[i][1]);
    }
    for (int i = 0; i < testData.size();i++) {
        int x = so.find(testData[i][0]);
        int y = so.find(testData[i][1]);
        if (x == y) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    
}

#endif /*_LUOGU_P1551_H*/
