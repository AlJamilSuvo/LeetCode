#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        int currentSum = nums[0];
        while (left < nums.size() || right < nums.size())
        {
            if (currentSum >= target)
            {
                ans = min(ans, right - left + 1);
                currentSum -= nums[left];
                left++;
                if (right < left)
                    right = left;
            }
            else
            {
                right++;
                if (right >= nums.size())
                    break;
                currentSum += nums[right];
            }
        }
        if(ans==INT_MAX) return 0;
        else return ans;
    }
};