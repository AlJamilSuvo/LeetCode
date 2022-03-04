#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int curP = nums[0];
        int curN = nums[0];
        int best = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            int oldCurP = curP;
            curP = max(curP * nums[i], max(curN * nums[i], nums[i]));
            curN = min(oldCurP * nums[i], min(curN * nums[i], nums[i]));
            best = max(best, curP);
        }
        return best;
    }
};