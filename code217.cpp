#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        unordered_map<int, bool> seenMap;
        for (int i = 0; i < nums.size(); i++)
        {
            if(seenMap[nums[i]]) return true;
            seenMap[nums[i]] = true;
        }
        return false;
    }
};