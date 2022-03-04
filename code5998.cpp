#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<long long> maximumEvenSplit(long long finalSum)
    {
        if (finalSum % 2 == 1)
            return {};

        double n = .5 * (-1 + sqrt(1.0 + 4.0 * finalSum));
        long long nf = ceil(n);
        long long sum = 2 * nf + nf * (nf - 1);
        long long cur = 2 + (nf - 1) * 2;

        long long remove = sum - finalSum;
        vector<long long> res;

        long long in = 2;
        while (in <= cur)
        {
            cout << in << endl;
            if (in != remove)
                res.push_back(in);
            in += 2;
        }
        return res;
    }
};