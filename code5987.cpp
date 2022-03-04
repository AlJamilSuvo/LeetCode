#include <bits/stdc++.h>
using namespace std;

class Solution
{
    map<pair<int, int>, long long> res;

    map<pair<int, int>, bool> seen;

public:
    long long minimumDifference(vector<int> &nums)
    {
        return getMinimumSum(nums, 0, 0, 0, 0, 0, 0);
    }

    long long getMinimumSum(vector<int> nums, int index, int removeCnt, int firstListCnt, int secondListCnt, int sum1, int sum2)
    {
        if (index >= nums.size())
        {
            return sum1 - sum2;
        }

        // if (!seen[{index, removeCnt}])
        // {

        int n = nums.size();
        int maxPartCnt = n / 3;

        if (removeCnt == maxPartCnt)
        {
            long long r;
            if (firstListCnt >= maxPartCnt)
                r = getMinimumSum(nums, index + 1, removeCnt, firstListCnt, secondListCnt + 1, sum1, sum2 + nums[index]);
            else
                r = getMinimumSum(nums, index + 1, removeCnt, firstListCnt + 1, secondListCnt, sum1 + nums[index], sum2);
            // seen[{index, removeCnt}] = true;
            // res[{index, removeCnt}] = r;
            return r;
        }
        else
        {

            long long r1 = getMinimumSum(nums, index + 1, removeCnt + 1, firstListCnt, secondListCnt, sum1, sum2);
            long long r2 = INT_MAX;

            if (firstListCnt + secondListCnt < 2 * maxPartCnt)
            {

                if (firstListCnt >= maxPartCnt)
                    r2 = getMinimumSum(nums, index + 1, removeCnt, firstListCnt, secondListCnt + 1, sum1, sum2 + nums[index]);
                else
                    r2 = getMinimumSum(nums, index + 1, removeCnt, firstListCnt + 1, secondListCnt, sum1 + nums[index], sum2);
            }

            // seen[{index, removeCnt}] = true;
            // res[{index, removeCnt}] = min(r1, r2);

            return min(r1, r2);
        }
        // }
        // return res[{index, removeCnt}];
    }
};