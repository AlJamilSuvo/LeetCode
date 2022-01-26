#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        
        if(amount==0) return 1;
        vector<int> dp(amount + 1, 0);
        for (int i = 0; i < coins.size(); i++)
        {
            if (coins[i] <= amount)
                dp[coins[i]] += 1;
            for (int a = coins[i] + 1; a <= amount; a++)
            {
                dp[a] += dp[a - coins[i]];
            }
        }
        return dp[amount];
    }
};