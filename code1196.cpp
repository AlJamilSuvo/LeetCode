#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxNumberOfApples(vector<int> &weight)
    {
        sort(weight.begin(), weight.end());
        int total=0;
        int i = 0;
        for (i = 0; i < weight.size(); i++)
        {
            if (total + weight[i] <= 5000)
                total += weight[i];
            else
                break;
        }
        return i;
    }
};