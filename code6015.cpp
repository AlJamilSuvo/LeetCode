#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long coutPairs(vector<int> &nums, int k)
    {
        long long l = nums.size();
        long long n = 0;
        for (int num : nums)
        {
            if (num % k == 0)
                n += 1;
        }

        long long res = (n * (l - n)) + .5 * n * (n - 1);
        return res;
    }
};