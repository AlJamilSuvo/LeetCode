#include <bits/stdc++.h>
using namespace std;

class Solution
{

    int m = 0;
    int n = 0;

public:
    int minimumEffortPath(vector<vector<int>> &heights)
    {
        m = heights.size();
        n = heights[0].size();

        vector<vector<int>> effors(m, vector<int>(n, INT_MAX));
        vector<vector<bool>> isAdded(m, vector<bool>(n, false));
        queue<pair<int, int>> Q;
        Q.push({0, 0});
        effors[0][0] = 0;
        isAdded[0][0] = true;
        while (!Q.empty())
        {
            auto cur = Q.front();
            Q.pop();
            isAdded[cur.first][cur.second] = false;
            updateEfforts(cur.first, cur.second, cur.first - 1, cur.second, effors, heights, isAdded, Q);
            updateEfforts(cur.first, cur.second, cur.first, cur.second - 1, effors, heights, isAdded, Q);
            updateEfforts(cur.first, cur.second, cur.first + 1, cur.second, effors, heights, isAdded, Q);
            updateEfforts(cur.first, cur.second, cur.first, cur.second + 1, effors, heights, isAdded, Q);
        }

        return effors[m - 1][n - 1];
    }

    void updateEfforts(int x, int y, int x1, int y1, vector<vector<int>> &effors, vector<vector<int>> &heights, vector<vector<bool>> &isAdded, queue<pair<int, int>> &Q)
    {
        if (x1 < 0 || x1 >= m || y1 < 0 || y1 >= n)
            return;
        int effort = max(effors[x][y], abs(heights[x][y] - heights[x1][y1]));
        if (effort < effors[x1][y1])
        {
            effors[x1][y1] = effort;
            if (!isAdded[x1][y1])
            {
                isAdded[x1][y1] = true;
                Q.push({x1, y1});
            }
        }
    }
};