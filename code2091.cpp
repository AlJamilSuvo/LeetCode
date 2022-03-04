#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minimumDeletions(vector<int> &nums)
    {
        int minIndex = 0;
        int maxIndex = 0;
        int minVal = INT_MAX;
        int maxVal = INT_MIN;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < minVal)
            {
                minVal = nums[i];
                minIndex = i;
            }

            if (nums[i] > maxVal)
            {
                maxVal = nums[i];
                maxIndex = i;
            }
        }

        int a = min(minIndex, maxIndex);
        int b = max(minIndex, maxIndex);

        int r1 = a + 1 + nums.size() - b;
        int r2 = b + 1;
        int r3 = nums.size() - a;
        return min(r1, min(r2, r3));
    }
};