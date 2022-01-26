#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> rearrangeArray(vector<int> &nums)
    {
        queue<int> pq;
        queue<int> nq;
        int next_insert = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] >= 0)
                pq.push(nums[i]);
            if (nums[i] < 0)
                nq.push(nums[i]);
            if (!pq.empty() && !nq.empty())
            {
                nums[next_insert++] = pq.front();
                nums[next_insert++] = nq.front();
                pq.pop();
                nq.pop();
            }
        }
        return nums;
    }
};