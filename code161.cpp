#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isOneEditDistance(string s, string t)
    {
        int m = t.length();
        int n = s.length();
        int dp[m + 1][n + 1];
        for (int i = 0; i < m + 1; i++)
        {
            dp[i][0] = i;
        }

        for (int j = 0; j < n + 1; j++)
        {
            dp[0][j] = j;
        }

        for (int i = 1; i < m + 1; i++)
        {
            for (int j = 1; j < n + 1; j++)
            {
                if (t[i - 1] == s[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        return dp[m][n] == 1;
    }
};