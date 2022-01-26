#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int dp[prices.size() + 1][3][2];
        for (int i = 0; i < 3; i++)
        {
            dp[prices.size()][i][0] = 0;
            dp[prices.size()][i][1] = 0;
        }

        for (int i = 0; i < prices.size(); i++)
        {
            dp[i][2][0] = 0;
            dp[i][2][1] = 0;
        }

        for (int day = prices.size() - 1; day >= 0; day--)
        {
            for (int count = 1; count >= 0; count--)
            {
                dp[day][count][0] = max(dp[day + 1][count][1] - prices[day], dp[day + 1][count][0]);
                dp[day][count][1] = max(dp[day + 1][count + 1][0] + prices[day], dp[day + 1][count][1]);
            }
        }
        return dp[0][0][0];
    }
};