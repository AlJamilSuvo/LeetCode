#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeviation(vector<int> &nums)
    {
        priority_queue<int> maxQ;
        priority_queue<int, vector<int>, greater<int>> minQ;
        for (int i = 0; i < nums.size(); i++)
        {
            maxQ.push(nums[i]);
            minQ.push(nums[i]);
        }
        int res = INT_MAX;
        while (true)
        {
            int mx = maxQ.top();
            int mn = minQ.top();
            int diff = mx - mn;
            if (diff == 0 || diff == 1)
                return 0;
            if (mx % 2 == 1)
                return diff;
            else if (mx % 2 == 0)
            {
                maxQ.pop();
                maxQ.push(mx / 2);
                minQ.push(mx / 2);
            }
            else
            {
                minQ.pop();
                minQ.push(mn * 2);
                maxQ.push(mn * 2);
            }
        }
        return 0;
    }
};