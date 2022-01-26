#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maximumScore(vector<int> &nums, vector<int> &multipliers)
    {
        int **dp;
        int m = multipliers.size() + 1;
        dp = new int *[m];
        for (int i = 0; i < m; i++)
            dp[i] = new int[m];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++)
                dp[i][j] = 0;

        return maximumScore(nums, multipliers, 0, 0, dp);
    }
    int maximumScore(vector<int> &nums, vector<int> &multipliers, int i, int left, int **dp)
    {
        if (i >= multipliers.size())
        {
            return 0;
        }
        if (dp[i][left] == 0)
        {
            int right = nums.size() - 1 - i + left;
            int m1 = multipliers[i] * nums[left] + maximumScore(nums, multipliers, i + 1, left + 1, dp);
            int m2 = multipliers[i] * nums[right] + maximumScore(nums, multipliers, i + 1, left, dp);
            dp[i][left] = max(m1, m2);
            cout << i << " " << left << endl;
        }
        return dp[i][left];
    }
};

int main()
{
    vector<int> nums = {1, 2, 3}, multipliers = {3, 2, 1};
    Solution s;
    cout << s.maximumScore(nums, multipliers) << endl;
}