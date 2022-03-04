#include <bits/stdc++.h>
using namespace std;

class Edge
{
public:
    int p1;
    int p2;
    int d;
};

class EdgeComprare
{
public:
    bool operator()(const Edge &e1, const Edge &e2)
    {
        return e1.d > e2.d;
    }
};

class DisjointSet
{
    vector<int> rank;
    vector<int> root;

public:
    DisjointSet(int n) : rank(n), root(n)
    {
        for (int i = 0; i < n; i++)
        {
            rank[i] = 0;
            root[i] = i;
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
        else
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
                rank[rootX]++;
            }
            return true;
        }
    }
};

class Solution
{
public:
    int minCostConnectPoints(vector<vector<int>> &points)
    {
        int n = points.size();
        DisjointSet ds(n);
        priority_queue<Edge, vector<Edge>, EdgeComprare> edges;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int d = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                Edge e;
                e.p1 = i;
                e.p2 = j;
                e.d = d;
                edges.push(e);
            }
        }
        int res = 0;
        int count = 0;
        while (!edges.empty())
        {
            Edge e = edges.top();
            edges.pop();

            if (ds.make_union(e.p1, e.p2))
            {
                res += e.d;
                count += 1;
            }
            if (count == n - 1)
                break;
        }
        return res;
    }
};