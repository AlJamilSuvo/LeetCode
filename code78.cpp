#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        vector<vector<int>> res;
        getPowerSet(nums, res, 0, {});
        return res;
    }

    void getPowerSet(vector<int> &nums, vector<vector<int>> &res, int startIndex, vector<int> presubset)
    {
        res.push_back(presubset);
        if (startIndex >= nums.size())
            return;
        for (int i = startIndex; i < nums.size(); i++)
        {
            presubset.push_back(nums[i]);
            getPowerSet(nums, res, i + 1, presubset);
            presubset.pop_back();
        }
    }
};