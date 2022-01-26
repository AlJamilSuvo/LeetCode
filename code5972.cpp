#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArrays(vector<int> &differences, int lower, int upper)
    {
        int64_t num = 0;
        int64_t mx = 0;
        int64_t mn = 0;
        for (int i = 1; i <= differences.size(); i++)
        {
            num = num + differences[i - 1];
            mx = max(mx, num);
            mn = min(mn, num);
        }
        int64_t result = (upper - lower) - (mx - mn) + 1;
        if (result < 0)
            result = 0;
        return result;
    }
};