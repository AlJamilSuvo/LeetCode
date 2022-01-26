#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost)
    {
        int startIndex = 0;
        int current_gas_amount = 0;
        int total_gas_amount = 0;
        for (int i = 0; i < gas.size(); i++)
        {
            if (current_gas_amount < 0)
            {
                startIndex = i;
                current_gas_amount = 0;
            }
            int diff = gas[i] - cost[i];
            current_gas_amount += diff;
            total_gas_amount += diff;
        }
        if (total_gas_amount >= 0)
            return startIndex;
        else
            return -1;
    }
};