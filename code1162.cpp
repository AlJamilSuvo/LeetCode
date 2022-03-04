#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    int maxDistance(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector(n, INT_MAX));
        queue<pii> bfsQ;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid[i][j] == 1)
                {
                    distance[i][j] = 0;
                    bfsQ.push({i, j});
                }
            }
        }

        int maxDistance = -1;

        while (!bfsQ.empty())
        {
            pii pnt = bfsQ.front();
            bfsQ.pop();
            int d = distance[pnt.first][pnt.second];
            vector<pii> ngbrs = getPoints(pnt, m, n);
            for (auto ngbr : ngbrs)
            {
                if (grid[ngbr.first][ngbr.second] == 0 && distance[ngbr.first][ngbr.second] > d + 1)
                {
                    distance[ngbr.first][ngbr.second] = d + 1;
                    bfsQ.push(ngbr);
                    maxDistance = max(d + 1, maxDistance);
                }
            }
        }

        return maxDistance;
    }

    vector<pii> getPoints(pii pnt, int m, int n)
    {
        vector<pii> res;

        if (pnt.first > 0)
            res.push_back({pnt.first - 1, pnt.second});
        if (pnt.second > 0)
            res.push_back({pnt.first, pnt.second - 1});

        if (pnt.first < m - 1)
            res.push_back({pnt.first + 1, pnt.second});
        if (pnt.second < n - 1)
            res.push_back({pnt.first, pnt.second + 1});
        return res;
    }
};