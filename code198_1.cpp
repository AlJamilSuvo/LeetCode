#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int rob(vector<int> &nums)
    {
        int n_2 = 0;
        int n_1 = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int n = max(n_2 + nums[i], n_1);
            n_2 = n_1;
            n_1 = n;
        }
        return n_1;
    }
};