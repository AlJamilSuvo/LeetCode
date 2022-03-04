#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int best = nums[0];
        int current = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            current = max(current + nums[i], nums[i]);
            best = max(best, current);
        }
        return best;
    }
};