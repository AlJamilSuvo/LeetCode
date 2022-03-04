#include <bits/stdc++.h>
using namespace std;

class Solution
{
    unordered_map<int, bool> seen;

public:
    bool isHappy(int n)
    {
        if (n == 1)
            return true;
        if (seen[n])
            return false;
        seen[n] = true;

        int nextN = 0;
        while (n > 0)
        {
            int mod = n % 10;
            n = n / 10;
            nextN += mod * mod;
        }
        return isHappy(nextN);
    }
};