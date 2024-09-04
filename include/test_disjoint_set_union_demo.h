#ifndef _TEST_DISJOINT_SET_UNION_DEMO_H_
#define _TEST_DISJOINT_SET_UNION_DEMO_H_

#include <iostream>
#include <vector>
#include <string>
#include "cmath"
#include "gtest.h"

using namespace std;

class TestDisjointSetUnionDemo {
public:
    void init(int n){
        for (int i = 0; i < n; i++) {
            father[i] = i;
            rank[i] = 1;
        }
    }
    int find(int x){
        if (x = father[x]) {
            return x;
        } else {
            father[x] = find(father[x]);
        }
        return father[x];
    }
    void merge(int i, int j) {
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
#define MAXN 512
    int father[MAXN];
    int rank[MAXN];
};

#endif /*_TEST_DISJOINT_SET_UNION_DEMO_H_*/
