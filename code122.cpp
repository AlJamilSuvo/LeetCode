#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int dp[prices.size() + 1][2];
        dp[prices.size()][0] = 0;
        dp[prices.size()][1] = 0;

        for (int day = prices.size() - 1; day >= 0; day--)
        {
            dp[day][0] = max(-prices[day] + dp[day + 1][1], dp[day + 1][0]);
            dp[day][1] = max(prices[day] + dp[day + 1][0], dp[day + 1][1]);
        }
        return dp[0][0];
    }
};