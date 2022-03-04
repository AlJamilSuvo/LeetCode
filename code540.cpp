#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int a = INT_MIN;
            int b = INT_MAX;
            if (mid > 0)
                a = nums[mid - 1];
            if (mid != nums.size() - 1)
                b = nums[mid + 1];

            if (a != nums[mid] && b != nums[mid])
                return nums[mid];

            int i1, i2;

            if (a == nums[mid])
            {
                i1 = mid - 1;
                i2 = mid;
            }
            else
            {
                i1 = mid;
                i2 = mid + 1;
            }

            if (i1 % 2 == 1)
            {
                right = i1 - 1;
            }
            else
            {
                left = i2 + 1;
            }
        }

        return 0;
    }
};