#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findBuildings(vector<int> &heights)
    {
        int m = INT_MIN;
        stack<int> indexs;
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            if (heights[i] > m)
            {
                indexs.push(i);
                m = heights[i];
            }
        }
        vector<int> res;
        while (!indexs.empty())
        {
            res.push_back(indexs.top());
            indexs.pop();
        }
        return res;
    }
};