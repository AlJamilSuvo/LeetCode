#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isMatch(string s, string p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector(p.size() + 1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p.size(); i++)
            dp[0][i] = false;
        for (int i = 1; i <= s.size(); i++)
            dp[i][0] = false;

        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < p.size(); j++)
            {
                if (s[i] == p[j] || p[i] == '.')
                    dp[i + 1][j + 1] = dp[i][j];
                if (p[i] == '*')
                {
                    dp[i + 1][j + 1] = dp[i][j] || dp[i + 1][j] || dp[i][j + 1];
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};