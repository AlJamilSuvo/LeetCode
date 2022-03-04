#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        int x = 0;
        int y = 0;
        int m = mat.size();
        int n = mat[0].size();
        bool isUpRight = true;
        vector<int> res;

        if (m == 1 || n == 1)
        {
            for (int i = 0; i < m; i++)
            {
                for (int j = -0; j < n; j++)
                {
                    res.push_back(mat[i][j]);
                }
            }
            return res;
        }

        int cnt = 0;
        while (cnt < m * n)
        {
            res.push_back(mat[x][y]);
            cnt += 1;

            if (x == m - 1 && y == n - 1)
                break;

            if (isUpRight)
            {

                if (x == 0 && y == n - 1)
                {
                    x = 1;
                    y = n - 1;
                    isUpRight = !isUpRight;
                }
                else if (x == 0 && y < n - 1)
                {
                    x = 0;
                    y = y + 1;
                    isUpRight = !isUpRight;
                }
                else if (x < m - 1 && y == n - 1)
                {
                    x = x + 1;
                    y = n - 1;
                    isUpRight = !isUpRight;
                }
                else
                {
                    x = x - 1;
                    y = y + 1;
                }
            }

            else
            {
                if (x == m - 1 && y == 0)
                {
                    x = m - 1;
                    y = 1;
                    isUpRight = !isUpRight;
                }
                else if (x < m - 1 && y == 0)
                {
                    x = x + 1;
                    y = 0;
                    isUpRight = !isUpRight;
                }
                else if (x == m - 1 && y < n - 1)
                {
                    x = m - 1;
                    y = n - 1;
                    isUpRight = !isUpRight;
                }
                else
                {
                    x = x + 1;
                    y = y - 1;
                }
            }
        }
        return res;
    }
};