#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        if (amount == 0)
            return 0;
        vector<int> dp(amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++)
        {
            dp[i] = -1;
            int mCount = INT_MAX;
            bool found = false;
            for (auto coin : coins)
            {
                if (i == coin)
                {
                    mCount = 1;
                    found = true;
                    break;
                }
                if (coin > i)
                    continue;
                if (dp[i - coin] != -1)
                {
                    found = true;
                    mCount = min(mCount, dp[i - coin] + 1);
                }
            }
            if (found)
                dp[i] = mCount;
            else
                dp[i] = -1;
            // cout << i << " " << dp[i] << endl;
        }
        return dp[amount];
    }
};

int main()
{
    vector<int> conis = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    Solution s;
    cout << s.coinChange(conis, 1013) << endl;
}