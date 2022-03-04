#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            totalSum += nums[i];
        }
        int leftSum = 0;
        int rightSum = totalSum;
        for (int i = 0; i < nums.size(); i++)
        {
            rightSum -= nums[i];
            if (rightSum == leftSum)
                return i;
            leftSum += nums[i];
        }
        return -1;
    }
};