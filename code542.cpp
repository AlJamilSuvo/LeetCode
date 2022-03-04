#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> distance(m, vector(n, INT_MAX));
        queue<pii> bfsQ;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (mat[i][j] == 0)
                {
                    distance[i][j] = 0;
                    bfsQ.push({i, j});
                }
            }
        }
        while (!bfsQ.empty())
        {
            pii pnt = bfsQ.front();
            bfsQ.pop();
            auto ngbrs = getNeghbs(pnt, m, n);
            int d = distance[pnt.first][pnt.second];
            for (auto ngbr : ngbrs)
            {
                if (distance[ngbr.first][ngbr.second] > d + 1)
                {
                    distance[ngbr.first][ngbr.second] = d + 1;
                    bfsQ.push(ngbr);
                }
            }
        }

        return distance;
    }

    vector<pii> getNeghbs(pii pnt, int m, int n)
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