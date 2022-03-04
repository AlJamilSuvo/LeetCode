#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        int n = grid.size();

        if (n == 1)
        {
            if (grid[0][0] == 0)
                return 1;
            else
                return -1;
        }

        vector<vector<int>> distance(n, vector(n, INT_MAX));
        queue<pii> bfsQ;
        if (grid[0][0] == 0)
        {
            distance[0][0] = 1;
            bfsQ.push({0, 0});
        }
        while (!bfsQ.empty())
        {
            pii pnt = bfsQ.front();
            bfsQ.pop();
            int x = pnt.first;
            int y = pnt.second;
            int d = distance[x][y];
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    if (i == 0 && j == 0)
                        continue;
                    if (i + x < 0 || i + x >= n || j + y < 0 || j + y >= n)
                        continue;

                    if (grid[i + x][j + y] == 0 && distance[i + x][j + y] > d + 1)
                    {
                        if (i + x == n - 1 && j + y == n - 1)
                            return d + 1;
                        distance[i + x][j + y] = d + 1;
                        bfsQ.push({i + x, j + y});
                    }
                }
            }
        }
        return -1;
    }
};