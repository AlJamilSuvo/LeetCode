#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {

        int bestP = INT_MIN;
        int curP = 0;
        int curN = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
            {
                curP = 0;
                curN = 0;
            }
            else if (curP == 0 && curN == 0)
            {
                curP = nums[i] > 0;
                curN = nums[i] < 0;
            }
            else
            {
                if (nums[i] > 0)
                {
                    curP++;
                    if (curN > 0)
                        curN++;
                }
                else
                {
                    int n = curN;
                    int p = curP;

                    curN = p + 1;
                    curP = n > 0 ? n + 1 : 0;
                }
            }
            cout << nums[i] << " " << curN << " " << curP << endl;

            bestP = max(bestP, curP);
        }
        return bestP;
    }
};