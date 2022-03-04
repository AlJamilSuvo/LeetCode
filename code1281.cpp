#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int subtractProductAndSum(int n)
    {
        int64_t sum = 0;
        int64_t product = 1;
        while (n > 0)
        {
            int mdo = n % 10;
            sum += mdo;
            product *= mdo;
            n = n / 10;
        }
        return product - sum;
    }
};