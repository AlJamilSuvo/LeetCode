#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        return majorityElement(nums, 0, nums.size() - 1);
    }

    int majorityElement(vector<int> &nums, int left, int right)
    {
        if (left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int lM = majorityElement(nums, left, mid);
        int rM = majorityElement(nums, mid + 1, right);
        if (lM == rM)
            return lM;
        int lCnt = getCount(nums, left, right, lM);
        int rCnt = getCount(nums, left, right, rM);

        return lCnt > rCnt ? lM : rM;
    }

    int getCount(vector<int> &nums, int left, int right, int target)
    {
        int cnt = 0;
        for (int i = left; i <= right; i++)
        {
            if (nums[i] == target)
                cnt++;
        }
        return cnt;
    }
};