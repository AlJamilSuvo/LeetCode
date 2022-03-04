#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> sortEvenOdd(vector<int> &nums)
    {
        vector<int> odd;
        vector<int> even;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        sort(even.begin(), even.end());
        sort(odd.begin(), odd.end(), greater<int>());
        int e = 0;
        int o = 0;

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i % 2 == 0)
            {
                res.push_back(even[e]);
                e++;
            }
            else
            {
                res.push_back(odd[o]);
                o++;
            }
        }
        return res;
    }
};