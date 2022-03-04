#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumGap(vector<int> &nums)
    {
        int64_t pos = 1;
        if(nums.size()==1) return 0;
        while (true)
        {
            vector<vector<int>> cnt(10);
            bool found = false;
            for (int i = 0; i < nums.size(); i++)
            {
                int base = nums[i] / pos;
                int index = base % 10;
                if (base > 0)
                    found = true;
                cnt[index].push_back(nums[i]);
            }
            if (!found)
                break;
            pos = pos * 10;

            int i = 0;
            for (int d = 0; d < 10; d++)
            {
                for (int j = 0; j < cnt[d].size(); j++)
                {
                    nums[i++] = cnt[d][j];
                }
            }
        }

        int diff = INT_MIN;
        for (int i = 1; i < nums.size(); i++)
        {
            diff = max(diff, nums[i] - nums[i - 1]);
        }
        return diff;
    }
};