#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp;
        dp.push_back(0);
        dp.push_back(0);
        for (int i = 2; i <= cost.size(); i++)
        {
            dp.push_back(min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]));
        }
        return dp[cost.size()];
    }
};