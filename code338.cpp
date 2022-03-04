#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> countBits(int n)
    {
        if (n == 0)
            return {0};
        if (n == 1)
            return {0, 1};
        vector<int> res = {0, 1};
        int prevIndex = 0;
        for (int i = 2; i <= n; i++)
        {

            if ((i & (i - 1)) == 0)
            {
                prevIndex = 0;
            }
            res.push_back(res[prevIndex] + 1);
            prevIndex++;
        }
        return res;
    }
};