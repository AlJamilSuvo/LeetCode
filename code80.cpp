#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.size() == 0)
            return 0;

        int nextInsertPos = 1;
        int lastItem = nums[0];
        int lastItemFreq = 1;

        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] == lastItem)
            {
                lastItemFreq += 1;
                if (lastItemFreq <= 2)
                    nums[nextInsertPos++] = nums[i];
            }
            else
            {
                nums[nextInsertPos++] = nums[i];
                lastItemFreq = 1;
                lastItem = nums[i];
            }
        }
        return nextInsertPos;
    }
};