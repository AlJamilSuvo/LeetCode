#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> maxScoreIndices(vector<int> &nums)
    {
        int zeroCount = 0;
        int oneCount = 0;

        vector<int> res;
        int m = -1;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 0)
                zeroCount++;
            if (nums[i] == 1)
                oneCount++;
        }

        int left = 0;
        int right = oneCount;
        for (int i = 0; i <= nums.size(); i++)
        {
            int r = left + right;
            // cout << r <<" "<<m<< endl;
            if (r > m)
            {
                res.clear();
                // cout<<"new result"<<endl;
                res.push_back(i);
                m = r;
            }
            else if (r == m)
            {
                // cout<<"old result"<<endl;
                res.push_back(i);
            }
            if (i == nums.size())
                break;
            if (nums[i] == 0)
                left++;
            if (nums[i] == 1)
                right--;
        }
        return res;
    }
};

int main()
{
    vector<int> r = {0, 0, 1, 0};
    Solution s;
    s.maxScoreIndices(r);
}