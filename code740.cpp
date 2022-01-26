#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> count;
        set<int> nums_set;

        for (auto num : nums)
        {
            nums_set.insert(num);
            count[num]++;
        }
        int last_number = -1;
        int skip = 0;
        int added = 0;
        for (auto num : nums_set)
        {
            int last_best = max(skip, added);
            if (last_number == num - 1)
            {
                added = num * count[num] + last_best;
                skip = last_best;
            }
            else
            {
                added = num * count[num] + skip;
                skip = last_best;
            }
            last_number = num;
        }

        return max(skip,added);
    }

};
