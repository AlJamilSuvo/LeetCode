#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<string> summaryRanges(vector<int> &nums)
    {
        int isContinue = false;
        vector<string> res;
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            bool isNextCnts = false;
            if (i < nums.size() - 1 && nums[i + 1] == (nums[i] + 1))
                isNextCnts = true;
            if (isNextCnts)
            {
                if (!isContinue)
                {
                    isContinue = true;
                    start = nums[i];
                }
            }
            else
            {
                if (isContinue)
                {
                    res.push_back(to_string(start) + "->" + to_string(nums[i]));
                }
                else
                    res.push_back(to_string(nums[i]));
                isContinue = false;
            }
        }
        return res;
    }
};