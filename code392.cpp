#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(t.length() + 1, false));

        for (int i = 0; i <= t.length(); i++)
        {
            dp[0][i] = true;
        }

        for (int i = 0; i < s.length(); i++)
        {
            for (int j = 0; j < t.length(); j++)
            {
                if (dp[i + 1][j])
                {
                    dp[i + 1][j + 1] = true;
                }
                else if (s[i] == t[j])
                {

                    dp[i + 1][j + 1] = dp[i][j];
                }
            }
        }
        return dp[s.length()][t.length()];
    }
};