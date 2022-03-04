#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        int area = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << i << " " << j << " " << grid[i][j] << " " << visited[i][j] << endl;
                if (grid[i][j] == 1 && !visited[i][j])
                {
                    visited[i][j] = true;
                    int a = 1;
                    queue<pair<int, int>> bfsQ;
                    bfsQ.push({i, j});
                    cout << "found " << i << " " << j << endl;

                    while (!bfsQ.empty())
                    {

                        int x = bfsQ.front().first;
                        int y = bfsQ.front().second;
                        cout << "connected " << x << " " << y << endl;
                        bfsQ.pop();
                        if (x > 0 && grid[x - 1][y] == 1 && !visited[x - 1][y])
                        {
                            visited[x - 1][y] = true;
                            a++;
                            bfsQ.push({x - 1, y});
                        }

                        if (y > 0 && grid[x][y - 1] == 1 && !visited[x][y - 1])
                        {
                            visited[x][y - 1] = true;
                            a++;
                            bfsQ.push({x, y - 1});
                        }

                        if (x + 1 < m && grid[x + 1][y] == 1 && !visited[x + 1][y])
                        {
                            visited[x + 1][y] = true;
                            a++;
                            bfsQ.push({x + 1, y});
                        }

                        if (y + 1 < n && grid[x][y + 1] == 1 && !visited[x][y + 1])
                        {
                            visited[x][y + 1] = true;
                            a++;
                            bfsQ.push({x, y + 1});
                        }
                    }
                    cout << "area = " << a << endl;
                    area = max(area, a);
                }
            }
        }
        return area;
    }
};