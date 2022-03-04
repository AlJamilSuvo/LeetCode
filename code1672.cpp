#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumWealth(vector<vector<int>> &accounts)
    {
        int richest = INT_MIN;
        for (int i = 0; i < accounts.size(); i++)
        {
            int amount = 0;
            for (int j = 0; j < accounts[i].size(); j++)
            {
                amount += accounts[i][j];
            }
            richest = max(richest, amount);
        }
        return richest;
    }
};