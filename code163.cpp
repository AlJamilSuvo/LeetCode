#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> findMissingRanges(vector<int> &nums, int lower, int upper)
    {
        vector<string> result;
        for (int i = 0; i <= nums.size(); i++)
        {
            int prev = lower - 1;
            int curr = 0;
            if (i == nums.size())
                curr = upper + 1;
            else
                curr = nums[i];
            if (i != 0)
                prev = nums[i - 1];
            if (curr - prev > 2)
            {
                string res = to_string(prev + 1) + "->" + to_string(curr - 1);
                result.push_back(res);
            }
            else if (curr - prev == 2)
            {
                result.push_back(to_string(curr - 1));
            }
        }
        return result;
    }
};