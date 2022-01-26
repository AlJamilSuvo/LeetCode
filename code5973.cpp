#include <bits/stdc++.h>
using namespace std;

class Solution
{
    struct result
    {
        int r;
        int c;
        int d;
        int p;
    };

    struct CompareHeight
    {
        bool operator()(result const &p1, result const &p2)
        {
            if (p1.d != p2.d)
                return p1.d > p2.d;

            if (p1.p != p2.p)
                return p1.p > p2.p;

            if (p1.r != p2.r)
                return p1.r > p2.r;

            return p1.c > p2.c;
        }
    };

public:
    vector<vector<int>>
    highestRankedKItems(vector<vector<int>> &grid, vector<int> &pricing, vector<int> &start, int k)
    {
        vector<vector<int>> res;
        map<pair<int, int>, bool> found;
        map<pair<int, int>, int> distance;
        queue<pair<int, int>> q;
        q.push({start[0], start[1]});
        distance[{start[0], start[1]}] = 0;

        priority_queue<struct result, vector<struct result>, CompareHeight> Q;

        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        int r = start[0];
        int c = start[1];
        int d = 0;

        if (grid[r][c] >= pricing[0] && grid[r][c] <= pricing[1])
        {
            struct result o;
            o.c = c;
            o.d = 0;
            o.p = grid[r][c];
            o.r = r;
            Q.push(o);
            cnt++;
        }
        found[{r,c}] = true;

        int max_distance = INT_MAX;

        while (!q.empty())
        {
            auto cp = q.front();
            q.pop();
            d = distance[cp];

            if (d > max_distance)
                break;

            vector<pair<int, int>> adj_list = {{cp.first - 1, cp.second},
                                               {cp.first + 1, cp.second},
                                               {cp.first, cp.second - 1},
                                               {cp.first, cp.second + 1}};

            for (auto adj : adj_list)
            {

                r = adj.first;
                c = adj.second;
                if (r < 0 || r >= m || c < 0 || c >= n)
                    continue;
                if (found[{r, c}])
                    continue;
                if (grid[r][c] == 0)
                    continue;
                if (grid[r][c] >= pricing[0] && grid[r][c] <= pricing[1])
                {
                    struct result o;
                    o.c = c;
                    o.d = d + 1;
                    o.p = grid[r][c];
                    o.r = r;
                    Q.push(o);
                    cnt++;
                }
                found[{r, c}] = true;
                q.push({r, c});
                distance[{r, c}] = d + 1;
            }
            if (cnt >= k)
            {
                max_distance = d;
            }
        }

        while (!Q.empty())
        {
            auto o = Q.top();
            Q.pop();
            res.push_back({o.r, o.c});
            if (res.size() == k)
                break;
        }

        return res;
    }
};