#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }
        int ans1 = kadane(nums, 1);
        int minSum = -kadane(nums, -1);
        int ans2 = totalSum - minSum;
        return max(ans1, ans2);
    }

    int kadane(vector<int> &nums, int sign)
    {
        int best = INT_MIN;
        int current = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            current = max(current, current + nums[i] * sign);
            best = max(current, best);
        }
        return best;
    }
};