#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<pair<int, int>>> root(m, vector<pair<int, int>>(n, {0, 0}));
        vector<vector<int>> rank(m, vector(n, 0));
        int rootCnt = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    root[i][j] = {i, j};
                    rootCnt += 1;
                }
            }
        }

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == '1')
                {
                    // if (i > 0 && grid[i - 1][j] == '1')
                    //     makeUnion(root, rank, rootCnt, {i, j}, {i - 1, j});

                    if (i < m - 1 && grid[i + 1][j] == '1')
                        makeUnion(root, rank, rootCnt, {i, j}, {i + 1, j});

                    // if (j > 0 && grid[i][j - 1] == '1')
                    //     makeUnion(root, rank, rootCnt, {i, j}, {i, j - 1});

                    if (j < n - 1 && grid[i][j + 1] == '1')
                        makeUnion(root, rank, rootCnt, {i, j}, {i, j + 1});
                }
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << "(" << root[i][j].first << "," << root[i][j].second << ")\t";
            }
            cout << endl;
        }

        return rootCnt;
    }

    pair<int, int> find(vector<vector<pair<int, int>>> &root, int x, int y)
    {
        if (root[x][y].first != x || root[x][y].second != y)
        {
            root[x][y] = find(root, root[x][y].first, root[x][y].second);
        }
        return root[x][y];
    }

    void makeUnion(vector<vector<pair<int, int>>> &root, vector<vector<int>> &rank, int &rootCnt, pair<int, int> x, pair<int, int> y)
    {
        auto rootX = find(root, x.first, x.second);
        auto rootY = find(root, y.first, y.second);

        if (rootX == rootY)
            return;
        else
        {
            rootCnt--;
            if (rank[rootX.first][rootX.second] > rank[rootY.first][rootY.second])
            {
                root[rootY.first][rootY.second] = rootX;
            }

            else if (rank[rootY.first][rootY.second] > rank[rootX.first][rootX.second])
            {
                root[rootX.first][rootX.second] = rootY;
            }
            else
            {
                root[rootY.first][rootY.second] = rootX;
                rank[rootX.first][rootX.second] += 1;
            }
        }
    }
};