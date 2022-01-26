#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumCost(vector<int> &cost)
    {
        priority_queue<int> pq;
        for (auto c : cost)
            pq.push(c);
        int cnt = 0;
        int total_cost = 0;
        while (!pq.empty())
        {
            int top = pq.top();
            pq.pop();
            if (cnt == 2)
            {
                cnt = 0;
            }
            else
            {
                total_cost += top;
                cnt += 1;
            }
        }
        return total_cost;
    }
};