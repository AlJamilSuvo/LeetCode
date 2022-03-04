#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numWays(int n, int k)
    {
        if (n == 1)
            return k;
        if (n == 2)
            return k * k;

        int n_1 = k * k;
        int n_2 = k;

        for (int i = 2; i < n; i++)
        {
            int n = (k - 1) * (n_1 + n_2);
            n_2 = n_1;
            n_1 = n;
        }
        return n_1;
    }
};