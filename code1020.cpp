#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>
class Solution
{
public:
    int numEnclaves(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> isEdge(m, vector<bool>(n, false));

        queue<pii> bfsQ;

        for (int i = 0; i < m; i++)
        {
            if (grid[i][0] == 1)
            {
                isEdge[i][0] = true;
                bfsQ.push({i, 0});
            }

            if (grid[i][n - 1] == 1)
            {
                isEdge[i][n - 1] = true;
                bfsQ.push({i, n - 1});
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (grid[0][i] == 1)
            {
                isEdge[0][i] = true;
                bfsQ.push({0, i});
            }

            if (grid[m - 1][i] == 1)
            {
                isEdge[m - 1][i] = true;
                bfsQ.push({m - 1, i});
            }
        }

        while (!bfsQ.empty())
        {
            int x = bfsQ.front().first;
            int y = bfsQ.front().second;
            bfsQ.pop();

            if (x > 0 && grid[x - 1][y] == 1 && !isEdge[x - 1][y])
            {
                isEdge[x - 1][y]=true;
                bfsQ.push({x - 1, y});
            }
            if (y > 0 && grid[x][y - 1] == 1 && !isEdge[x][y - 1])
            {
                isEdge[x][y - 1]=true;
                bfsQ.push({x, y - 1});
            }

            if (x < m - 1 && grid[x + 1][y] == 1 && !isEdge[x + 1][y])
            {
                isEdge[x + 1][y]=true;
                bfsQ.push({x + 1, y});
            }
            if (y < n - 1 && grid[x][y + 1] == 1 && !isEdge[x][y + 1])
            {
                isEdge[x][y + 1]=true;
                bfsQ.push({x, y + 1});
            }
        }
        int cnt = 0;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if(grid[i][j]==1 && !isEdge[i][j]) cnt++;
            }
        }
        return cnt;
    }
};