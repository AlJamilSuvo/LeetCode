#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findLonely(vector<int> &nums)
    {
        vector<int> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            bool isPrevOk = true;
            bool isNextOk = true;

            if (i > 0)
            {
                isPrevOk = nums[i - 1] < nums[i] - 1;
            }

            if (i != nums.size() - 1)
            {
                isNextOk = nums[i + 1] > nums[i] + 1;
            }

            if (isPrevOk && isNextOk)
                res.push_back(nums[i]);
        }

        return res;
    }
};