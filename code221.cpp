#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n];
        for (int i = 0; i < m; i++)
        {
            dp[i][0] = matrix[i][0] == '1';
        }
        for (int i = 0; i < n; i++)
        {
            dp[0][i] = matrix[0][i] == '1';
        }
        for (int i = 1; i < m; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (matrix[i][j] == '0')
                    dp[i][j] = 0;
                else
                {
                    int s = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                    dp[i][j] = s + 1;
                }
            }
        }
        int result = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                result = max(result, dp[i][j]);
            }
        }
        return result * result;
    }
};