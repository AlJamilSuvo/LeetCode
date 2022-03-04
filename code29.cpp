#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int divide(int dividend, int divisor)
    {
        int ds1 = dividend < 0 ? -1 : 1;
        int ds2 = divisor < 0 ? -1 : 1;

        int64_t d1 = abs(dividend);
        int64_t d2 = abs(divisor);
        if (d1 < d2)
            return 0;
        if (d1 == d2)
            return 1;

        int64_t res = 0;
        int64_t curRes = 1;

        int64_t currentD = divisor;

        while (d1 >= currentD)
        {
            currentD = currentD + currentD;
            if (d1 > currentD)
            {
                curRes = curRes + curRes;
            }
            if (d1 == currentD)
            {
                res += curRes;
                break;
            }
            else{
                d1 = 
            }

        }
        return res * ds1 * ds2;
    }
};