#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int> &prices)
    {
        int dp[prices.size() + 1][k + 1][2];
        for (int i = 0; i <= k; i++)
        {
            dp[prices.size()][i][0] = 0;
            dp[prices.size()][i][1] = 0;
        }
        for (int i = 0; i < prices.size(); i++)
        {
            dp[i][k][0] = 0;
            dp[i][k][1] = 0;
        }

        for (int day = prices.size() - 1; day >= 0; day--)
        {
            for (int count = k-1; count >= 0; count--)
            {
                dp[day][count][0] = max(dp[day + 1][count][1] - prices[day], dp[day + 1][count][0]);
                dp[day][count][1] = max(prices[day] + dp[day + 1][count + 1][0], dp[day + 1][count][1]);
            }
        }
        return dp[0][0][0];
    }
};
