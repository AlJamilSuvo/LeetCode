#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
private:
    vector<int> root;
    vector<int> rank;
    int connected_component_cnt;
public:
    DisjointSet(int sz) : root(sz), rank(sz)
    {
        connected_component_cnt = sz;
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
        if (rootX != rootY)
        {
            connected_component_cnt--;
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
        return connected_component_cnt == 1;
    }
};

bool compare(vector<int> &p1, vector<int> &p2)
{
    return p1[0] < p2[0];
}

class Solution
{
public:
    int earliestAcq(vector<vector<int>> &logs, int n)
    {
        sort(logs.begin(), logs.end(), compare);
        DisjointSet ds(n);
        for (int i = 0; i < logs.size(); i++)
        {
            if (ds.make_union(logs[i][1], logs[i][2]))
                return logs[i][0];
        }
        return -1;
    }
};