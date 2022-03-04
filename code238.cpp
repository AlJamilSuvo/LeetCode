#include <bits/stdc++.h>
using namespace std;





class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int zeroCnt;
        long long product = 1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zeroCnt++;
            else
                product = product * nums[i];
        }

        vector<int> res;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                if (zeroCnt > 1)
                    res.push_back(0);
                else
                    res.push_back(product);
            }
            else
            {
                if (zeroCnt > 0)
                    res.push_back(0);
                else
                    res.push_back(product / nums[i]);
            }
        }
        return res;
    }
};