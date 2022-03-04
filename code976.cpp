#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<int>());
        int l = 0;
        int m = 1;
        int s = 2;
        while (s < nums.size())
        {
            if ((nums[m] + nums[s]) > nums[l])
            {
                return nums[m] + nums[s] + nums[l];
            }
            l++;
            if (l == m)
                m++;
            if (m == s)
                s++;
        }
        return 0;
    }
};