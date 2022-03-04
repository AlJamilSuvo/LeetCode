#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countEven(int num)
    {
        int res = 0;

        for (int i = 1; i <= num; i++)
        {
            int sum = 0;
            int n = i;
            while (n > 0)
            {
                int d = n % 10;
                n = n / 10;
                sum += d;
            }

            if (sum % 2 == 0)
                res += 1;
        }

        return res;
    }
};