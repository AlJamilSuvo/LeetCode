#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> canSeePersonsCount(vector<int> &heights)
    {
        stack<int> stk;
        vector<int> result(heights.size());
        for (int i = heights.size() - 1; i >= 0; i--)
        {
            int cnt = 0;
            stack<int> temp = stk;
            int prev = INT_MIN;
            while (!temp.empty())
            {
                if (min(heights[i], temp.top()) > prev)
                {
                    cnt++;
                    prev = temp.top();
                    temp.pop();
                }
                else
                    break;
            }

            result[i] = cnt;

            while (!stk.empty() && heights[i] > stk.top())
                stk.pop();
            stk.push(heights[i]);
        }
        return result;
    }
};