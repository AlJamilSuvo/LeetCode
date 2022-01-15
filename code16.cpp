#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int threeSumClosest(vector<int> &nums, int target)
    {
        if (nums.size() == 3)
        {
            return nums[0] + nums[1] + nums[2];
        }

        sort(nums.begin(), nums.end());
        int closestSum = 0;
        int minDiff = INT_MAX;
        for (int i = 0; i < nums.size(); i++)
        {
            int twoSum = twoSumClosest(nums, target - nums[i], i);
            int sum = nums[i] + twoSum;
            if (sum == target)
                return sum;
            int diff = abs(target - sum);
            if (diff < minDiff)
            {
                minDiff = diff;
                closestSum = sum;
            }
        }
        return closestSum;
    }

    int twoSumClosest(vector<int> &nums, int newTarget, int skipIndex)
    {
        int left = 0;
        int right = nums.size() - 1;
        int closestSum = 0;
        int minDiff = INT_MAX;
        while (left < right)
        {
            if (left == skipIndex)
            {
                left++;
                continue;
            }
            if (right == skipIndex)
            {
                right--;
                continue;
            }
            int sum = nums[left] + nums[right];
            if (sum == newTarget)
                return sum;
            int diff = abs(newTarget - sum);
            if (diff < minDiff)
            {
                minDiff = diff;
                closestSum = sum;
            }
            if (sum < newTarget)
                left++;
            else
                right--;
        }
        return closestSum;
    }
};