#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxLength(vector<int> &nums)
    {
        map<int, int> cntMap;
        map<int, int> foundMap;
        int result;
        cntMap[0] = -1;
        foundMap[0] = true;

        int curCnt = 0;
        int maxLen = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            curCnt += nums[i] == 0 ? -1 : 1;
            if (foundMap[curCnt])
            {
                maxLen = max(i - cntMap[curCnt], maxLen);
            }
            else
            {
                cntMap[curCnt] = i;
                foundMap[curCnt] = true;
            }
        }
        return maxLen;
    }
};