#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSumAfterPartitioning(vector<int> &arr, int k)
    {
        vector<int> dp(arr.size());
        for (int i = 0; i < arr.size(); i++)
        {
            int m = INT_MIN;
            int h = INT_MIN;
            for (int j = 0; j < k; j++)
            {
                if (i - j < 0)
                    break;
                h = max(arr[i - j], h);
                int prev = 0;
                if (i - j - 1 >= 0)
                    prev = dp[i - j - 1];
                m = max(h * (j + 1) + prev, m);
            }
            dp[i] = m;
        }
        return dp[arr.size() - 1];
    }
};