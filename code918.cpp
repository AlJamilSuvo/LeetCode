#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int current = 0;
        int best = INT_MIN;
        int best_start_index = -1;
        int current_index = 0;

        for (int i = 0; i < nums.size() * 2; i++)
        {
            int index = i % nums.size();
            if (index == best_start_index)
                break;
            current = max(current + nums[index], nums[index]);
            best = max(current, best);
            if (best == nums[index])
                best_start_index = index;
        }
        return best;
    }
};