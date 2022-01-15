#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPartitionKSubsets(vector<int> &nums, int k)
    {
        int64_t sum = 0;
        for (auto num : nums)
            sum += num;
        if (sum % k != 0)
            return false;
        sort(nums.begin(), nums.end(), greater<int>());
    }
};