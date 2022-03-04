#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> result;
        int pivotCnt = 0;
        vector<int> endPart;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] < pivot)
                result.push_back(nums[i]);
            else if (nums[i] == pivot)
                pivotCnt++;
            else
                endPart.push_back(nums[i]);
        }

        for (int i = 0; i < pivotCnt; i++)
            result.push_back(pivot);
        for (int i = 0; i < endPart.size(); i++)
        {
            result.push_back(endPart[i]);
        }

        return result;
    }
};