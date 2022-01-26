#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int consecutiveNumbersSum(int n)
    {
        double upper_limit = 2 * n;
        upper_limit = upper_limit + .25;
        upper_limit = sqrt(upper_limit) - .5;
        int count = 0;
        for (int i = 1; i <= upper_limit; i++)
        {
            n = n - i;
            if (n % i == 0)
                count += 1;
        }
        return count;
    }
};