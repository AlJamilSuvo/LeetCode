#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int64_t dp[multipliers.size() + 1][multipliers.size() + 1];
        memset(dp, 0, sizeof(dp));

        for (int i = multipliers.size() - 1; i >= 0; i--)
        {
            for (int left = i; left >= 0; left--)
            {
                int right = nums.size() - 1 - i + left;
                int64_t m1 = multipliers[i] * nums[left] + dp[i + 1][left + 1];
                int64_t m2 = multipliers[i] * nums[right] + dp[i + 1][left];
                dp[i][left] = max(m1, m2);
            }
        }
        return dp[0][0];
    }
};
int main()
{
    vector<int> nums = {1, 2, 3}, multipliers = {3, 2, 1};
    Solution s;
    cout << s.maximumScore(nums, multipliers) << endl;
}