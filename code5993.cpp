#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findFinalValue(vector<int> &nums, int original)
    {
        map<int, bool> found;
        for (int i = 0; i < nums.size(); i++)
        {
            found[nums[i]] = true;
        }

        while (found[original])
        {
            original = original * 2;
        }
        return original;
    }
};