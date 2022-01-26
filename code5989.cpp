#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countElements(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        int mn = nums[0];
        int mx = nums[nums.size() - 1];

        int mn_count = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] > mn)
                break;
            else
                mn_count++;
        }

        int mx_count = 1;
        for (int i = nums.size() - 2; i >= 0; i--)
        {
            if (nums[i] < mx)
                break;
            else
                mx_count++;
        }

        int cnt = nums.size() - mn_count - mx_count;
        cout << mn_count << " " << mx_count << endl;
        if (cnt < 0)
            cnt = 0;


        return cnt;
    }
};

int main()
{

    vector<int> res = {1};
    Solution s;
    cout << s.countElements(res) << endl;
}