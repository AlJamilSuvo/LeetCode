#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int newColor)
    {
        queue<pair<int, int>> bfsQ;
        map<pair<int, int>, bool> visited;
        int oldColor = image[sr][sc];
        image[sr][sc] = newColor;
        bfsQ.push({sr, sc});
        visited[{sr, sc}] = true;
        int m = image.size() - 1;
        int n = image[0].size() - 1;

        while (!bfsQ.empty())
        {
            int x = bfsQ.front().first;
            int y = bfsQ.front().second;
            bfsQ.pop();

            if (x > 0 && image[x - 1][y] == oldColor && !visited[{x - 1, y}])
            {
                image[x - 1][y] = newColor;
                bfsQ.push({x - 1, y});
                visited[{x - 1, y}] = true;
            }
            if (y > 0 && image[x][y - 1] == oldColor && !visited[{x, y - 1}])
            {
                image[x][y - 1] = newColor;
                bfsQ.push({x, y - 1});
                visited[{x, y - 1}] = true;
            }
            if (x < m && image[x + 1][y] == oldColor && !visited[{x + 1, y}])
            {
                image[x + 1][y] = newColor;
                bfsQ.push({x + 1, y});
                visited[{x + 1, y}] = true;
            }
            if (y < n && image[x][y + 1] == oldColor && !visited[{x, y + 1}])
            {
                image[x][y + 1] = newColor;
                bfsQ.push({x, y + 1});
                visited[{x, y + 1}] = true;
            }
        }
        return image;
    }
};