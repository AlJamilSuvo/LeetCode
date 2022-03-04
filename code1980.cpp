#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        int n = nums[0].length();
        int l = pow(2, n);
        vector<bool> seen(l, false);
        for (int i = 0; i < nums.size(); i++)
        {
            bitset<16> bs(nums[i]);
            int val = bs.to_ulong();
            seen[val] = true;
        }

        for (int i = 0; i < l; i++)
        {
            if (!seen[i])
            {
                bitset<16> bs(i);
                string str = bs.to_string();
                return str.substr(16 - n, n);
            }
        }
        return "";
    }
};