#include <bits/stdc++.h>
using namespace std;

class IntervalCmp
{
public:
    bool operator()(const vector<int> &i1, const vector<int> &i2)
    {
        if (i1[0] == i2[0])
            return i1[1] >= i2[1];
        else
            return i1[0] < i2[0];
    }
};

class Solution
{
public:
    int removeCoveredIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), IntervalCmp());
        vector<bool> isRemoved(intervals.size(), false);
        int removedCnt = 0;
        for (int i = 0; i < intervals.size() - 1; i++)
        {
            if (isRemoved[i])
                continue;

            for (int j = i + 1; j < intervals.size(); j++)
            {
                if (isRemoved[j])
                    continue;

                if (intervals[j][0] >= intervals[i][1])
                    break;

                if (intervals[j][1] <= intervals[i][1])
                {
                    isRemoved[j] = true;
                    removedCnt += 1;
                }
            }
        }
        return intervals.size() - removedCnt;
    }
};