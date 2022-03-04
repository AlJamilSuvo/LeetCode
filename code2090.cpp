#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> getAverages(vector<int> &nums, int k)
    {
        int64_t sum=0;
        int m = nums.size();
        vector<int> avg(m, -1);
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            if (i - (2 * k + 1) >= 0)
                sum -= nums[i - (2 * k + 1)];
            if (i - (2 * k) >= 0)
            {
                int val = sum / (2 * k + 1);
                avg[i-k] = val;
            }
        }
        return avg;
    }
};