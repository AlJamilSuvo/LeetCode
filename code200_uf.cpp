#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<vector<pair<int, int>>> root;
    vector<vector<int>> rank;

public:
    int setCnt = 0;

    DisjointSet(int m, int n, vector<vector<char>> &grid) : root(m, vector<pair<int, int>>(n)), rank(m, vector<int>(n))
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '1')
                {
                    root[i][j] = {i, j};
                    rank[i][j] = 0;
                    setCnt++;
                }
            }
        }
    }

    pair<int, int> find(pair<int, int> x)
    {
        if (root[x.first][x.second] == x)
            return x;
        root[x.first][x.second] = find(root[x.first][x.second]);
        return root[x.first][x.second];
    }

    void make_union(pair<int, int> x, pair<int, int> y)
    {
        auto rootX = find(x);
        auto rootY = find(y);
        if (rootX != rootY)
        {
            setCnt--;
            if (rank[rootX.first][rootX.second] > rank[rootY.first][rootY.second])
            {
                root[rootY.first][rootY.second] = rootX;
            }
            else if (rank[rootX.first][rootX.second] < rank[rootY.first][rootY.second])
            {
                root[rootX.first][rootX.second] = rootY;
            }
            else
            {
                root[rootY.first][rootY.second] = rootX;
                rank[rootX.first][rootX.second]++;
            }
        }
    }
};

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        DisjointSet ds(m, n, grid);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == '0')
                    continue;
                if (i < m - 1 && grid[i + 1][j] == '1')
                {
                    ds.make_union({i, j}, {i + 1, j});
                }

                if (j < n - 1 && grid[i][j + 1] == '1')
                {
                    ds.make_union({i, j}, {i, j + 1});
                }
            }
        }
        return ds.setCnt;
    }
};