#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int cnt = 0;
        while (n != 0)
        {
            int check = n & 1;
            if (check)
                cnt++;
            n = n >> 1;
        }
        return cnt;
    }
};