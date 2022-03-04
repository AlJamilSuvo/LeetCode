#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void solve(vector<vector<char>> &board)
    {
        vector<pair<int, int>> zeroPos;
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'O')
                {
                    zeroPos.push_back({i, j});
                }
            }
        }
        map<pair<int, int>, int> found;
        while (true)
        {

            vector<pair<int, int>> visitedPath;
            bool hasEscapePath = false;
            queue<pair<int, int>> bfsQ;
            for (int i = 0; i < zeroPos.size(); i++)
            {
                if (!found[zeroPos[i]])
                {
                    bfsQ.push(zeroPos[i]);
                    found[zeroPos[i]] = true;
                    break;
                }
            }
            if (bfsQ.empty())
                break;

            while (!bfsQ.empty())
            {
                auto cur = bfsQ.front();
                bfsQ.pop();
                visitedPath.push_back(cur);
                if (cur.first == 0)
                    hasEscapePath = true;
                else if (board[cur.first - 1][cur.second] == 'O' && !found[{cur.first - 1, cur.second}])
                {
                    bfsQ.push({cur.first - 1, cur.second});
                    found[{cur.first - 1, cur.second}] = true;
                }

                if (cur.first == m - 1)
                    hasEscapePath = true;
                else if (board[cur.first + 1][cur.second] == 'O' && !found[{cur.first + 1, cur.second}])
                {
                    bfsQ.push({cur.first + 1, cur.second});
                    found[{cur.first + 1, cur.second}] = true;
                }

                if (cur.second == 0)
                    hasEscapePath = true;
                else if (board[cur.first][cur.second - 1] == 'O' && !found[{cur.first, cur.second - 1}])
                {
                    bfsQ.push({cur.first - 1, cur.second});
                    found[{cur.first, cur.second - 1}] = true;
                }

                if (cur.second == n - 1)
                    hasEscapePath = true;
                else if (board[cur.first][cur.second + 1] == 'O' && !found[{cur.first, cur.second + 1}])
                {
                    bfsQ.push({cur.first, cur.second + 1});
                    found[{cur.first, cur.second + 1}] = true;
                }
            }
            if (!hasEscapePath)
            {
                for (auto pos : visitedPath)
                {
                    board[pos.first][pos.second] = 'X';
                }
            }
        }
    }
};