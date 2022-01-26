#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> root;
    vector<int> rank;

public:
    DisjointSet(int sz) : root(sz), rank(sz)
    {
        for (int i = 0; i < sz; i++)
        {
            root[i] = i;
            rank[i] = 0;
        }
    }

    int find(int x)
    {
        if (root[x] != x)
        {
            root[x] = find(root[x]);
        }
        return root[x];
    }

    bool make_union(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return false;
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
        return true;
    }
};

class Solution
{
public:
    bool validTree(int n, vector<vector<int>> &edges)
    {
        DisjointSet ds(n);
        for (auto edge : edges)
        {
            if (!ds.make_union(edge[0], edge[1]))
                return false;
        }
        int root = ds.find(0);
        for (int i = 1; i < n; i++)
        {
            if (ds.find(i) != root)
                return false;
        }

        return true;
    }
};