#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        vector<int64_t> addedNum1, addedNum2;
        for (int i = 0; i < nums1.size(); i++)
        {
            for (int j = 0; j < nums2.size(); j++)
            {
                addedNum1.push_back(nums1[i] + nums2[j]);
                addedNum2.push_back(nums3[i] + nums4[j]);
            }
        }
        sort(addedNum1.begin(), addedNum1.end());
        sort(addedNum2.begin(), addedNum2.end());
        map<int64_t, int> numCnt;
        for (int i = 0; i < addedNum1.size(); i++)
        {
            numCnt[addedNum1[i]] += 1;
        }
        int res = 0;
        for (int i = 0; i < addedNum2.size(); i++)
        {
            res += numCnt[-addedNum2[i]];
        }
        return res;
    }
};