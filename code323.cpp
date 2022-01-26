#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> root;
    vector<int> rank;

public:
    int connected_compunent_cnt = 0;
    DisjointSet(int sz) : root(sz), rank(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
            rank[i] = i;
        }
        connected_compunent_cnt = sz;
    }

    int find(int x)
    {
        if (root[x] != x)
        {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    void make_union(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
            connected_compunent_cnt--;
            if (rank[rootX] > rank[rootY])
            {
                root[rootY] = rootX;
            }
            else if (rank[rootY] > rank[rootX])
            {
                root[rootX] = rootY;
            }
            else
            {
                root[rootY] = rootX;
                rank[rootX] += 1;
            }
        }
    }
};

class Solution
{
public:
    int countComponents(int n, vector<vector<int>> &edges)
    {
        DisjointSet ds(n);
        for (int i = 0; i < edges.size(); i++)
        {
            ds.make_union(edges[i][0], edges[i][1]);
        }
        return ds.connected_compunent_cnt;
    }
};