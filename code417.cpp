#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class Solution
{
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
    {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> p(m, vector(n, false));
        vector<vector<bool>> a(m, vector(n, false));

        queue<pii> pQ, aQ;

        for (int i = 0; i < m; i++)
        {
            p[i][0] = true;
            pQ.push({i, 0});

            a[i][n - 1] = true;
            aQ.push({i, n - 1});
        }

        for (int i = 0; i < n; i++)
        {
            p[0][i] = true;
            pQ.push({0, i});

            a[m - 1][i] = true;
            aQ.push({m-1, i});
        }

        while (!pQ.empty())
        {
            pii pnt = pQ.front();
            pQ.pop();
            vector<pii> ngbrs = getPoints(pnt, m, n);
            for (auto ngbr : ngbrs)
            {
                if (!p[ngbr.first][ngbr.second] && heights[ngbr.first][ngbr.second] >= heights[pnt.first][pnt.second])
                {
                    p[ngbr.first][ngbr.second] = true;
                    pQ.push(ngbr);
                }
            }
        }

        while (!aQ.empty())
        {
            pii pnt = aQ.front();
            aQ.pop();
            vector<pii> ngbrs = getPoints(pnt, m, n);
            for (auto ngbr : ngbrs)
            {
                if (!a[ngbr.first][ngbr.second] && heights[ngbr.first][ngbr.second] >= heights[pnt.first][pnt.second])
                {
                    a[ngbr.first][ngbr.second] = true;
                    aQ.push(ngbr);
                }
            }
        }

        vector<vector<int>> res;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (p[i][j] && a[i][j])
                {
                    res.push_back({i, j});
                }
            }
        }
        return res;
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