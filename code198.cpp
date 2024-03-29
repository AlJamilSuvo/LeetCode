#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> dp;
        dp.push_back(nums[0]);
        dp.push_back(max(nums[0], nums[1]));
        for (int i = 2; i < nums.size(); i++)
        {
            dp.push_back(max(nums[i] + dp[i - 2], dp[i - 1]));
        }
        return dp[nums.size()-1];
    }
};