#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int n = nums.size() - 1;
        long long sum=0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
        }
        long long originalSum = (n * (n + 1)) / 2;
        return sum - originalSum;
    }
};