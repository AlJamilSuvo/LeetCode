#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size() - 1;
        vector<vector<int>> distance(n + 1, vector(n + 1, -1));
        queue<pair<int, int>> bfsQ;
        distance[0][0] = grid[0][0] == 0 ? 1 : -1;
        bfsQ.push({0, 0});
        while (!bfsQ.empty())
        {
            auto cur = bfsQ.front();
            bfsQ.pop();
            int x = cur.first;
            int y = cur.second;
            int d = distance[x][y];
            if (grid[x][y] == 1 || d == -1)
                continue;
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (i == 0 && j == 0)
                        continue;
                    if (x + i < 0 || x + i > n || y + j < 0 || y + j > n)
                        continue;
                    if (grid[x + i][y + j] == 1)
                        continue;
                    if (d + 1 < distance[x + i][y + j] || distance[x + i][y + j] == -1)
                    {
                        distance[x + i][y + j] = d + 1;
                        if (x + i == n && y + j == n)
                            return d + 1;
                        bfsQ.push({x + i, y + j});
                    }
                }
            }
        }
        return distance[n][n];
    }
};