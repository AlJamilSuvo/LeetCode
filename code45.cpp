#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int64_t> dp(nums.size(), INT_MAX);
        dp[nums.size() - 1] = 0;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            int64_t m = INT_MAX;
            for (int j = 1; j <= nums[i]; j++)
            {

                if (i + j >= nums.size())
                    break;
                m = min(m, dp[i + j] + 1);
            }
            dp[i] = m;
        }
        return dp[0];
    }
};