#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1)
            return 1;
        int p_2 = 0;
        int p_1 = 1;
        for (int i = 2; i <= n; i++)
        {
            int p = p_1 + p_2;
            p_2 = p_1;
            p_1 = p;
        }
        return p_1;
    }
};