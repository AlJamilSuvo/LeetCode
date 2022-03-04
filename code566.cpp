#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c)
    {
        int m = mat.size();
        int n = mat[0].size();

        if (m * n != r * c)
            return mat;
        vector<vector<int>> res(r, vector(c, 0));
        int i = 0;
        int j = 0;
        int x = 0;
        int y = 0;
        while (i < m)
        {
            res[x][y] = mat[i][j];
            j++;
            y++;
            if (j == n)
            {
                i++;
                j = 0;
            }

            if (y == c)
            {
                x++;
                y = 0;
            }
        }
        return res;
    }
};