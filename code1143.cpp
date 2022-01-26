#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1 = text1.size();
        int l2 = text2.size();
        int dp[l1 + 1][l2 + 1];
        for (int i = 0; i <= l1; i++)
            dp[i][0] = 0;
        for (int i = 0; i <= l2; i++)
            dp[0][i] = 0;

        for (int i = 0; i < text1.size(); i++)
        {
            for (int j = 0; j < text2.size(); j++)
            {
                int dMax = max(dp[i - 1][j], dp[i][j - 1]);
                if (text1[i] == text2[j])
                {
                    dp[i][j] = max(dp[i - 1][j - 1] + 1, dMax);
                }
                else
                    dp[i][j] = dMax;
            }
        }
        return dp[l1][l2];
    }
};