#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<vector<int>> rank;
    vector<vector<pair<int, int>>> root;

public:
    int cnt=0;
    DisjointSet(int m, int n, vector<vector<int>> &grid, vector<vector<bool>> &isPartOfCloseIceLand)
        : rank(m, vector<int>(n, 0)), root(m, vector<pair<int, int>>(n, {0, 0}))
    {
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 0 && isPartOfCloseIceLand[i][j])
                {
                    rank[i][j] = 0;
                    root[i][j] = {i, j};
                    cnt++;
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
            cnt--;
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
    int closedIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> isPartOfCloseIceLand(m, vector<bool>(n, true));
        queue<pair<int, int>> bfsQ;
        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 0)
            {
                isPartOfCloseIceLand[0][i] = false;
                bfsQ.push({0, i});
            }
            if (grid[m - 1][i] == 0)
            {
                isPartOfCloseIceLand[m - 1][i] = false;
                bfsQ.push({m - 1, i});
            }
        }
       

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 0)
            {
                isPartOfCloseIceLand[i][0] = false;
                bfsQ.push({i, 0});
            }
            if (grid[i][n - 1] == 0)
            {
                isPartOfCloseIceLand[i][n - 1] = false;
                bfsQ.push({i, n - 1});
            }
        }
        
        while (!bfsQ.empty())
        {
            int x = bfsQ.front().first;
            int y = bfsQ.front().second;
            bfsQ.pop();

            if (x > 0 && grid[x - 1][y] == 0 && isPartOfCloseIceLand[x - 1][y])
            {
                isPartOfCloseIceLand[x - 1][y] = false;
                bfsQ.push({x - 1, y});
            }

            if (y > 0 && grid[x][y - 1] == 0 && isPartOfCloseIceLand[x][y - 1])
            {
                isPartOfCloseIceLand[x][y - 1] = false;
                bfsQ.push({x, y - 1});
            }

            if (x + 1 < m && grid[x + 1][y] == 0 && isPartOfCloseIceLand[x + 1][y])
            {
                isPartOfCloseIceLand[x + 1][y] = false;
                bfsQ.push({x + 1, y});
            }

            if (y + 1 < n && grid[x][y + 1] == 0 && isPartOfCloseIceLand[x][y + 1])
            {
                isPartOfCloseIceLand[x][y + 1] = false;
                bfsQ.push({x, y + 1});
            }
        }
        DisjointSet ds(m, n, grid, isPartOfCloseIceLand);
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (grid[i][j] == 0 && isPartOfCloseIceLand[i][j])
                {
                    if (grid[i + 1][j] == 0 && isPartOfCloseIceLand[i + 1][j])
                    {
                        ds.make_union({i, j}, {i + 1, j});
                    }
                    if (grid[i][j + 1] == 0 && isPartOfCloseIceLand[i][j + 1])
                    {
                        ds.make_union({i, j}, {i, j + 1});
                    }
                }
            }
        }

        return ds.cnt;
    }
};

int main()
{
    vector<vector<int>> grid = {{1, 1, 1, 1, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 1, 0}, {1, 0, 1, 0, 1, 1, 1, 0}, {1, 0, 0, 0, 0, 1, 0, 1}, {1, 1, 1, 1, 1, 1, 1, 0}};
    Solution s;
    s.closedIsland(grid);
}