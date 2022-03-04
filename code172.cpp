#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int trailingZeroes(int n)
    {
        double fivePower = 5;
        int cnt = 0;
        while (fivePower <= n)
        {
            cnt += floor(n / fivePower);
            fivePower *= 5;
        }
        return cnt;
    }
};