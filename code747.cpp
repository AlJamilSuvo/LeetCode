#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        bool found = false;
        int m = 0;
        int index = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] <= m / 2)
                continue;
            else
            {
                if (nums[i] >= m * 2)
                {
                    found = true;
                    index = i;
                }

                else
                    found = false;
                m = max(m, nums[i]);
            }
        }
        if(!found) return -1;
        return index;
    }
};