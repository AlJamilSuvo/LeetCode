#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    int size = 0;
    vector<int> root;
    vector<int> rank;

public:
    UnionFind(int sz) : size(sz), root(sz), rank(sz)
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

    void make_union(int x, int y)
    {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY)
        {
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

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        UnionFind uf(isConnected.size());
        for (int i = 0; i < isConnected.size(); i++)
        {
            for (int j = 0; j < isConnected.size(); j++)
            {
                if(isConnected[i][j]==1)uf.make_union(i, j);
            }
        }
        set<int> root_set;
        for (int i = 0; i < isConnected.size(); i++)
        {
            root_set.insert(uf.find(i));
        }
        return root_set.size();
    }
};