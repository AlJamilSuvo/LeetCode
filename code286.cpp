#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void wallsAndGates(vector<vector<int>> &rooms)
    {
        queue<pair<int, int>> bfsQ;
        int m = rooms.size();
        int n = rooms[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (rooms[i][j] == 0)
                    bfsQ.push({i, j});
            }
        }
        while (!bfsQ.empty())
        {
            auto point = bfsQ.front();
            bfsQ.pop();
            int d = rooms[point.first][point.second];

            if (point.first > 0 && rooms[point.first - 1][point.second] != -1 && rooms[point.first - 1][point.second] > d + 1)
            {
                rooms[point.first - 1][point.second] = d + 1;
                bfsQ.push({point.first - 1, point.second});
            }

            if (point.first < m - 1 && rooms[point.first + 1][point.second] != -1 && rooms[point.first + 1][point.second] > d + 1)
            {
                rooms[point.first + 1][point.second] = d + 1;
                bfsQ.push({point.first + 1, point.second});
            }

            if (point.second > 0 && rooms[point.first][point.second - 1] != -1 && rooms[point.first][point.second - 1] > d + 1)
            {
                rooms[point.first][point.second - 1] = d + 1;
                bfsQ.push({point.first, point.second - 1});
            }

            if (point.second < n - 1 && rooms[point.first][point.second + 1] != -1 && rooms[point.first][point.second + 1] > d + 1)
            {
                rooms[point.first][point.second + 1] = d + 1;
                bfsQ.push({point.first, point.second + 1});
            }
        }
    }
};