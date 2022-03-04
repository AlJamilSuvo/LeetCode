#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++)
        {
            dp[n - 1][i] = matrix[n - 1][i];
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j = 0; j < n; j++)
            {
                int m = dp[i + 1][j];
                if (j > 0)
                    m = min(m, dp[i + 1][j - 1]);
                if (j < n - 1)
                    m = min(m, dp[i + 1][j + 1]);
                dp[i][j] = m + matrix[i][j];
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            res = min(dp[0][i], res);
        }
        return res;
    }
};