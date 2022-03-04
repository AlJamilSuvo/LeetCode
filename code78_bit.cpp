#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int l = nums.size();
        int subSetCnt = pow(2, l);
        vector<vector<int>> res;
        for (int i = 0; i < subSetCnt; i++)
        {
            vector<int> arr;
            int bit = i;
            for (int j = 0; j < l; j++)
            {
                if (bit == 0)
                    break;
                int check = bit & 1;
                if (check)
                    arr.push_back(nums[j]);
                bit = bit >> 1;
            }
            res.push_back(arr);
        }
        return res;
    }
};