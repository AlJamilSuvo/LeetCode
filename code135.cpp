#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        vector<int> dp(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; i++)
        {
            if (ratings[i] > ratings[i + 1] && dp[i] <= dp[i + 1])
            {
                dp[i] = dp[i + 1] + 1;
            }
            else if (ratings[i + 1] > ratings[i] && dp[i + 1] <= dp[i])
            {
                dp[i + 1] = dp[i] + 1;
            }
        }

        for (int i = ratings.size() - 1; i > 0; i--)
        {
            if (ratings[i] > ratings[i - 1] && dp[i] <= dp[i - 1])
            {
                dp[i] = dp[i - 1] + 1;
            }
            else if (ratings[i - 1] > ratings[i] && dp[i - 1] <= dp[i])
            {
                dp[i - 1] = dp[i] + 1;
            }
        }
        int res = 0;
        for (int i = 0; i < ratings.size(); i++)
            res += dp[i];
        return res;
    }
};