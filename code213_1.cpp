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

        vector<int> dp0(nums.size());
        vector<int> dp1(nums.size());

        dp0[0] = nums[0];
        dp1[0] = 0;

        dp0[1] = max(nums[0], nums[1]);
        dp1[1] = nums[1];

        for (int i = 2; i < nums.size(); i++)
        {
            dp0[i] = max(dp0[i - 2] + nums[i], dp0[i - 1]);
            dp1[i] = max(dp1[i - 2] + nums[i], dp1[i - 1]);
        }

        return max(dp0[nums.size() - 2], dp1[nums.size() - 1]);
    }
};