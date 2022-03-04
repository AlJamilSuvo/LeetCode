#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> sumOfThree(long long num)
    {
        if (num % 3 == 0)
        {
            long long d = num / 3;
            return {d - 1, d, d + 1};
        }
        else
            return {};
    }
};