#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int64_t skip = 0;
        int64_t added = 0;
        int index = 0;
        while (index < nums.size())
        {
            int prev = INT_MIN;
            int cur = nums[index];
            int next = INT_MAX;
            if (index > 0)
                prev = nums[index - 1];
            int cnt = 0;
            while (index < nums.size() && nums[index] == cur)
            {
                cnt++;
                index++;
            }

            if (index < nums.size())
                next = nums[index];

            int64_t s = skip;
            int64_t a = added;
            if (prev == cur - 1)
            {
                added = s + cnt * cur;
            }
            else
                added = max(s, a) + cnt * cur;

            skip = max(s, a);
        }

        return max(skip, added);
    }
};