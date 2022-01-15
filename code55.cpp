#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int current = 0;
        int target = nums.size() - 1;
        int reached = 0;
        while (true)
        {
            reached = max(current + nums[current], reached);
            if (reached >= target)
                return true;
            current++;
            if (current > reached)
                return false;
        }
        return false;
    }
};