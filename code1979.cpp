#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findGCD(vector<int> &nums)
    {
        int s = INT_MAX;
        int l = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            s = min(s, nums[i]);
            l = max(l, nums[i]);
        }
        int gcd = s;
        while (gcd > 0)
        {
            if (s % gcd == 0 && l % gcd == 0)
                return gcd;
            gcd--;
        }
        return 1;
    }
};