#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minElements(vector<int> &nums, int limit, int goal)
    {
        double sum = 0;
        for (auto num : nums)
            sum += num;
        double diff = abs(goal - sum);
        return ceil(diff / limit);
    }
};