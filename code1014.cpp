#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int res = INT_MIN;
        for (int i = 0; i < values.size() - 1; i++)
        {
            for (int j = i + 1; j < values.size(); j++)
            {
                int sc = values[i] + values[j] + i - j;
                res = max(res, sc);
            }
        }
        return res;
    }
};



//time limit 