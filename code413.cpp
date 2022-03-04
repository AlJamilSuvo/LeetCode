#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int lastDiff = INT_MAX;
        int res = 0;
        int conCnt = 0;
        for (int i = 1; i < nums.size(); i++)
        {
            int diff = nums[i] - nums[i - 1];
            if (lastDiff != diff)
            {
                conCnt = 2;
            }
            else
                conCnt += 1;

            if (conCnt >= 3)
                res += (conCnt - 2);

            lastDiff = diff;
        }
        return res;
    }
};