#include <bits/stdc++.h>
using namespace std;

class LimitedMaxHeadp
{

    int capasity;
    int heapSize;
    map<int, int> dpIndexMap;
    vector<int> heap;

public:
    LimitedMaxHeadp(int cap) : capasity(cap), heap(cap)
    {
        heapSize = 0;
    }

    void push(int val, int index)
    {
        heapSize++;
        int i = heapSize - 1;
        
    }
}

class Solution
{
public:
    int maxResult(vector<int> &nums, int k)
    {
        vector<int> dp(nums.size(), 0);
        for (int i = 0; i < nums.size(); i++)
        {
            int m = nums[i];

            if (!q.empty())
                m += q.top();

            if (i - k >= 0)
            {
                q.remove(dp[i - k]);
            }
            q.push(m);

            dp[i] = m;
        }
        return dp[nums.size() - 1];
    }
};