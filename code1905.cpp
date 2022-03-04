#include <bits/stdc++.h>
using namespace std;

#define pii pair<int, int>

class DisjointSet
{
    map<pii, pii> root;
    map<pii, int> rank;

    pii find(pii x)
    {
        if (root[x] == x)
            return x;
        root[x] = find(root[x]);
        return root[x];
    }

public:
    int cnt = 0;
    DisjointSet(const vector<vector<bool>> isSubIceLand)
    {
        for (int i = 0; i < isSubIceLand.size(); i++)
        {
            for (int j = 0; j < isSubIceLand[0].size(); j++)
            {
                if (isSubIceLand[i][j])
                {
                    root[{i, j}] = {i, j};
                    rank[{i, j}] = 0;
                    cnt++;
                    // cout << i << " " << j << " " << cnt << endl;
                }
            }
        }
    }

    void make_union(pii x, pii y)
    {
        pii rX = find(x);
        pii rY = find(y);
        if (rX != rY)
        {
            cnt--;
            if (rank[rX] > rank[rY])
            {
                root[rY] = rX;
            }
            else if (rank[rY] > rank[rX])
            {
                root[rX] = rY;
            }
            else
            {
                root[rY] = rX;
                rank[rX]++;
            }
        }
    }
};

class Solution
{
public:
    int countSubIslands(vector<vector<int>> &grid1, vector<vector<int>> &grid2)
    {
        int m = grid1.size();
        int n = grid1[0].size();
        vector<vector<bool>> isSubIceLand(m, vector(n, false));
        queue<pii> q;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (grid1[i][j] == 1 && grid2[i][j]==1)
                {
                    isSubIceLand[i][j] = true;
                    // cout << i << " " << j << " sub" << endl;
                }
                else if (grid2[i][j] == 1)
                {
                    q.push({i, j});
                    // cout << i << " " << j << " outside" << endl;
                }
            }
        }

        while (!q.empty())
        {
            pii pnt = q.front();
            q.pop();
            vector<pii> ngbrs = getPoints(pnt, m, n);
            for (auto ngbr : ngbrs)
            {
                if (isSubIceLand[ngbr.first][ngbr.second])
                {
                    // cout << pnt.first << " " << pnt.second << " # " << ngbr.first << " " << ngbr.second << " -> false" << endl;
                    isSubIceLand[ngbr.first][ngbr.second] = false;
                    q.push(ngbr);
                }
            }
        }

        DisjointSet ds(isSubIceLand);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isSubIceLand[i][j])
                {
                    vector<pii> ngbrs = getPoints({i, j}, m, n);
                    for (auto ngbr : ngbrs)
                    {
                        if (isSubIceLand[ngbr.first][ngbr.second])
                        {
                            ds.make_union({i, j}, ngbr);
                        }
                    }
                }
            }
        }
        return ds.cnt;
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