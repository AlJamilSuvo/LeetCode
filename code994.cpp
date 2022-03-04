#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> bfsQ;
        vector<vector<int>> rottenTime(m, vector(n, INT_MAX));
        int maxTime = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 2)
                {
                    rottenTime[i][j] = 0;
                    bfsQ.push({i, j});
                }
            }
        }
        while (!bfsQ.empty())
        {
            auto pos = bfsQ.front();
            bfsQ.pop();
            int x = pos.first;
            int y = pos.second;
            int t = rottenTime[x][y];
            if (x - 1 >= 0 && grid[x - 1][y] == 1)
            {
                rottenTime[x - 1][y] = t + 1;
                grid[x - 1][y] = 2;
                maxTime = max(t + 1, maxTime);
                bfsQ.push({x - 1, y});
            }

            if (y - 1 >= 0 && grid[x][y - 1] == 1)
            {
                rottenTime[x][y - 1] = t + 1;
                grid[x][y - 1] = 2;
                maxTime = max(t + 1, maxTime);
                bfsQ.push({x, y - 1});
            }

            if (x + 1 < m && grid[x + 1][y] == 1)
            {
                rottenTime[x + 1][y] = t + 1;
                grid[x + 1][y] = 2;
                maxTime = max(t + 1, maxTime);
                bfsQ.push({x + 1, y});
            }

            if (y + 1 < n && grid[x][y + 1] == 1)
            {
                rottenTime[x][y + 1] = t + 1;
                grid[x][y + 1] = 2;
                maxTime = max(t + 1, maxTime);
                bfsQ.push({x, y + 1});
            }
        }

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return maxTime;
    }
};