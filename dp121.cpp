#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int n = prices.size() - 1;
        int having = prices[n];
        int not_having = 0;
        for (int i = prices.size() - 2; i >= 0; i--)
        {
            int h = having;
            int nh = not_having;
            having = max(h, prices[i]);
            not_having = max(not_having, -prices[i]+h);
        }
        return not_having;
    }
};